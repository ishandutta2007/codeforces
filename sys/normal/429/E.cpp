#include <bits/stdc++.h>
using namespace std;

const int Maxn = 600005;
int n, ct, cnt, e[Maxn], l[Maxn], r[Maxn], tmp[Maxn], deg[Maxn], head[Maxn];
struct edg
{
	int nxt, to;
	bool dir;
} edge[2 * Maxn];
void add(int x, int y)
{
	deg[x]++;
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void dfs(int u)
{
	for (int & i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (edge[i].dir || edge[((i - 1) ^ 1) + 1].dir) continue;
		edge[i].dir = true;
		dfs(to);
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &l[i], &r[i]), r[i]++, tmp[++ct] = l[i], tmp[++ct] = r[i];
	sort(tmp + 1, tmp + 1 + ct);
	ct = unique(tmp + 1, tmp + 1 + ct) - tmp - 1;
	for (int i = 1; i <= n; i++)
	{
		l[i] = lower_bound(tmp + 1, tmp + 1 + ct, l[i]) - tmp, r[i] = lower_bound(tmp + 1, tmp + 1 + ct, r[i]) - tmp;
		add(l[i], r[i]), add(r[i], l[i]);
		e[i] = cnt - 1;
	}
	for (int i = ct - 1; i >= 1; i--)
		add(i + 1, i), add(i, i + 1);
	for (int i = 1; i <= ct; i++)
		if (deg[i] & 1) add(0, i), add(i, 0);
	for (int i = 0; i <= ct; i++)
		dfs(i);
	for (int i = 1; i <= n; i++)
		printf("%d ", (int) edge[e[i]].dir);
	return 0;
}