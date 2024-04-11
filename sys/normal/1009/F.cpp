#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;
int n, ct, cnt, ans[Maxn], top[Maxn], fa[Maxn], dep[Maxn], head[Maxn], son[Maxn], pool[Maxn];
int * f[Maxn]; 
struct edg
{
	int nxt, to;
} edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void dfs1(int u, int f)
{
	fa[u] = f;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != f)
		{
			dfs1(to, u);
			dep[u] = max(dep[u], dep[to] + 1);
			if (dep[to] > dep[son[u]]) son[u] = to;
		}
	}
}
void get_ans(int x, int y)
{
	if (f[x][ans[x]] < f[x][y] || (f[x][ans[x]] == f[x][y] && ans[x] > y)) ans[x] = y;
}
void dfs2(int u, int tp)
{
	top[u] = tp;
	if (son[u])
	{
		f[son[u]] = f[u] + 1;
		dfs2(son[u], tp);
		ans[u] = ans[son[u]] + 1;
	}
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != son[u] && to != fa[u])
		{
			f[to] = &pool[ct];
			ct += dep[to] + 1;
			dfs2(to, to);
			for (int j = 1; j <= dep[to] + 1; j++)
			{
				f[u][j] += f[to][j - 1];
				get_ans(u, j);
			}
		}
	}
	f[u][0] = 1;
	get_ans(u, 0);
}
int main()
{
	dep[0] = -1;
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}
	dfs1(1, 0);
	f[1] = &pool[ct];
	ct += dep[1] + 1;
	dfs2(1, 1);
	for (int i = 1; i <= n; i++)
		printf("%d\n", ans[i]);
	return 0;
}