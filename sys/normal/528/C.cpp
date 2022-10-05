#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;
int n, m, c, ct, cnt, deg[Maxn], head[Maxn], sta[Maxn], tmp[Maxn];
bool vis[2 * Maxn];
struct edg
{
	int nxt, to;
} edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void dfs(int u)
{
	for (int &i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (!vis[i])
		{
			vis[i] = vis[((i - 1) ^ 1) + 1] = true;
			dfs(to);
		}
	}
	sta[++ct] = u;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
		deg[x]++, deg[y]++;
	}
	for (int i = 1; i <= n; i++)
		if (deg[i] & 1) tmp[++c] = i;
	for (int i = 1; i <= c; i += 2)
		add(tmp[i], tmp[i + 1]), add(tmp[i + 1], tmp[i]);
	if (cnt & 2) add(1, 1), add(1, 1);
	dfs(1);
	printf("%d\n", ct - 1);
	for (int i = 1; i < ct; i++)
		if (i & 1) printf("%d %d\n", sta[i], sta[i + 1]);
		else printf("%d %d\n", sta[i + 1], sta[i]);
	return 0;
}