/*input
3 3 3 100
1 1 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll dp[2][500 + 1][500 + 1];
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, m, b, mod;
	cin >> n >> m >> b >> mod;
	for (int a = 0; a < 2; a++)
	{
		for (int c = 0; c <= m; c++)
		{
			for (int d = 0; d <= b; d++)
			{
				dp[a][c][d] = 0;
			}
		}
	}
	for (int a = 0; a <= b; a++)
		dp[0][0][a] = 1;
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		for (int c = 0; c <= m; c++)
		{
			for (int d = 0; d <= b; d++)
			{
				dp[i % 2][c][d] = 0;
				dp[i % 2][c][d] += dp[(i - 1) % 2][c][d];
				if (d - a >= 0 && c > 0)
					dp[i % 2][c][d] += dp[i % 2][c - 1][d - a];
				dp[i % 2][c][d] %= mod;
			}
		}
	}
	cout << dp[n % 2][m][b] << "\n";
}