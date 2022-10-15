#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

long long a[5010];
long long dp[5010][5010];
long long q[5010], h, t;

int main()
{
	int n, m, x; scanf("%d%d%d", &n, &m, &x);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	memset(dp, -0x3f, sizeof(dp)); dp[0][0] = 0;
	for(int j = 1; j <= x; j++)
	{
		h = 0; t = -1;
		q[++t] = 0;
		for(int i = 1; i <= n; i++)
		{
			while(h <= t && q[h] < i - m) h++;
			dp[i][j] = dp[q[h]][j - 1] + a[i];
			while(h <= t && dp[q[t]][j - 1] < dp[i][j - 1]) t--;
			q[++t] = i;
		}
	}
	long long ans = -1e18;
	for(int i = n - m + 1; i <= n; i++) ans = std::max(ans, dp[i][x]);
	if(ans >= 0) printf("%lld\n", ans);
	else puts("-1");
	return 0;
}