#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll MOD = (ll)1e9 + 7;
ll add(ll x, ll y)
{
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y)
{
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
ll mult(ll x, ll y)
{
	return (x * y) % MOD;
}

const int N = 210;
const int C = 1010;
int n, k;
int a[N];
ll dp[2][N][C];

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	dp[0][0][0] = 1;
	for (int p = 0; p < n; p++)
	{
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= k; j++)
				dp[1][i][j] = 0;
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= k; j++)
			{
				if (dp[0][i][j] == 0) continue;
				int T = a[p] - (p == 0 ? 0 : a[p - 1]);
				int nj = j + i * T;
				if (nj > k) continue;
				dp[1][i][nj] = add(dp[1][i][nj], dp[0][i][j]);
				dp[1][i + 1][nj] = add(dp[1][i + 1][nj], dp[0][i][j]);
				dp[1][i][nj] = add(dp[1][i][nj], mult(dp[0][i][j], i));
				if (i > 0)
					dp[1][i - 1][nj] = add(dp[1][i - 1][nj], mult(dp[0][i][j], i));
			}
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= k; j++)
				dp[0][i][j] = dp[1][i][j];
	}
	ll ans = 0;
	for (int i = 0; i <= k; i++)
		ans = add(ans, dp[0][0][i]);
	printf("%lld\n", ans);

	return 0;
}