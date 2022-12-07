#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int n, a, q;
ll dp[300005][2];

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d%d", &n, &q);
		dp[0][0] = 0;
		dp[0][1] = -1e18;
		for (int i = 1; i <= n; ++i) {
			scanf ("%d", &a);
			dp[i][0] = dp[i - 1][0];
			dp[i][1] = dp[i - 1][1];
			dp[i][0] = max(dp[i][0], dp[i - 1][1] - a);
			dp[i][1] = max(dp[i][1], dp[i - 1][0] + a);
		}
		printf ("%lld\n", max(dp[n][0], dp[n][1]));
	}
}