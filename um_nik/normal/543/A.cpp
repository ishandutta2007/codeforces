#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;

int MOD;
const int N = 505;
int a[N];
int n, m, b;
int dp[2][N][N];

void read()
{
	scanf("%d%d%d%d", &n, &m, &b, &MOD);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	return;
}

int sum(int x, int y)
{
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}

void solve()
{
	dp[0][0][0] = 1 % MOD;
	for (int i = 0; i < n + m; i++)
	{
		for (int p = 0; p < n; p++)
			for (int x = 0; x <= b; x++)
			{
				dp[1][p + 1][x] = sum(dp[1][p + 1][x], dp[0][p][x]);
				int y = x + a[p];
				if (y > b) continue;
				dp[1][p][y] = sum(dp[1][p][y], dp[0][p][x]);
			}
		for (int p = 0; p <= n; p++)
			for (int x = 0; x <= b; x++)
			{
				dp[0][p][x] = dp[1][p][x];
				dp[1][p][x] = 0;
			}
	}
	int ans = 0;
	for (int x = 0; x <= b; x++)
		ans = sum(ans, dp[0][n][x]);
	cout << ans << endl;
}

int main()
{
	read();
	solve();

	return 0;
}