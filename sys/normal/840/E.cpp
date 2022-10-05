#include <bits/stdc++.h>
using namespace std;

const int Maxn = 50005;
int n, q, tree_ct, cnt, top, a[Maxn], head[Maxn], lson[20 * Maxn], rson[20 * Maxn], fa[Maxn], anc[Maxn], dep[Maxn], sta[Maxn], f[Maxn][261];
struct edg
{
	int nxt, to;
} edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void insert(int x)
{
	int now = 1;
	for (int i = 15; i >= 0; i--)
		if (x & (1 << i))
		{
			if (!rson[now]) rson[now] = ++tree_ct, lson[tree_ct] = rson[tree_ct] = 0;
			now = rson[now];
		}
		else
		{
			if (!lson[now]) lson[now] = ++tree_ct, lson[tree_ct] = rson[tree_ct] = 0;
			now = lson[now];
		}
}
int ask(int x)
{
	int result = 0, now = 1;
	for (int i = 15; i >= 0; i--)
	{
		if (x & (1 << i))
		{
			if (lson[now]) now = lson[now], result |= 1 << i;
			else now = rson[now];
		}
		else
		{
			if (rson[now]) now = rson[now], result |= 1 << i;
			else now = lson[now];
		}
	}
	return result;
}
void dfs(int u, int Fa)
{
	fa[u] = Fa;
	dep[u] = dep[Fa] + 1;
	sta[++top] = u;
	tree_ct = 1, lson[1] = rson[1] = 0;
	if (top >= 256)
		anc[u] = sta[top - 256];
	for (int i = top; i >= max(1, top - 255); i--)
		insert((top - i) ^ a[sta[i]]);
	for (int i = 0; i <= 256; i++)
		f[u][i] = ask(256 * i);
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != Fa)
			dfs(to, u);
	}
	top--;
}
int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}
	dfs(1, 0);
	while (q--)
	{
		int u, v, ct = 0, ans = 0;
		scanf("%d%d", &u, &v);
		while (dep[v] - dep[u] >= 256)
		{
			ans = max(ans, f[v][ct++]);
			v = anc[v];
		}
		ct *= 256;
		while (v != fa[u])
			ans = max(ans, a[v] ^ (ct++)), v = fa[v];
		printf("%d\n", ans);
	}
	return 0;
}