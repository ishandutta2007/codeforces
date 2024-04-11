/*input
5 4
1 2
2 3
2 4
4 5
2 1
2 5
1 2
2 5
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int>adj[101010];
int pa[101010][30];
int d[101010];
void dfs(int i, int p)
{
	d[i] = d[p] + 1;
	pa[i][0] = p;
	for (int t = 1; t < 30; t++)
		pa[i][t] = pa[pa[i][t - 1]][t - 1];
	for (int j : adj[i])
	{
		if (j == p)
			continue;
		dfs(j, i);
	}
}
int lca(int u, int v)
{
	if (d[u] < d[v])
		swap(u, v);
	for (int t = 29; t >= 0; t--)
		if (d[pa[u][t]] >= d[v])
			u = pa[u][t];
	while (d[u] > d[v])
		u = pa[u][0];
	for (int t = 29; t >= 0; t--)
		if (pa[u][t] != pa[v][t])
			u = pa[u][t], v = pa[v][t];
	while (u != v)
	{
		u = pa[u][0];
		v = pa[v][0];
	}
	return u;
}
int CenP[101010];
void centroid(int i, int sz, int pa)
{
	pair<int, int> gers = {sz + 1, i};
	function<int(int, int)>DFS;
	DFS = [&](int x, int p)->int
	{
		int ret = 1;
		int mxs = 0;
		for (int j : adj[x])
		{
			if (j == p)
				continue;
			int s = DFS(j, x);
			mxs = max(mxs, s);
			ret += s;
		}
		mxs = max(mxs, sz - ret);
		gers = min(gers, {mxs, x});
		return ret;
	};
	assert(sz == DFS(i, i));
	int x = gers.second;
	if (pa == -1)
		pa = x;
	CenP[x] = pa;
	vector<int>k = adj[x];
	for (int i : k)
		adj[i].erase(find(adj[i].begin(), adj[i].end(), x));
	adj[x].clear();
	for (int i : k)
		centroid(i, DFS(i, x), x);
}
int dist(int a, int b)
{
	return d[a] + d[b] - 2 * d[lca(a, b)];
}
pair<int, int>artimiausia[101010];
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	d[1] = 0;
	dfs(1, 1);
	centroid(1, n, -1);
	for (int i = 1; i <= n; i++)
	{
		artimiausia[i] = {dist(i, 1), 1};
	}
	while (m--)
	{
		int t, v;
		cin >> t >> v;
		if (t == 1)
		{
			int u = v;
			while (true)
			{
				artimiausia[u] = min(artimiausia[u], {dist(u, v), v});
				if (u == CenP[u])
					break;
				u = CenP[u];
			};
		}
		else
		{
			int ans = n + 2;
			int u = v;
			while (true)
			{
				int x = artimiausia[u].second;
				ans = min(ans, dist(v, x));
				if (u == CenP[u])
					break;
				u = CenP[u];
			};
			cout << ans << "\n";
		}
	}
}