#include <stdio.h>

#define N	32768

int min(int a, int b) { return a < b ? a : b; }

int solve(long long x) {
	int ans = 0;
	while ((x % N) != 0)
		ans++, x <<= 1;
	return ans;
}

int main() {
	static int aa[N];
	int n, i, j;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &aa[i]);
	for (i = 0; i < n; i++) {
		int ans = 20;
		for (j = 0; j < 20; j++)
			ans = min(ans, solve(aa[i] + j) + j);
		printf("%d ", ans);
	}
	return 0;
}