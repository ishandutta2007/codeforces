#include <bits/stdc++.h>
using namespace std;

const int Maxn = 400005;
int n, cnt, deg[Maxn], head[Maxn];
bool vis[Maxn], dir[Maxn];
struct edg
{
	int nxt, to;
}edge[4 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void dfs(int u)
{
	for (int &i = head[u]; i; i = edge[i].nxt)
		if (!vis[(i + 1) >> 1]) vis[(i + 1) >> 1] = true, dir[(i + 1) >> 1] = i & 1, dfs(edge[i].to);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y + 2e5), add(y + 200000, x);
		deg[x]++, deg[y + 200000]++;
	}
	for (int i = 1; i <= 400000; i++)
		if (deg[i] & 1) add(i, 0), add(0, i);
	for (int i = 1; i <= 400000; i++)
		dfs(i);
	for (int i = 1; i <= n; i ++)
		if (dir[i]) putchar('b');
		else putchar('r');
	return 0;
}