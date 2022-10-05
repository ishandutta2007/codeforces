#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;
int n, m, q, cc, cnt, top, Top, dfn_cnt, Dfn_cnt, bcc_ct, Bcc_ct, node_ct, edge_ct, used_ct, times[Maxn], used[Maxn], c[Maxn], father[Maxn], bel[Maxn], Bel[Maxn], sta[Maxn], Sta[Maxn], dep[Maxn], anc[Maxn][20], node[Maxn], real_node[Maxn], mas[Maxn], dfn[Maxn], low[Maxn], Dfn[Maxn], Low[Maxn], head[Maxn];
vector <int> Ve[Maxn], Vt[Maxn];
long long R;
struct edg
{
	int nxt, to;
} edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void Tarjan(int u, int f)
{
	bool tag = false;
	father[u] = f;
	dfn[u] = low[u] = ++dfn_cnt;
	sta[++top] = u;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to == f && !tag)
		{
			tag = true;
			continue;
		}
		if (!dfn[to])
		{
			Tarjan(to, u);
			low[u] = min(low[u], low[to]);
			if (low[to] > dfn[u])
			{
				mas[++bcc_ct] = to;
				int x;
				do
				{
					x = sta[top--];
					bel[x] = bcc_ct;
				} while (x != to);
			}
		}
		else
			low[u] = min(low[u], dfn[to]);
	}
}
void Tarjan2(int u, int f)
{
	bool tag = false;
	Dfn[u] = Low[u] = ++Dfn_cnt;
	Sta[++Top] = u;
	for (vector <int> :: iterator it = Vt[u].begin(); it != Vt[u].end(); it++)
	{
		int to = *it;
		if (to == f && !tag)
		{
			tag = true;
			continue;
		}
		if (!Dfn[to])
		{
			Tarjan2(to, u);
			Low[u] = min(Low[u], Low[to]);
			if (Low[to] > Dfn[u])
			{
				Bcc_ct++;
				int x;
				do
				{
					x = Sta[Top--];
					Bel[x] = Bcc_ct;
				} while (x != to);
			}
		}
		else
			Low[u] = min(Low[u], Dfn[to]);
	}
}
void dfs(int u, int fa, int tim)
{
	times[u] = tim;
	dfn[u] = ++dfn_cnt;
	for (vector <int> :: iterator it = Ve[u].begin(); it != Ve[u].end(); it++)
	{
		if (*it == fa) continue;
		anc[*it][0] = u;
		dep[*it] = dep[u] + 1;
		dfs(*it, u, tim);
	}
}
void init(void)
{
	for (int j = 1; (1 << j) <= bcc_ct; j++)
		for (int i = 1; i <= bcc_ct; i++)
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
}
int lca(int x, int y)
{
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 19; i >= 0; i--)
		if ((dep[x] - dep[y]) & (1 << i)) x = anc[x][i];
	if (x == y) return x;
	for (int i = 19; i >= 0; i--)
		if (anc[x][i] != anc[y][i]) x = anc[x][i], y = anc[y][i];
	return anc[x][0];
}
void build(void)
{
	sort(node + 1, node + 1 + node_ct, [](int x, int y){return dfn[x] < dfn[y];});
	node_ct = unique(node + 1, node + 1 + node_ct) - node - 1;
	for (int i = 1; i <= node_ct; i++)
	{
		if (times[node[i]] != times[node[i - 1]])
		{
			while (top > 1) Vt[sta[top]].push_back(sta[top - 1]), Vt[sta[top - 1]].push_back(sta[top]), top--;
			top = 0;
			if (times[node[i]] != node[i]) sta[++top] = times[node[i]], used[++used_ct] = times[node[i]]; 
		}
		if (!top)
		{
			sta[++top] = node[i];
			used[++used_ct] = node[i];
			continue;
		}
		int l = lca(sta[top], node[i]);
		while (top > 1 && dep[l] < dep[sta[top - 1]]) Vt[sta[top]].push_back(sta[top - 1]), Vt[sta[top - 1]].push_back(sta[top]), top--;
		if (dep[l] < dep[sta[top]]) Vt[sta[top]].push_back(l), Vt[l].push_back(sta[top]), top--;
		if (!top || sta[top] != l) sta[++top] = l, used[++used_ct] = l;
		sta[++top] = node[i];
		used[++used_ct] = node[i];
	}
	while (top > 1) Vt[sta[top]].push_back(sta[top - 1]), Vt[sta[top - 1]].push_back(sta[top]), top--;
}
int rotate(int element)
{
	element = (element + R - 1) % n + 1;
	return element;
}
int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
		{
			Tarjan(i, 0);
			mas[++bcc_ct] = i;
			while (top) bel[sta[top]] = bcc_ct, top--;
		}
	for (int i = 1; i <= bcc_ct; i++)
		if (father[mas[i]]) Ve[bel[father[mas[i]]]].push_back(i), Ve[i].push_back(bel[father[mas[i]]]);
	dfn_cnt = 0;
	for (int i = 1; i <= bcc_ct; i++)
		if (!anc[i][0]) dfs(i, 0, i);
	init();
	for (int Case = 1; Case <= q; Case++)
	{
		cc = Bcc_ct = top = dfn_cnt = used_ct = 0;
		scanf("%d%d", &node_ct, &edge_ct);
		for (int i = 1; i <= node_ct; i++)
		{
			scanf("%d", &node[i]);
			node[i] = bel[rotate(node[i])];
		}
		memcpy(real_node, node, sizeof(int[node_ct + 1]));
		int real_node_ct = node_ct;
		for (int i = 1; i <= edge_ct; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			x = bel[rotate(x)], y = bel[rotate(y)];
			node[++node_ct] = x, node[++node_ct] = y;
			Vt[x].push_back(y), Vt[y].push_back(x);
		}
		build();
		for (int i = 1; i <= used_ct; i++)
			if (!Dfn[used[i]])
			{
				Tarjan2(used[i], 0);
				++Bcc_ct;
				while (Top) Bel[Sta[Top]] = Bcc_ct, Top--;
			}
		for (int i = 1; i <= real_node_ct; i++)
		{
			c[Bel[real_node[i]]]++;
			if (c[Bel[real_node[i]]] == 1) cc++;
			if (cc > 1)
			{
				puts("NO");
				goto END;
			}
		}
		puts("YES"), R += Case;
		END:
		for (int i = 1; i <= used_ct; i++) Vt[used[i]].clear(), Dfn[used[i]] = 0;
		for (int i = 1; i <= real_node_ct; i++) c[Bel[real_node[i]]] = 0;
	}
	return 0;
}