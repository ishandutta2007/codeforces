#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, m, cnt, top, sta[Maxn], head[Maxn], deg[Maxn];
vector <int> G[Maxn];
bool vis[Maxn], in[Maxn];
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
	vis[u] = in[u] = true;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (!in[to]) G[u].push_back(to), deg[to]++;
		if (!vis[to]) dfs(to);
	}
	in[u] = false;
}
bool ask(int x, int y)
{
	int result;
	printf("? %d %d\n", x, y);
	fflush(stdout);
	scanf("%d", &result);
	return result;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i]) dfs(i);
	for (int i = 1; i <= n; i++)
		if (!deg[i]) sta[++top] = i;
	while (top > 1)
	{
		int u = sta[top], v = sta[top - 1];
		top -= 2;
		if (!ask(u, v)) swap(u, v);
		sta[++top] = u;
		for (auto to : G[v]) if (!(--deg[to])) sta[++top] = to;
	}
	printf("! %d\n", sta[1]);
	fflush(stdout);
	return 0;
}