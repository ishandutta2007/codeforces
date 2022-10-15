/*input
5 5
1 2 1
2 3 1
3 4 1
4 5 1
2 4 1
15
1 1
2 2
3 3
4 4
5 5
1 2
2 3
3 4
4 5
1 3
2 4
3 5
1 4
2 5
1 5
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct DSU
{
	vector<ll>pa;
	DSU(ll n = 1)
	{
		pa = vector<ll>(n + 3, -1);
	}
	ll root(ll i)
	{
		if (pa[i] < 0)
			return i;
		return pa[i] = root(pa[i]);
	}
	ll size(ll i)
	{
		return -pa[root(i)];
	}
	ll merge(ll a, ll b)
	{
		a = root(a);
		b = root(b);
		if (a == b)
			return 0;
		if (pa[a] < pa[b])
			swap(a, b);
		pa[b] += pa[a];
		pa[a] = b;
		return 1;
	}
};
int main()
{
	srand(time(NULL));
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll n, m;
	cin >> n >> m;
	vector<ll>idomu;
	DSU X(n + 1);
	vector<pair<ll, ll>>adj[n + 1];
	vector<pair<ll, ll>>med[n + 1];
	while (m--)
	{
		ll u, v, d;
		cin >> u >> v >> d;
		adj[u].push_back({v, d});
		adj[v].push_back({u, d});
		if (X.root(u) != X.root(v))
		{
			med[u].push_back({v, d});
			med[v].push_back({u, d});
		}
		else
		{
			idomu.push_back(u);
			idomu.push_back(v);
		}
		X.merge(u, v);
	}/*
	for (int a = 0; a < 120; a++)
	{
		idomu.push_back((rand() % n) + 1);
	}*/
	ll d[n + 1];
	ll DD[n + 1];
	ll pa[n + 1][25];
	function<void(ll, ll)>dfs = [&](ll i, ll p)->void
	{
		pa[i][0] = p;
		for (ll t = 1; t < 25; t++)
		{
			pa[i][t] = pa[pa[i][t - 1]][t - 1];
		}
		for (pair<ll, ll>j : med[i])
		{
			if (j.first == p)
				continue;
			DD[j.first] = DD[i] + 1;
			d[j.first] = d[i] + j.second;
			dfs(j.first, i);
		}
	};
	DD[1] = 0;
	d[1] = 0;
	dfs(1, 1);
	function<ll(ll, ll)>lca = [&](ll x, ll y)->ll
	{
		if (DD[x] < DD[y])
			swap(x, y);
		for (ll t = 24; t >= 0; t--)
		{
			if (DD[pa[x][t]] >= DD[y])
				x = pa[x][t];
		}
		for (ll t = 24; t >= 0; t--)
			if (pa[x][t] != pa[y][t])
			{
				x = pa[x][t];
				y = pa[y][t];
			}
		while (x != y)
		{
			x = pa[x][0];
			y = pa[y][0];
		}
		return x;
	};
	auto dist = [&](ll u, ll v)->ll
	{
		return d[u] + d[v] - 2 * d[lca(u, v)];
	};
	ll q;
	cin >> q;
	ll D[idomu.size()][n + 1];
	for (ll t = 0; t < idomu.size(); t++)
	{
		ll i = idomu[t];
		for (ll j = 1; j <= n; j++)
		{
			D[t][j] = 3e16;
		}
		D[t][i] = 0;
		priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>Q;
		Q.push({D[t][i], i});
		while (!Q.empty())
		{
			ll x = Q.top().second;
			Q.pop();
			for (pair<ll, ll>y : adj[x])
			{
				if (D[t][y.first] > D[t][x] + y.second)
				{
					D[t][y.first] = D[t][x] + y.second;
					Q.push({D[t][y.first], y.first});
				}
			}
		}
	}
	while (q--)
	{
		ll u, v;
		cin >> u >> v;
		ll ans = dist(u, v);
		for (ll t = 0; t < idomu.size(); t++)
		{
			ans = min(ans, D[t][u] + D[t][v]);
		}
		cout << ans << "\n";
	}
}