/*input
2
2 3
2 5 7
4 2 4
3 6
4 1 5 2 10 4
8 6 6 4 9 10
5 4 9 5 8 7
*/
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll t;
	cin >> t;
	while (t--)
	{
		ll n, m;
		cin >> n >> m;
		ll a[n][m];
		for (ll i = 0; i < n; i++)
		{
			for (ll j = 0; j < m; j++)
				cin >> a[i][j];
		}
		ll dp[1 << n][m + 1];
		for (ll msk = 0; msk < (1 << n); msk++)
		{
			for (ll j = 0; j <= m; j++)
			{
				dp[msk][j] = 0;
			}
		}
		for (ll j = m - 1; j >= 0; j--)
		{
			vector<ll>x[n];
			for (ll i = 0; i < n; i++)
				x[0].push_back(a[i][j]);
			for (ll i = 1; i < n; i++)
			{
				x[i] = x[i - 1];
				ll a = x[i].back();
				x[i].pop_back();
				x[i].insert(x[i].begin(), a);
			}
			ll rez[1 << n];
			for (ll msk = 0; msk < (1 << n); msk++)
			{
				rez[msk] = 0;
				for (ll c = 0; c < n; c++)
				{
					ll suma = 0;
					for (ll i = 0; i < n; i++)
					{
						if ((msk & (1 << i)) != 0)
							suma += x[c][i];
					}
					rez[msk] = max(rez[msk], suma);
				}
			}
			for (ll msk = 0; msk < (1 << n); msk++)
				for (ll x = msk;; x = ((x - 1) & msk))
				{
					dp[msk][j] = max(dp[msk][j], rez[x] + dp[x ^ msk][j + 1]);
					if (x == 0)
						break;
				}
		}
		cout << dp[(1 << n) - 1][0] << "\n";
	}
}