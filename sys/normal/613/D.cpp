#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, m, q, ans, ct, cnt, top, a[Maxn], sta[Maxn], head[Maxn], dep[Maxn], dfn[Maxn], anc[Maxn][20], siz[Maxn];
struct edg
{
	int nxt, to;
}edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void dfs(int u, int fa)
{
	dfn[u] = ++ct;
	dep[u] = dep[fa] + 1;
	anc[u][0] = fa;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
			dfs(to, u);
	}
}
void init(void)
{
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i <= n; i++)
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
}
int lca(int x, int y)
{
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 19; i >= 0; i--)
		if ((1 << i) & (dep[x] - dep[y])) x = anc[x][i];
	if (x == y) return x;
	for (int i = 19; i >= 0; i--)
		if (anc[x][i] != anc[y][i]) x = anc[x][i], y = anc[y][i];
	return anc[x][0];
}
void insert(int x)
{
	if (!top)
	{
		sta[++top] = x;
		return ;
	}
	int l = lca(sta[top], x);
	while (top > 1 && dep[l] < dep[sta[top - 1]])
	{
		add(sta[top - 1], sta[top]);
		top--;
	}
	if (dep[l] < dep[sta[top]]) add(l, sta[top--]);
	if (!top || sta[top] != l) sta[++top] = l;
	sta[++top] = x;
}
void dfs2(int u)
{
	if (siz[u])
	{
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			dfs2(to);
			if (siz[to])
				siz[to] = 0, ans++;
		}
	}
	else
	{
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			dfs2(to);
			siz[u] += siz[to];
			siz[to] = 0;
		}
		if (siz[u] > 1)
		{
			ans++;
			siz[u] = 0;
		}
	}
	head[u] = 0;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}
	dfs(1, 0);
	init();
	memset(head, 0, sizeof(head));
	cnt = 0;
	scanf("%d", &q);
	while (q--)
	{
		cnt = top = 0;
		scanf("%d", &m); 
		for (int i = 1; i <= m; i++)
			scanf("%d", &a[i]), siz[a[i]] = 1;
		for (int i = 1; i <= m; i++)
			if (siz[anc[a[i]][0]])
			{
				puts("-1");
				for (int i = 1; i <= m; i++)
					siz[a[i]] = 0; 
				goto END;
			}
		ans = 0;
		sort(a + 1, a + 1 + m, [](int x, int y){return dfn[x] < dfn[y];});
		if (a[1] != 1) sta[++top] = 1;
		for (int i = 1; i <= m; i++) insert(a[i]);
		while (top > 1) add(sta[top - 1], sta[top]), top--;
		dfs2(1);
		siz[1] = 0; 
		printf("%d\n", ans);
		END:;
	}
	return 0;
}