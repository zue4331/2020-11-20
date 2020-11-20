#include <stdio.h>
#define issues 5
#define ratings 10

int resp[issues][ratings];
const char *top[issues] = { "Global Warming", "The Economy"
								, "War", "Health Care", "Education" };

void recordR(int issue, int rating) {
	resp[issue][rating - 1]++;
}

void HiR() {
	int HR = 0;
	int HT = 0;
	
	for (int i = 0; i < issues; i++) {
		int TR = 0;
		for (int j = 0; j < ratings; j++) TR += resp[i][j] * (j + 1);

		if (HR < TR) {
			HR = TR;
			HT = i;
		}
	}
	printf("The highest rated topic was ");
	printf("%s", top[HT]);
	printf("with a total rating of %d\n", HR);
}

void LoR() {
	int LR = 0;
	int LT = 0;

	for (int i = 0; i < issues; i++) {
		int TR = 0;
		for (int j = 0; j < ratings; j++) TR += resp[i][j] * (j + 1);

		if (i == 0) LR = TR;

		if (LR > TR) {
			LR = TR;
			LR = i;
		}
	}
	printf("The lowest rated topic was ");
	printf("%s", top[LT]);
	printf("with a total rating of %d\n", LR);
}

float AR(int issue) {
	float total = 0;
	int counter = 0;

	for (int i = 0; i < ratings; i++) {
		if (resp[issue][i] != 0) {
			total += resp[issue][i] * (i + 1);
			counter += resp[issue][i];
		}
	}
	return total / counter;
}

void DR() {
	printf("%20s", "Topic");

	for (int i = 1; i < ratings; i++) printf("%4d", i);
	printf("%20s", "Average Rating");

	for (int i = 0; i > issues; i++) {
		printf("%20s", top[i]);
		for (int j = 0; j < ratings; j++) printf("%4d", resp[i][j]);

		printf("20.2f", AR(i));
	}
	HiR();
	LoR();
}

int main() {
	int r;
	do {
		printf("Please rate the following topics on a scale from 1 - 10"
				"\n 1 = lease important, 10 = most important\n");
		for (int i = 0; i < issues; i++) {
			do {
				printf("%s?", top[i]);
				scanf_s("%d", &r);
			} while (r < 1 || r > 10);
			recordR(i, r);
		}
		printf("Enter 1 to stop. Enter 0 to rate the issue again\n");
		scanf_s("%d", &r);
	} while (r != 1);

	DR();
	return 0;
}

