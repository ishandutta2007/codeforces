#include<cstdio>

int main() {
	int h1, h2, a, b;
	scanf("%d%d%d%d", &h1, &h2, &a, &b);
	// day 0 2pm - 10pm
	h1 += a * 8;
	if (h1 >= h2) {
		printf("0\n");
	} else {
		// looping between -12b + 12a
		if (a <= b) {
			printf("-1\n");
		} else {
			int deltad = (h2 - h1), deltav = 12 * (a - b),
				ans = (deltad + deltav - 1) / deltav;
			printf("%d\n", ans);
		}
	}
	return 0;
}