#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int t, T, n, m, n1, n2 = 0x3f3f3f3f, cnt, u[Maxn], v[Maxn], head[Maxn], l[Maxn], r[Maxn], col[Maxn];
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
		if (col[to] == col[u])
		{
			puts("IMPOSSIBLE");
			exit(0);
		}
	}
}
int main()
{
	scanf("%d%d%d%d", &t, &T, &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &l[i], &r[i]);
		n1 = max(n1, l[i]);
		n2 = min(n2, r[i]);
	}
	while (n1 + n2 < t) n1++;
	while (n1 + n2 > T) n2--;
	if (n2 < 0)
	{
		puts("IMPOSSIBLE");
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		bool flag1 = (l[i] <= n1 && n1 <= r[i]), flag2 = (l[i] <= n2 && n2 <= r[i]);
		if (flag1 && !flag2) col[i] = 0;
		else if (!flag1 && flag2) col[i] = 1;
		else if (flag1 && flag2) col[i] = -1;
		else
		{
			puts("IMPOSSIBLE");
			return 0;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &u[i], &v[i]);
		add(u[i], v[i]), add(v[i], u[i]);
	}
	for (int i = 1; i <= n; i++)
		if (col[i] != -1) dfs(i);
	for (int i = 1; i <= n; i++)
		if (col[i] == -1) col[i] = 0, dfs(i);
	for (int i = 1; i <= m; i++)
		if (col[u[i]] == col[v[i]])
		{
			puts("IMPOSSIBLE");
			return 0;
		}
	puts("POSSIBLE");
	printf("%d %d\n", n1, n2);
	for (int i = 1; i <= n; i++)
		printf("%d", col[i] + 1);
	return 0;
}