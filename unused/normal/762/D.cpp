#include <bits/stdc++.h>
using namespace std;

long long dp[100005][3];
int dat[100005][3];

int main()
{
	int n;
	scanf("%d", &n);
	for (int j = 0; j < 3; j++) for (int i = 1; i <= n; i++) scanf("%d", &dat[i][j]);

	dp[0][0] = 0; dp[0][1] = dp[0][2] = -1e18;
	dp[1][0] = dat[1][0]; dp[1][1] = dp[1][0] + dat[1][1]; dp[1][2] = dp[1][1] + dat[1][2];

	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = max({
			dp[i - 1][0],
			dp[i - 1][1] + dat[i][1],
			dp[i - 1][2] + dat[i][1] + dat[i][2],
			dp[i - 2][2] + dat[i-1][2] + dat[i][2] + dat[i-1][1] + dat[i][1] + dat[i-1][0]
		}) + dat[i][0];

		dp[i][2] = max({
			dp[i - 1][2],
			dp[i - 1][1] + dat[i][1],
			dp[i - 1][0] + dat[i][1] + dat[i][0],
			dp[i - 2][0] + dat[i - 1][0] + dat[i][0] + dat[i - 1][1] + dat[i][1] + dat[i - 1][2]
		}) + dat[i][2];

		dp[i][1] = max({
			dp[i-1][0] + dat[i][0],
			dp[i-1][1],
			dp[i-1][2] + dat[i][2]
		}) + dat[i][1];
	}

	printf("%lld\n", dp[n][2]);
}