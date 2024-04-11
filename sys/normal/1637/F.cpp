#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, h[Maxn], maxi[Maxn], maxi2[Maxn];
long long sum, ans = 0x3f3f3f3f3f3f3f3fLL;
pair <int, int> all, son[Maxn];
vector <int> G[Maxn];
void dfs1(int u, int fa)
{
	if (h[u] > h[all.first]) all = make_pair(u, all.second);
	else if (h[u] > h[all.second]) all.second = u;
	for (auto v : G[u])
		if (v != fa)
		{
			dfs1(v, u);
			maxi[u] = max(maxi[u], max(h[v], maxi[v]));
			if (max(h[v], maxi[v]) > son[u].first) son[u] = make_pair(max(h[v], maxi[v]), son[u].first);
			else son[u].second = max(son[u].second, max(h[v], maxi[v]));
		}
	sum += max(0, h[u] - maxi[u]);
}
void dfs2(int u, int fa)
{
	for (auto v : G[u])
		if (v != fa)
		{
			maxi2[v] = max(max(maxi2[u], h[fa]), son[u].first == max(h[v], maxi[v]) ? son[u].second : son[u].first);
			dfs2(v, u);
		}
}
void dfs3(int u, int fa, int tmp)
{
	tmp = max(tmp, maxi[u]);
	ans = min(ans, sum + h[all.first]);
	for (auto v : G[u])
		if (v != fa)
		{
			sum -= max(0, h[v] - maxi[v]);
			sum -= max(0, h[u] - (all.first == u ? h[all.second] : h[all.first]));
			sum += max(0, h[u] - maxi2[v]);
			sum += max(0, h[v] - (all.first == v ? h[all.second] : h[all.first]));
			dfs3(v, u, tmp);
			sum += max(0, h[v] - maxi[v]);
			sum += max(0, h[u] - (all.first == u ? h[all.second] : h[all.first]));
			sum -= max(0, h[u] - maxi2[v]);
			sum -= max(0, h[v] - (all.first == v ? h[all.second] : h[all.first]));
		}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &h[i]);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y), G[y].push_back(x);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	dfs3(1, 0, 0);
	printf("%lld", ans);
	return 0;
}