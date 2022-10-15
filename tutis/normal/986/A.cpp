/*input
7 6 3 2
1 2 3 3 2 2 1
1 2
2 3
3 4
2 5
5 6
6 7
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, m, k, s;
	cin >> n >> m >> k >> s;
	ll a[n + 1];
	vector<ll>aa[k + 1];
	vector<ll>adj[n + 1];
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i];
		aa[a[i]].push_back(i);
	}
	while (m--)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	ll D[n + 1][k + 1];
	for (ll i = 0; i <= n; i++)
	{
		for (ll j = 0; j <= k; j++)
		{
			D[i][j] = ll(1e12);
		}
	}
	for (ll t = 1; t <= k; t++)
	{
		queue<ll>Q;
		for (ll i : aa[t])
		{
			Q.push(i);
			D[i][t] = 0;
		}
		while (!Q.empty())
		{
			ll a = Q.front();
			Q.pop();
			for (ll b : adj[a])
			{
				if (D[b][t] > D[a][t] + 1)
				{
					D[b][t] = D[a][t] + 1;
					Q.push(b);
				}
			}
		}
	}
	for (ll i = 1; i <= n; i++)
	{
		ll ans = 0;
		sort(D[i] + 1, D[i] + (k + 1));
		for (ll t = 1; t <= s; t++)
			ans += D[i][t];
		cout << ans << " ";
	}
	cout << "\n";


}