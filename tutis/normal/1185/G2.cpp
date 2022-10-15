/*input
3 3
1 1
1 1
1 3

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int modulo = 1000000007;
ll K[3][2502][27];
ll G[27][27][27][3];
ll Gs[27][27][27];
ll F[27];
int kkk[3];
int32_t main()
{
	ios_base::sync_with_stdio(false);
	F[0] = 1;
	for (int i = 1; i <= 25; i++)
	{
		F[i] = (i * F[i - 1]) % modulo;
	}
	G[1][0][0][0] = 1;
	G[0][1][0][1] = 1;
	G[0][0][1][2] = 1;
	for (int a = 0; a <= 25; a++)
	{
		for (int b = 0; b <= 25; b++)
		{
			for (int c = 0; c <= 25; c++)
			{
				for (int d = 0; d < 3; d++)
				{
					G[a][b][c][d] %= modulo;
					for (int e = 0; e < 3; e++)
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
					Gs[a][b][c] += G[a][b][c][d];
					Gs[a][b][c] %= modulo;
				}
			}
		}
	}
	int n, T;
	cin >> n >> T;
	vector<int>ts[3];
	for (int i = 0; i < n; i++)
	{
		int t, g;
		cin >> t >> g;
		g--;
		kkk[g]++;
		ts[g].push_back(t);
	}
	for (int t : {0, 1, 2})
	{
		K[t][0][0] = 1;
	}
	for (int c = 0; c < 3; c++)
	{
		for (int t : ts[c])
		{
			for (int k = 25; k >= 1; k--)
			{
				for (int tt = t; tt <= T; tt++)
				{
					K[c][tt][k] += K[c][tt - t][k - 1];
					K[c][tt][k] %= modulo;
				}
			}
		}
	}
	ll ans = 0;
	for (int k0 = 0; k0 <= min(kkk[0], (n + 1) / 2); k0++)
	{
		for (int t0 = 0; t0 <= T; t0++)
		{
			if (K[0][t0][k0] == 0)
				continue;
			for (int k1 = 0; k1 <= min(kkk[1], (n + 1) / 2); k1++)
			{
				for (int t1 = 0; t0 + t1 <= T; t1++)
				{
					if (K[1][t1][k1] == 0)
						continue;
					for (int k2 = 0; k2 <= min(kkk[2], (n + 1) / 2); k2++)
					{
						int t2 = T - t0 - t1;
						ll x = Gs[k0][k1][k2];
						if (x == 0)
							continue;
						x *= K[0][t0][k0];
						x %= modulo;
						x *= K[1][t1][k1];
						x %= modulo;
						x *= K[2][t2][k2];
						x %= modulo;
						ans += x;
					}
				}
			}
		}
	}
	ans %= modulo;
	cout << ans << "\n";
}