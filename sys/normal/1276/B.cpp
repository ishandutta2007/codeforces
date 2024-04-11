#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;
int T, n, m, head[Maxn], a, b, cnt1, cnt2, cnt;
bool vis[Maxn][3];
struct edg
{
	int nxt, to;
}edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void dfs(int u, int type)
{
	vis[u][type] = true;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (vis[to][type] || to == a || to == b) continue;
		dfs(to, type);
	}
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d%d", &n, &m, &a, &b);
		memset(head, 0, sizeof(int[n + 1]));
		cnt = cnt1 = cnt2 = 0;
		for (int i = 1; i <= n; i++)
			vis[i][1] = vis[i][2] = false;
		for (int i = 1; i <= m; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			add(x, y);
			add(y, x);
		}
		for (int i = head[a]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			if (to != b) dfs(to, 1);
		}
		for (int i = head[b]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			if (to != a) dfs(to, 2);
		}
		for (int i = 1; i <= n; i++)
		{
			if (vis[i][1] && !vis[i][2]) cnt1++;
			if (vis[i][2] && !vis[i][1]) cnt2++;
		}
		printf("%lld\n", cnt1 * (long long) cnt2);
	}
	return 0;
}