#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;
int n, cnt, x[Maxn], y[Maxn], col[Maxn], head[Maxn];
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
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (col[to] == -1) col[to] = col[u] ^ 1, dfs(to);
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
		add(x[i], y[i]), add(y[i], x[i]);
	}
	for (int i = 1; i < 2 * n; i += 2)
		add(i, i + 1), add(i + 1, i);
	memset(col, -1, sizeof(col));
	for (int i = 1; i <= 2 * n; i++)
		if (col[i] == -1) col[i] = 0, dfs(i);
	for (int i = 1; i <= n; i++)
		putchar(col[x[i]] + '1'), putchar(' '), putchar(col[y[i]] + '1'), putchar('\n');
	return 0;
}