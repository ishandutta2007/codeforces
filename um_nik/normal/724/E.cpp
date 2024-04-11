#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = (int)1e4 + 20;
const ll INF = (ll)1e18 + 3;
int n;
ll a[N], b[N];
ll c;
ll dp[2][N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld", &n, &c);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%lld", &b[i]);
	for (int i = 0; i <= n; i++)
		dp[0][i] = INF;
	dp[0][0] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= n; j++)
			dp[1][j] = INF;
		for (int j = 0; j <= i; j++)
		{
			dp[1][j + 1] = min(dp[1][j + 1], dp[0][j] + b[i]);
			dp[1][j] = min(dp[1][j], dp[0][j] + a[i] + c * j);
		}
		for (int j = 0; j <= n; j++)
			dp[0][j] = dp[1][j];
	}
	ll ans = INF;
	for (int i = 0; i <= n; i++)
		ans = min(ans, dp[0][i]);
	printf("%lld\n", ans);

	return 0;
}