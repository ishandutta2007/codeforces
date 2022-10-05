#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;
int a[Maxn], b[Maxn], n, T;
long long dp[Maxn][3];
int main()
{
//	freopen("D.in", "r", stdin);
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d%d", &a[i], &b[i]);
		for(int i = 1; i <= n; i++)
			dp[i][0] = dp[i][1] = dp[i][2] = 1e18 + 1;
		a[0] = -0x3f3f3f3f;
		for(int i = 1; i <= n; i++)
		{
			if(a[i] + 1 != a[i - 1])
			{
				dp[i][1] = min(dp[i][1], dp[i - 1][0]);
				dp[i][2] = min(dp[i][2], dp[i - 1][1]);
			}
			if(a[i] != a[i - 1])
			{
				dp[i][1] = min(dp[i][1], dp[i - 1][1]);
				dp[i][0] = min(dp[i][0], dp[i - 1][0]);
				dp[i][2] = min(dp[i][2], dp[i - 1][2]);
			}
			if(a[i] != a[i - 1] + 1)
			{
				dp[i][0] = min(dp[i][0], dp[i - 1][1]);
				dp[i][1] = min(dp[i][1], dp[i - 1][2]);
			}
			if(a[i] != a[i - 1] + 2)
				dp[i][0] = min(dp[i][0], dp[i - 1][2]);
			if(a[i] + 2 != a[i - 1])
				dp[i][2] = min(dp[i][2], dp[i - 1][0]);
			dp[i][1] += b[i];
			dp[i][2] += 2 * b[i];
		}
		printf("%lld\n", min(dp[n][2], min(dp[n][0], dp[n][1])));
	}
	return 0;
}