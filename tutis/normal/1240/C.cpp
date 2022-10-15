/*input
2
4 1
1 2 5
3 1 2
3 4 3
7 2
1 2 5
1 3 4
1 4 2
2 5 1
2 6 2
4 7 3

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, k;
vector<pair<ll, ll>>adj[505050];
map<pair<ll, ll>, ll>M;
ll dfs(ll i, ll p, ll w)
{
	if (M.count({i, w}))
		return M[ {i, w}];
	vector<pair<ll, ll>>I;
	for (pair<ll, ll> jw : adj[i])
	{
		ll j = jw.first;
		ll w = jw.second;
		if (j != p)
		{
			I.push_back({w + dfs(j, i, 1), dfs(j, i, 0)});
		}
	}
	sort(I.begin(), I.end(), [&](pair<ll, ll>v1, pair<ll, ll>v2) {
		return v1.first - v1.second > v2.first - v2.second;
	});
	ll id = min(k - w - 1, (ll)I.size() - 1);
	while (id >= 0 && I[id].first - I[id].second <= 0)
		id--;
	ll r = 0;
	for (ll i = 0; i <= id; i++)
		r += I[i].first;
	for (ll i = id + 1; i < I.size(); i++)
		r += I[i].second;
	return M[ {i, w}] = r;
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll q;
	cin >> q;
	while (q--)
	{
		M.clear();
		cin >> n >> k;
		for (ll i = 1; i < n; i++)
		{
			ll u, v, w;
			cin >> u >> v >> w;
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
		}
		cout << dfs(1, 1, 0) << "\n";
		for (ll i = 1; i <= n; i++)
			adj[i].clear();
	}
}