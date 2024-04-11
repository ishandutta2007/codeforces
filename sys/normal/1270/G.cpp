#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 1000005;
bool vis[Maxn];
int head[Maxn], cnt, las, n, ans[Maxn], ct, T; //aaa
struct edg
{
	int nxt, to;
}edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void dfs(int u)
{
	vis[u] = true;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (vis[to])
		{
			las = to;
			ans[++ct] = u;
			if (to == u) las = -1;
			return ;
		}
		dfs(to);
		if (las == -1) return ;
		if (las)
		{
			ans[++ct] = u;
			if (las == u)
			{
				las = -1;
			}
			return ;
		}
	}
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		cnt = 0;
		ct = las = 0;
		scanf("%d", &n);
		memset(head, 0, sizeof(int[n + 1]));
		memset(vis, 0, sizeof(bool[n + 1]));
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			add(i, i - x);
		}
		dfs(1);
		printf("%d\n", ct);
		for (int i = 1; i <= ct; i++)
			printf("%d ", ans[i]);
		printf("\n");
	}
	return 0;
}