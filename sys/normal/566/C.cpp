#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, cnt, tot, root, w[Maxn], siz[Maxn], maxi[Maxn], head[Maxn];
double now, sum, d[Maxn];
bool vis[Maxn];
pair <int, double> ans;
struct edg
{
	int nxt, to, w;
} edge[2 * Maxn];
void add(int x, int y, int w)
{
	edge[++cnt] = (edg){head[x], y, w};
	head[x] = cnt;
}
void get_root(int u, int fa)
{
	siz[u] = maxi[u] = 1;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa && !vis[to])
		{
			get_root(to, u);
			siz[u] += siz[to];
			maxi[u] = max(maxi[u], siz[to]);
		}
	}
	maxi[u] = max(maxi[u], tot - siz[u]);
	if (maxi[u] < maxi[root]) root = u;
}
void dfs(int u, int fa, int rt, int dis)
{
	now += dis * sqrt(dis) * w[u], d[rt] += sqrt(dis) * 1.5 * w[u];
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa) dfs(to, u, rt, dis + edge[i].w);
	}
}
void divide(int u)
{
	now = sum = 0;
	vis[u] = true;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		d[to] = 0, dfs(to, u, to, edge[i].w), sum += d[to];
	}
	if (now < ans.second) ans = make_pair(u, now);
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (!vis[to] && sum - 2 * d[to] < 0)
		{
			get_root(to, u), root = 0, tot = siz[to], get_root(to, u);
			divide(root);
		}
	}
}
int main()
{
	ans.second = 1e50;
	maxi[0] = 0x3f3f3f3f;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &w[i]);
	for (int i = 1; i < n; i++)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		add(x, y, w), add(y, x, w);
	}
	tot = n, get_root(1, 0);
	divide(root);
	printf("%d %.10lf", ans.first, ans.second);
	return 0;
}