/*input
6
1 2 6
1 3 8
1 4 12
2 5 2
2 6 4

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<pair<ll, ll>>adj[1010];
vector<pair<ll, pair<ll, ll>>>ans;
ll vaikas(ll i, ll p)
{
	for (auto j : adj[i])
	{
		if (j.first == p)
			continue;
		return vaikas(j.first, i);
	}
	return i;
}
void atimk(ll i, ll p, ll x)
{
	for (auto &j : adj[p])
	{
		if (j.first == i)
		{
			j.second -= x;
		}
	}
	for (auto &j : adj[i])
	{
		if (j.first == p)
		{
			j.second -= x;
		}
	}
	for (auto &j : adj[i])
	{
		if (j.first != p)
			return atimk(j.first, i, x);
	}
	return;
}
void tvarkyk(ll i)
{
	if (adj[i].size() < 3)
		return;
	for (ll t = 0; t < (ll)adj[i].size(); t++)
	{
		ll a = vaikas(adj[i][t].first, i);
		ll b = vaikas(adj[i][(t + 1) % (adj[i].size())].first, i);
		ll c = vaikas(adj[i][(t + 2) % (adj[i].size())].first, i);
		ll x = adj[i][t].second;
		if (x == 0)
			continue;
		ans.push_back({x / 2, {a, c}});
		ans.push_back({x / 2, {a, b}});
		ans.push_back({ -x / 2, {b, c}});
		atimk(adj[i][t].first, i, x);
	}
}
void dfs(ll i, ll p)
{
	vector<pair<ll, ll>>child;
	for (auto j : adj[i])
	{
		if (j.first == p)
			continue;
		child.push_back(j);
	}
	tvarkyk(i);
	for (auto j : child)
		dfs(j.first, i);
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	for (ll i = 1; i < n; i++)
	{
		ll u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	for (ll i = 1; i <= n; i++)
	{
		if (adj[i].size() == 2)
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	if (n == 2)
	{
		ans.push_back({adj[1][0].second, {1, 2}});
	}
	else
	{
		ll x = 1;
		while (adj[x].size() == 1)
			x++;
		dfs(x, x);
	}
	cout << ans.size() << "\n";
	for (auto i : ans)
		cout << i.second.first << " " << i.second.second << " " << i.first << "\n";
}