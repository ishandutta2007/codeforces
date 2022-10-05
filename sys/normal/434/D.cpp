#include <bits/stdc++.h>
using namespace std;

const int Maxn = 50005;
int n, m, s, t, ct, cnt, l[Maxn], r[Maxn], cur[Maxn], head[Maxn], dis[Maxn], id[55][205], a[55], b[55], c[55];
long long ans;
int f(int u, int x)
{
	return a[u] * x * x + b[u] * x + c[u];
}
struct edg
{
	int nxt, to;
	long long w;
} edge[20 * Maxn];
void add(int x, int y, long long w)
{
	if (!x || !y) return ;
	edge[++cnt] = (edg){head[x], y, w};
	head[x] = cnt;
	edge[++cnt] = (edg){head[y], x, 0};
	head[y] = cnt;
}
queue <int> Qu;
bool bfs(void)
{
	memset(dis, 0, sizeof(int[ct + 1]));
	Qu.push(s);
	while (!Qu.empty())
	{
		int u = Qu.front();
		Qu.pop();
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			if (!dis[to] && to != s && edge[i].w)
				dis[to] = dis[u] + 1, Qu.push(to);
		}
	}
	return dis[t];
}
long long dfs(int u, long long mini)
{
	if (u == t || !mini) return mini;
	long long w, used = 0;
	for (int & i = cur[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (dis[to] == dis[u] + 1 && edge[i].w)
		{
			w = dfs(to, min(mini - used, (long long) edge[i].w));
			used += w, edge[i].w -= w, edge[((i - 1) ^ 1) + 1].w += w;
		}
	}
	return used;
}
void dinic(void)
{
	while (bfs())
	{
		memcpy(cur, head, sizeof(int[ct + 1]));
		ans -= dfs(s, 0x3f3f3f3f3f3f3f3fLL);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	s = ++ct, t = ++ct;
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &l[i], &r[i]);
		for (int j = l[i]; j <= r[i] + 1; j++)
			id[i][j + 100] = ++ct;
		add(s, id[i][l[i] + 100], 0x3f3f3f3f3f3f3f3fLL), add(id[i][r[i] + 101], t, 0x3f3f3f3f3f3f3f3fLL);
		for (int j = l[i]; j <= r[i]; j++)
			add(id[i][j + 100], id[i][j + 101], 0x3f3f3f3f - f(i, j));
	}
	while (m--)
	{
		int u, v, d;
		scanf("%d%d%d", &u, &v, &d);
		for (int j = max(0, d); j <= min(201, 201 + d); j++)
			add(id[u][j], id[v][j - d], 0x3f3f3f3f3f3f3f3fLL);
	}
	ans = n * 0x3f3f3f3fLL;
	dinic();
	printf("%lld", ans);
	return 0;
}