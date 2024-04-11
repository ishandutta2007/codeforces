#include <stdio.h>

#define N   25

long long abs_(long long x) { return x < 0 ? -x : x; }
long long min(long long a, long long b) { return a < b ? a : b; }

int main() {
	int t;

	scanf("%d", &t);
	while (t--) {
		int n, i, j, x, aa[N], bb[N];
		long long dp[N][2];

		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", &aa[i]);
		for (i = 0; i < n; i++)
			scanf("%d", &bb[i]);
		dp[0][0] = dp[0][1] = 0;
		for (i = 1; i < n; i++)
			for (j = 0; j < 2; j++) {
				dp[i][j] = min(dp[i - 1][0] + abs_(aa[i] - aa[i - 1]) + abs_(bb[i] - bb[i - 1]), dp[i - 1][1] + abs_(aa[i] - bb[i - 1]) + abs_(bb[i] - aa[i - 1]));
				x = bb[i], bb[i] = aa[i], aa[i] = x;
			}
		printf("%lld\n", min(dp[n - 1][0], dp[n - 1][1]));
	}

	return 0;
}