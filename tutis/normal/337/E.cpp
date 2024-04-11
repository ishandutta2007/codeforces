/*input
4
10000000000 10000000001 10000000002 10000000003
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll alpha[100][2000];
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll n;
	cin >> n;
	ll a[n + 1];
	set<ll>ps;
	for (ll i = 1; i <= n; i++)
		cin >> a[i];
	a[0] = -1000;
	sort(a + 1, a + n + 1, greater<ll>());
	for (ll i = 1; i <= n; i++)
	{
		ll y = a[i];
		for (ll x = 2; x * x <= a[i]; x++)
		{
			while (y % x == 0)
			{
				y /= x;
				ps.insert(x);
			}
		}
		if (y > 1)
		{
			ps.insert(y);
		}
	}
	vector<ll>pp;
	for (ll i : ps)
		pp.push_back(i);
	ll k = pp.size();
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 0; j < k; j++)
		{
			ll y = a[i];
			alpha[i][j] = 0;
			while (y % pp[j] == 0)
			{
				y /= pp[j];
				alpha[i][j]++;
			}
		}
	}
	ll ans = 100000000000000000;
	ll pa[9];
	pa[0] = 0;
	for (pa[1] = 0; pa[1] < 1; pa[1]++)
	{
		for (pa[2] = 0; pa[2] < 2; pa[2]++)
		{
			for (pa[3] = 0; pa[3] < 3; pa[3]++)
			{
				for (pa[4] = 0; pa[4] < 4; pa[4]++)
				{
					for (pa[5] = 0; pa[5] < 5; pa[5]++)
					{
						for (pa[6] = 0; pa[6] < 6; pa[6]++)
						{
							for (pa[7] = 0; pa[7] < 7; pa[7]++)
							{
								for (pa[8] = 0; pa[8] < 8; pa[8]++)
								{
									vector<ll>adj[n + 1];
									for (ll i = 1; i <= n; i++)
										adj[pa[i]].push_back(i);
									bool ok = true;
									ll nulis = 0;
									for (ll i = 1; i <= n; i++)
									{
										ll y = a[i];
										for (ll j : adj[i])
										{
											if (y % a[j] == 0)
												y /= a[j];
											else
											{
												ok = false;
											}
										}
									}
									for (ll i = 2; i <= n; i++)
										if (pa[i] == 0)
											nulis = 1;
									if (ok)
									{
										ll gal = nulis + n;
										for (ll i = 1; i <= n; i++)
										{
											ll kiekis = 0;
											ll suma[k];
											fill_n(suma, k, 0);
											for (ll c = 0; c < k; c++)
											{
												kiekis += alpha[i][c];
											}
											if (kiekis == 1)
												continue;
											gal += kiekis;
											for (ll j : adj[i])
											{
												for (ll c = 0; c < k; c++)
												{
													gal -= alpha[j][c];
												}
											}
											for (ll c = 0; c < k; c++)
												gal += suma[c];
										}
										ans = min(ans, gal);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << ans << "\n";
}