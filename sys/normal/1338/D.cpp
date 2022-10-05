#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 100005;
int n, cnt, ans, head[Maxn], f[Maxn][2];
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
	int maxi0 = 0, maxi1 = 0, tmp0 = 0, tmp1 = 0, son = 0;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
		{
			dfs(to, u);
			f[u][1] = max(f[u][1], f[to][0]);
			f[u][0] = max(f[u][0], max(f[to][0], f[to][1]));
			tmp0 = max(tmp0, max(maxi0, maxi1) + max(f[to][0], f[to][1]));
			tmp1 = max(tmp1, maxi0 + f[to][0] + 1);
			maxi0 = max(maxi0, f[to][0]);
			maxi1 = max(maxi1, f[to][1]);
			son++;
		}
	}
	ans = max(ans, max(tmp0 + son - 1 - (u == 1), tmp1));
	f[u][0] += son - 1;
	f[u][1]++;
	ans = max(ans, max(f[u][1], f[u][0] + (u != 1)));
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}
	dfs(1, 0);
	printf("%d", ans);
	return 0;
}