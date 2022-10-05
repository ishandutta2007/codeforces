#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, ans, root, cnt, ct, head[Maxn], leaf[Maxn], deg[Maxn];
bool col[Maxn];
struct edg
{
	int nxt, to;
} edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void dfs(int u, int fa)
{
	int siz = 0;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
		{
			col[to] = col[u] ^ 1;
			dfs(to, u);
			siz += (deg[to] == 1);
		}
	}
	ans += max(0, siz - 1);
}
int main()
{
	scanf("%d", &n);
	if (n == 2)
	{
		printf("1 1");
		return 0;
	}
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
		deg[x]++, deg[y]++;
	}
	for (int i = 1; i <= n; i++)
		if (deg[i] != 1) root = i;
		else leaf[++ct] = i;
	dfs(root, 0);
	bool tag1 = false, tag2 = false;
	for (int i = 1; i <= ct; i++)
		if (col[leaf[i]]) tag1 = true;
		else tag2 = true;
	if (tag1 && tag2)
		printf("3 ");
	else
		printf("1 ");
	printf("%d", n - 1 - ans);
	return 0;
}