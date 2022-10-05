#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;
int n, m, cnt, ans, x[Maxn], y[Maxn], ct[Maxn], head[Maxn], deg[Maxn];
struct edg
{
	int nxt, to;
} edge[Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
	deg[y]++;
}
queue <int> Qu;
void bfs(void)
{
	int sum = n;
	for (int i = 1; i <= n; i++)
		if (!deg[i]) Qu.push(i), sum--;
	while (!Qu.empty())
	{
		int u = Qu.front();
		Qu.pop();
		if (!Qu.size())
			ct[u] += sum;
		if (Qu.size() == 1)
		{
			bool flag = true;
			int v = Qu.front();
			for (int i = head[v]; i; i = edge[i].nxt)
			{
				int to = edge[i].to;
				if (deg[to] == 1) flag = false;
			}
			if (flag) ct[u] += sum;
		}
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			deg[to]--;
			if (!deg[to]) Qu.push(to), sum--;
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d%d", &x[i], &y[i]), add(x[i], y[i]);
	bfs();
	memset(head, 0, sizeof(int[n + 1])), cnt = 0;
	for (int i = 1; i <= m; i++) add(y[i], x[i]);
	bfs();
	for (int i = 1; i <= n; i++)
		if (ct[i] >= n - 2) ans++;
	printf("%d", ans);
	return 0;
}