/*input
10 12
1 7 1 9 3 3 6 30 1 10
1 2
1 3
3 5
5 7
2 3
5 4
6 9
4 6
3 7
6 8
9 4
9 10
6

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
set<ll>ok;
vector<ll>adj[201010];
ll pa[201010][20];
set<pair<ll, ll>>E;
ll d[201010];
void dfs(ll i, ll p)
{
	d[i] = d[p] + 1;
	pa[i][0] = p;
	for (ll t = 1; t < 20; t++)
		pa[i][t] = pa[pa[i][t - 1]][t - 1];
	E.insert({i, p});
	E.insert({p, i});
	ok.insert(i);
	for (ll j : adj[i])
	{
		if (ok.count(j) == 0)
		{
			dfs(j, i);
		}
	}
}
ll lca(ll a, ll b)
{
	if (a == -1)
		return b;
	if (b == -1)
		return a;
	if (d[a] < d[b])
		swap(a, b);
	for (ll t = 19; t >= 0; t--)
		if (d[pa[a][t]] >= d[b])
			a = pa[a][t];
	for (ll t = 19; t >= 0; t--)
		if (pa[a][t] != pa[b][t])
		{
			a = pa[a][t];
			b = pa[b][t];
		}
	while (a != b)
	{
		a = pa[a][0];
		b = pa[b][0];
	}
	return a;
}
ll r[202020];
ll w[202020];
ll root(ll x)
{
	if (x != r[x])
		r[x] = root(r[x]);
	return r[x];
}
void merge(ll a, ll b)
{
	a = root(a);
	b = root(b);
	if (d[a] > d[b])
		swap(a, b);
	if (a != b)
	{
		r[b] = a;
		w[a] += w[b];
		w[b] = 0;
	}
}
int main()
{
	iota(r, r + 202020, 0);
	ios_base::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;
	for (ll i = 1; i <= n; i++)
		cin >> w[i];
	ll u[m], v[m];
	for (ll i = 0; i < m; i++)
	{
		cin >> u[i] >> v[i];
		adj[u[i]].push_back(v[i]);
		adj[v[i]].push_back(u[i]);
	}
	ll s;
	cin >> s;
	dfs(s, s);
	for (ll i = 0; i < m; i++)
	{
		if (E.count({u[i], v[i]}) == 0)
		{
			for (ll x : {u[i], v[i]})
			{
				while (root(x) != s)
				{
					x = root(x);
					merge(x, pa[x][0]);
				}
			}
		}
	}
	vector<ll>ans(n + 1, -1ll);
	ans[s] = w[s];
	queue<ll>Q;
	Q.push(s);
	set<ll>buvo = {s};
	for (ll i = 0; i <= n; i++)
		adj[i].clear();
	for (auto i : E)
	{
		adj[root(i.first)].push_back(root(i.second));
		adj[root(i.second)].push_back(root(i.first));
	}
	while (!Q.empty())
	{
		ll i = Q.front();
		Q.pop();
		for (ll j : adj[i])
		{
			if (buvo.count(j))
				continue;
			ans[j] = ans[i] + w[j];
			buvo.insert(j);
			Q.push(j);
		}
	}
	cout << *max_element(ans.begin(), ans.end()) << "\n";
}