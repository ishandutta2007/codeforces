/*input
3 3
1 1
1 1
1 3

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll modulo = 1000000007;
ll K[3][2502][52];
ll G[52][52][52][3];
ll F[52];
int32_t main()
{
	F[0] = 1;
	for (ll i = 1; i <= 51; i++)
	{
		F[i] = (i * F[i - 1]) % modulo;
	}
	ll n, T;
	cin >> n >> T;
	ll t[n], g[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> t[i] >> g[i];
		g[i]--;
	}
	G[1][0][0][0] = 1;
	G[0][1][0][1] = 1;
	G[0][0][1][2] = 1;
	for (ll a = 0; a <= 50; a++)
	{
		for (ll b = 0; b <= 50; b++)
		{
			for (ll c = 0; c <= 50; c++)
			{
				for (ll d = 0; d < 3; d++)
				{
					G[a][b][c][d] %= modulo;
					for (ll e = 0; e < 3; e++)
					{
						if (d != e)
							G[a + (e == 0)][b + (e == 1)][c + (e == 2)][e] += G[a][b][c][d];
					}
					G[a][b][c][d] *= F[a];
					G[a][b][c][d] %= modulo;
					G[a][b][c][d] *= F[b];
					G[a][b][c][d] %= modulo;
					G[a][b][c][d] *= F[c];
					G[a][b][c][d] %= modulo;
				}
			}
		}
	}
	for (ll t : {0, 1, 2})
	{
		K[t][0][0] = 1;
	}
	for (ll i = 0; i < n; i++)
	{
		for (ll k = 50; k >= 1; k--)
		{
			for (ll tt = T; tt >= t[i]; tt--)
			{
				K[g[i]][tt][k] += K[g[i]][tt - t[i]][k - 1];
				K[g[i]][tt][k] %= modulo;
			}
		}
	}
	ll ans = 0;
	for (ll k0 = 0; k0 <= n; k0++)
	{
		for (ll k1 = 0; k0 + k1 <= n; k1++)
		{
			for (ll k2 = 0; k0 + k1 + k2 <= n; k2++)
			{
				for (ll t0 = 0; t0 <= T; t0++)
				{
					for (ll t1 = 0; t0 + t1 <= T; t1++)
					{
						ll t2 = T - t0 - t1;
						ll x = 1;
						x *= G[k0][k1][k2][0] + G[k0][k1][k2][1] + G[k0][k1][k2][2];
						x %= modulo;
						x *= K[0][t0][k0];
						x %= modulo;
						x *= K[1][t1][k1];
						x %= modulo;
						x *= K[2][t2][k2];
						x %= modulo;
						ans += x;
						ans %= modulo;
					}
				}
			}
		}
	}
	cout << ans << "\n";
}