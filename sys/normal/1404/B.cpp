#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int T, n, s, t, da, db, cnt, rt, dep[Maxn], head[Maxn];
struct edg
{
	int nxt, to;
} edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void dfs(int u, int f)
{
	if (dep[u] > dep[rt]) rt = u;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != f)
			dep[to] = dep[u] + 1, dfs(to, u);
	}
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d%d%d", &n, &s, &t, &da, &db);
		memset(head, 0, sizeof(int[n + 1]));
		cnt = 0;
		rt = t;
		for (int i = 1; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			add(x, y), add(y, x);
		}
		if (da > db) 
		{
			 puts("Alice");
			 continue;
		}
		dep[t] = 0;
		dfs(t, 0);
		if (da >= dep[s])
		{
			puts("Alice");
			continue;
		}
		dep[rt] = 0;
		dfs(rt, 0);
		if (da >= (dep[rt] + 1) / 2)
		{
			puts("Alice");
			continue;
		}
		if (db > 2 * da) puts("Bob"); 
		else puts("Alice");
	}
	return 0;
}