#include <bits/stdc++.h>
using namespace std;

int n, K, pos, val, diff, nums;

int main() {
	scanf("%d%d", &n, &K);
	printf("? ");
	for (int i = 1; i <= K; ++ i) printf("%d ", i);
	printf("\n");
	fflush(stdout);
	scanf("%d%d", &pos, &val);
	diff = nums = 0;
	for (int i = 1; i <= K; ++ i) {
		if (i == pos) continue;
		printf("? ");
		for (int j = 1; j <= K; ++ j) {
			if (j == i) continue;
			printf("%d ", j);
		}
		printf("%d\n", K + 1);
		fflush(stdout);
		int a, b; scanf("%d%d", &a, &b);
		if (a != pos) {
			diff = b;
			++ nums;
		}
	}
	if (nums == 0) {
		printf("? ");
		for (int i = 1; i <= K; ++ i) {
			if (i == pos) continue;
			printf("%d ", i);
		}
		printf("%d\n", K + 1);
		fflush(stdout);
		int a, b; scanf("%d%d", &a, &b);
		if (b < val) printf("! %d\n", K);
		else printf("! %d\n", 1); 
	} else {
		if (diff < val) printf("! %d\n", K - nums);
		else printf("! %d\n", nums + 1);
	}
	fflush(stdout);
	return 0;
}