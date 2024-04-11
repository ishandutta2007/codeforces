#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, q, cnt, head[Maxn];
int ct1, root1, ans1[Maxn], rk1[Maxn], pos1[Maxn], top1[Maxn], dis1[Maxn], maxdis1[Maxn], son1[Maxn], w1[Maxn], val1[Maxn], anc1[Maxn][20], mini1[Maxn][20];
int ct2, root2, ans2[Maxn], rk2[Maxn], pos2[Maxn], top2[Maxn], dis2[Maxn], maxdis2[Maxn], son2[Maxn], w2[Maxn], val2[Maxn], anc2[Maxn][20], mini2[Maxn][20];
struct edg
{
	int nxt, to, w;
} edge[2 * Maxn];
void add(int x, int y, int w)
{
	edge[++cnt] = (edg){head[x], y, w};
	head[x] = cnt;
}
void dfs1(int u, int fa)
{
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
			dis1[to] = dis1[u] + edge[i].w, dfs1(to, u);
	}
}
void dfs21(int u, int fa)
{
	anc1[u][0] = fa;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
		{
			maxdis1[to] = dis1[to] = dis1[u] + edge[i].w, dfs21(to, u);
			maxdis1[u] = max(maxdis1[u], maxdis1[to]);
			if (maxdis1[son1[u]] < maxdis1[to]) son1[u] = to, w1[u] = edge[i].w;
		}
	}
}
void dfs22(int u, int fa)
{
	anc2[u][0] = fa;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
		{
			maxdis2[to] = dis2[to] = dis2[u] + edge[i].w, dfs22(to, u);
			maxdis2[u] = max(maxdis2[u], maxdis2[to]);
			if (maxdis2[son2[u]] < maxdis2[to]) son2[u] = to, w2[u] = edge[i].w;
		}
	}
}
void dfs31(int u, int tp)
{
	top1[u] = tp;
	if (son1[u])
	{
		val1[tp] += w1[u];
		dfs31(son1[u], tp);
	}
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != anc1[u][0] && to != son1[u]) val1[to] = edge[i].w, dfs31(to, to);
	}
}
void dfs32(int u, int tp)
{
	top2[u] = tp;
	if (son2[u])
	{
		val2[tp] += w2[u];
		dfs32(son2[u], tp);
	}
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != anc2[u][0] && to != son2[u]) val2[to] = edge[i].w, dfs32(to, to);
	}
}
void init(void)
{
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i <= n; i++)
		{
			anc1[i][j] = anc1[anc1[i][j - 1]][j - 1];
			mini1[i][j] = min(mini1[i][j - 1], mini1[anc1[i][j - 1]][j - 1]);
			anc2[i][j] = anc2[anc2[i][j - 1]][j - 1];
			mini2[i][j] = min(mini2[i][j - 1], mini2[anc2[i][j - 1]][j - 1]);
		}
}
int work1(int x, int y)
{
	for (int i = 19; i >= 0; i--)
		if (mini1[x][i] > y) x = anc1[x][i];
	return x;
}
int work2(int x, int y)
{
	for (int i = 19; i >= 0; i--)
		if (mini2[x][i] > y) x = anc2[x][i];
	return x;
}
void work1(void)
{
	for (int i = 1; i <= n; i++)
		if (val1[i]) pos1[++ct1] = i;
	sort(pos1 + 1, pos1 + 1 + ct1, [](int x, int y){return val1[x] > val1[y];});
	for (int i = 1; i <= ct1; i++) rk1[pos1[i]] = i;
	for (int i = 1; i <= ct1; i++)
		ans1[i] = ans1[i - 1] + val1[pos1[i]];
	for (int i = 1; i <= n; i++)
		mini1[i][0] = rk1[top1[i]];
}
void work2(void)
{
	for (int i = 1; i <= n; i++)
		if (val2[i]) pos2[++ct2] = i;
	sort(pos2 + 1, pos2 + 1 + ct2, [](int x, int y){return val2[x] > val2[y];});
	for (int i = 1; i <= ct2; i++) rk2[pos2[i]] = i;
	for (int i = 1; i <= ct2; i++)
		ans2[i] = ans2[i - 1] + val2[pos2[i]];
	for (int i = 1; i <= n; i++)
		mini2[i][0] = rk2[top2[i]];
}
int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i < n; i++)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		add(x, y, w), add(y, x, w);
	}
	dfs1(1, 0);
	for (int i = 1; i <= n; i++)
		if (dis1[i] > dis1[root1]) root1 = i;
	dis1[root1] = 0, dfs21(root1, 0);
	for (int i = 1; i <= n; i++)
		if (dis1[i] > dis1[root2]) root2 = i;
	dfs22(root2, 0);
	dfs31(root1, root1);
	dfs32(root2, root2);
	work1(), work2();
	init();
	int lastans = 0;
	while (q--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x = (x + lastans - 1) % n + 1, y = (y + lastans - 1) % n + 1;
		lastans = 0;
		if (rk1[top1[x]] <= 2 * y - 1)
			lastans = max(lastans, ans1[min(ct1, 2 * y - 1)]);
		else
		{
			int tmp = work1(x, 2 * y - 1);
			lastans = max(lastans, max(ans1[2 * y - 2] - dis1[tmp] + maxdis1[x], ans1[2 * y - 1] - maxdis1[tmp] + maxdis1[x]));
		}
		if (rk2[top2[x]] <= 2 * y - 1)
			lastans = max(lastans, ans2[min(ct2, 2 * y - 1)]);
		else
		{
			int tmp = work2(x, 2 * y - 1);
			lastans = max(lastans, max(ans2[2 * y - 2] - dis2[tmp] + maxdis2[x], ans2[2 * y - 1] - maxdis2[tmp] + maxdis2[x]));
		}
		printf("%d\n", lastans);
	}
	return 0;
}