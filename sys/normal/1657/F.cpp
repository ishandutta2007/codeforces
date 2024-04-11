#include <bits/stdc++.h>
using namespace std;

const int Maxn = 400005;
int n, q, ct, scc, top, cnt, dfn_cnt, val[Maxn], x[Maxn], y[Maxn], fa[Maxn], dep[Maxn], head[60 * Maxn], dfn[60 * Maxn], low[60 * Maxn], sta[60 * Maxn], bel[60 * Maxn];
vector <int> G[Maxn];
string str[Maxn];
bool in_stack[60 * Maxn];
struct edg
{
	int nxt, to;
} edge[120 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void dfs(int u, int f)
{
	fa[u] = f;
	dep[u] = dep[f] + 1;
	for (auto v : G[u])
		if (v != f)
			dfs(v, u);
}
void work(int x, int y, string s, int id)
{
	int pt1 = 0, pt2 = s.size() - 1;
	bool flag = false;
	while (true)
	{
		if (dep[x] < dep[y]) swap(x, y), flag ^= 1;
		int c = s[flag ? pt2-- : pt1++] - 'a';
		add(id, 2 * q + 1 + (x - 1) * 26 + c);
		add(2 * q + 1 + (x - 1 + n) * 26 + c, ((id - 1) ^ 1) + 1);
		if (x == y) break;
		x = fa[x];
	}
}
void Tarjan(int u)
{
	dfn[u] = low[u] = ++dfn_cnt;
	sta[++top] = u;
	in_stack[u] = true;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (!dfn[to])
		{
			Tarjan(to);
			low[u] = min(low[u], low[to]);
		}
		else if (in_stack[to]) low[u] = min(low[u], dfn[to]);
	}
	if (dfn[u] == low[u])
	{
		scc++;
		int x;
		do
		{
			x = sta[top--];
			in_stack[x] = false;
			bel[x] = scc;
		}
		while (x != u);
	}
}
void modify(int x, int y, string s)
{
	int pt1 = 0, pt2 = s.size() - 1;
	bool flag = false;
	while (true)
	{
		if (dep[x] < dep[y]) swap(x, y), flag ^= 1;
		val[x] = s[flag ? pt2-- : pt1++] - 'a';
		if (x == y) break;
		x = fa[x];
	}
}
int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y), G[y].push_back(x);
	}
	dfs(1, 0);
	for (int i = 1; i <= q; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
		cin >> str[i];
		work(x[i], y[i], str[i], 2 * i - 1), work(y[i], x[i], str[i], 2 * i);
	}
	for (int i = 1; i <= n; i++)
		for (int k = 0; k < 26; k++)
			if (head[2 * q + 1 + (i - 1 + n) * 26 + k])
				for (int j = 0; j < 26; j++)
					if (j != k)
						add(2 * q + 1 + (i - 1) * 26 + j, 2 * q + 1 + (i - 1 + n) * 26 + k);
	for (int i = 1; i <= 2 * q + 52 * n + 1; i++)
		if (!dfn[i]) Tarjan(i);
	for (int i = 1; i <= q; i++)
		if (bel[2 * i - 1] == bel[2 * i])
			return puts("NO"), 0;
	for (int i = 1; i <= q; i++)
	{
		if (bel[2 * i - 1] < bel[2 * i])
			modify(x[i], y[i], str[i]);
		else modify(y[i], x[i], str[i]);
	}
	puts("YES");
	for (int i = 1; i <= n; i++)
		putchar(val[i] + 'a');
	return 0;
}