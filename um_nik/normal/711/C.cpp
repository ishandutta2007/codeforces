#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;


typedef long long ll;
const ll INF = (ll)1e17;
const int N = 102;
ll dp[N][N][N];
int n, m, k;
int a[N];
ll b[N][N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%lld", &b[i][j]);
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			for (int h = 0; h <= m; h++)
				dp[i][j][h] = INF;
	if (a[0] == 0)
	{
		for (int c = 1; c <= m; c++)
			dp[1][1][c] = b[0][c];
	}
	else
		dp[1][1][a[0]] = 0;
	for (int i = 1; i < n; i++)
		for (int g = 1; g <= min(i, k); g++)
			for (int lc = 1; lc <= m; lc++)
			{
				if (dp[i][g][lc] == INF) continue;
				if (a[i] == 0)
				{
					for (int c = 1; c <= m; c++)
						dp[i + 1][g + (int)(lc != c)][c] = min(dp[i + 1][g + (int)(lc != c)][c], dp[i][g][lc] + b[i][c]);
				}
				else
				{
					dp[i + 1][g + (int)(lc != a[i])][a[i]] = min(dp[i + 1][g + (int)(lc != a[i])][a[i]], dp[i][g][lc]);
				}
			}
	ll ans = INF;
	for (int c = 1; c <= m; c++)
		ans = min(ans, dp[n][k][c]);
	if (ans == INF)
		printf("-1\n");
	else
		printf("%lld\n", ans);

	return 0;
}