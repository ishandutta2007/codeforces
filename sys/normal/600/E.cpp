#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, ct, maxi, cnt[Maxn], col[Maxn], siz[Maxn], son[Maxn], head[Maxn];
long long tot, ans[Maxn];
struct edg
{
	int nxt, to;
} edge[2 * Maxn];
void add(int x, int y)
{
	edge[++ct] = (edg){head[x], y};
	head[x] = ct;
}
void dfs1(int u, int fa)
{
	siz[u] = 1;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
		{
			dfs1(to, u);
			siz[u] += siz[to];
			if (siz[to] > siz[son[u]]) son[u] = to;
		}
	}
}
void get_ans(int u, int fa, int hson)
{
	cnt[col[u]]++;
	if (cnt[col[u]] > maxi) maxi = cnt[col[u]], tot = 0;
	if (cnt[col[u]] == maxi) tot += col[u];
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa && to != hson)
			get_ans(to, u, hson);
	}
}
void clear(int u, int fa)
{
	cnt[col[u]]--;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
			clear(to, u);
	}
}
void dfs2(int u, int fa)
{
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa && to != son[u])
		{
			dfs2(to, u);
			clear(to, u);
			maxi = 0;
		}
	}
	if (son[u]) dfs2(son[u], u);
	get_ans(u, fa, son[u]);
	ans[u] = tot;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &col[i]);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	for (int i = 1; i <= n; i++)
		printf("%lld ", ans[i]);
	return 0;
}