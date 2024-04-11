#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 200005;
int n, d[Maxn], h[Maxn], l[Maxn], ans[Maxn];
vector <int> V, G[Maxn], D[Maxn];
vector <pair <int, int> > Op;
queue <int> Qu;
bool vis[Maxn], used[Maxn];
void dfs1(int u, int fa)
{
	h[u] = l[u] ? 0 : 0x3f3f3f3f;
	for (auto v : G[u])
		if (v != fa)
		{
			dfs1(v, u);
			Op.push_back(make_pair(u, v));
			h[u] = min(h[u], h[v] + 1);
		}
}
void dfs2(int u, int fa)
{
	for (auto v : G[u])
		if (v != fa)
		{
			Op.push_back(make_pair(v, u));
			h[v] = min(h[v], h[u] + 1);
			dfs2(v, u);
		}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &l[i]);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y), G[y].push_back(x);
	}
	dfs1(1, 0), dfs2(1, 0);
	for (int u = 1; u <= n; u++)
		for (auto v : G[u])
			if (h[u] == h[v]) used[u] = used[v] = true, V.push_back(h[u]);
	for (int i = 1; i <= n; i++) ans[i] = h[i];
	sort(V.begin(), V.end(), greater <int> ());
	V.resize(unique(V.begin(), V.end()) - V.begin());
	for (auto val : V)
	{
		memset(d, -0x3f, sizeof(int[n + 1]));
		for (int i = 1; i <= n; i++)
			if (h[i] == val && used[i]) d[i] = 0;
		for (auto [u, v] : Op)
			if (h[u] >= h[v]) d[u] = max(d[u], min(d[v], 0) + (h[u] == h[v] ? -1 : 1));
		for (int i = 1; i <= n; i++)
			if (d[i] >= 0) ans[i] = min(ans[i], val);
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", 2 * h[i] - ans[i]);
	return 0;
}