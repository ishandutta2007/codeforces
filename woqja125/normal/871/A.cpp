#include<stdio.h>
#include<vector>
int c[] = { 4, 6, 8, 9, 10,
			12, 14, 15, 16, 18,
			20, 21, 22, 24, 25,
			26, 27, 28, 30, 32,
			33, 34, 35, 36, 38,
			39, 40 };
std::vector<int> p;
int dp[10010];
int main() {
	int M = 10000, N = 27;
	dp[0] = 0;
	for (int i = 1; i <= M; i++) {
		dp[i] = -1;
		for (int j = 0; j < N; j++) {
			if (i - c[j] >= 0 && dp[i - c[j]] != -1) 
				if (dp[i] < dp[i - c[j]] + 1) dp[i] = dp[i - c[j]] + 1;
		}
	}
	int q, n;
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		scanf("%d", &n);
		int ans = -1, c = n / 4;
		for (int i = n % 4; i <= M && i <= n; i += 4, c--) {
			if (dp[i] != -1 && ans < dp[i] + c) ans = dp[i] + c;
		}
		printf("%d\n", ans);
	}
	return 0;
}