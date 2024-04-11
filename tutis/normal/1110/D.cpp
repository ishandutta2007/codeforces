/*input
13 5
1 1 5 1 2 3 3 2 4 2 3 4 5

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll A[(ll)1e6 + 500];
ll dp[2][9][9];
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;
	while (n--)
	{
		int a;
		cin >> a;
		A[a]++;
	}
	n = m + 5;
	ll ans = 0;
	for (ll i = 0; i < n; i++)
	{
		while (A[i] >= 9)
		{
			A[i] -= 3;
			ans++;
		}
	}
	for (ll i = 0; i < 2; i++)
	{
		for (ll a = 0; a <= 8; a++)
		{
			for (ll b = 0; b <= 8; b++)
			{
				dp[i][a][b] = -1e18;
			}
		}
	}
	dp[1][A[0]][A[1]] = ans;
	for (ll k = 1; k < n; k++)
	{
		for (ll a = 0; a <= A[k - 1]; a++)
		{
			for (ll b = 0; b <= A[k]; b++)
			{
				for (ll c = 1; c * 3 <= a; c++)
				{
					dp[k % 2][a - 3 * c][b] = max(dp[k % 2][a - 3 * c][b], dp[k % 2][a][b] + c);
				}
				for (ll c = 1; c * 3 <= b; c++)
				{
					dp[k % 2][a][b - 3 * c] = max(dp[k % 2][a][b - 3 * c], dp[k % 2][a][b] + c);
				}
			}
		}
		for (ll a = 0; a <= A[k - 1]; a++)
		{
			for (ll b = 0; b <= A[k]; b++)
			{
				for (ll kk = 0; kk <= min({a, b, A[k + 1]}); kk++)
				{
					dp[(k + 1) % 2][b - kk][A[k + 1] - kk] =
					    max(dp[(k + 1) % 2][b - kk][A[k + 1] - kk],
					        dp[k % 2][a][b] + kk);
				}
			}
		}
		for (ll a = 0; a <= A[k - 1]; a++)
		{
			for (ll b = 0; b <= A[k]; b++)
			{
				dp[k % 2][a][b] = -1e18;
			}
		}
	}
	cout << dp[n % 2][0][0] << "\n";
}