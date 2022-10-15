/*input
3 3
1 2
1 3
2 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll modulo = 1000 * 1000 * 1000 + 7;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n, m;
	cin >> n >> m;
	vector<ll>adj[n + 1];
	for (ll i = 1; i < n; i++)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	ll k, x;
	ll ans[n + 1][11][3];
	function<void(ll, ll)>dfs = [&](ll i, ll p)->void
	{
		auto it = find(adj[i].begin(), adj[i].end(), p);
		if (it != adj[i].end())
			adj[i].erase(it);
		for (ll j : adj[i])
			dfs(j, i);
		for (ll a = 0; a <= 10; a++)
		{
			for (ll t = 0; t < 3; t++)
			{
				ans[i][a][t] = 0;
			}
		}
		{
			ans[i][0][0] = k - 1;
			for (ll j : adj[i])
			{
				ll dp[10];
				for (ll a_b = 10; a_b >= 0; a_b--)
				{
					ll suma = 0;
					for (ll a = a_b; a >= 0; a--)
					{
						suma += ans[i][a][0] *
						(ans[j][a_b - a][0] + ans[j][a_b - a][1] + ans[j][a_b - a][2]);
						suma %= modulo;
					}
					ans[i][a_b][0] = suma;
				}
			}
		}
		{
			ans[i][1][1] = 1;
			for (ll j : adj[i])
			{
				for (ll a_b = 10; a_b >= 0; a_b--)
				{
					ll suma = 0;
					for (ll a = a_b; a >= 0; a--)
					{
						suma += ans[i][a][1] *
						(ans[j][a_b - a][0]);
						suma %= modulo;
					}
					ans[i][a_b][1] = suma;
				}
			}
		}
		{
			ans[i][0][2] = m - k;
			for (ll j : adj[i])
			{
				for (ll a_b = 10; a_b >= 0; a_b--)
				{
					ll suma = 0;
					for (ll a = a_b; a >= 0; a--)
					{
						suma += ans[i][a][2] *
						(ans[j][a_b - a][0] + ans[j][a_b - a][2]);
						suma %= modulo;
					}
					ans[i][a_b][2] = suma;
				}
			}
		}
		for (ll a = 0; a <= 10; a++)
		{
			for (ll t = 0; t < 3; t++)
			{
				ans[i][a][t] %= modulo;
			}
		}
	};
	cin >> k >> x;
	dfs(1, 1);
	ll ats = 0;
	for (ll i = 0; i <= x; i++)
		ats += ans[1][i][0] + ans[1][i][1] + ans[1][i][2];
	ats %= modulo;
	cout << ats << "\n";
}