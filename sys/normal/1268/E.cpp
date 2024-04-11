#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;
int n, m, cnt, bcc, top, dfn_cnt, x[Maxn], y[Maxn], pre[Maxn], fa[Maxn], sta[Maxn], bel[Maxn], dfn[Maxn], low[Maxn], head[Maxn], mini[Maxn], maxi[Maxn], f[Maxn], val[Maxn];
map <pair <int, int>, int> Ma;
struct edg
{
	int nxt, to;
} edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void dfs(int u, int j)
{
	dfn[u] = ++dfn_cnt, pre[u] = j;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		if (((i + 1) >> 1) == j) continue;
		int to = edge[i].to;
		if (!dfn[to]) fa[to] = u, dfs(to, (i + 1) >> 1);
		else if (dfn[to] == -1)
		{
			bcc++;
			vector <int> Ve;
			Ve.push_back((i + 1) >> 1);
			while (to != u) Ve.push_back(pre[to]), to = fa[to];int x = max_element(Ve.begin(), Ve.end()) - Ve.begin();
			for (auto now : Ve) bel[now] = bcc;
			int y = min_element(Ve.begin(), Ve.end()) - Ve.begin(), val = 0;
			for (int i = y; i != x; i = (i + 1) % (int) Ve.size())
			{
				if (Ve[i] < val) goto END;
				val = Ve[i];
			}
			val = 0;
			for (int i = y; i != x; i = (i - 1 + Ve.size()) % (int) Ve.size())
			{
				if (Ve[i] < val) goto END;
				val = Ve[i];
			}
			maxi[bcc] = Ve[x], mini[bcc] = Ve[y];
		}
		END:;
	}
	dfn[u] = -1;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
		Ma[make_pair(x[i], y[i])] = Ma[make_pair(y[i], x[i])] = i;
		add(x[i], y[i]), add(y[i], x[i]);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) f[i] = 1;
	for (int i = m; i >= 1; i--)
	{
		int tmp = f[x[i]] + f[y[i]];
		if (bel[i] && i == mini[bel[i]])
			tmp -= val[maxi[bel[i]]];
		val[i] = f[x[i]] = f[y[i]] = tmp;
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", f[i] - 1);
	return 0;
}