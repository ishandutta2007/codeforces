#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int T, n, m, cnt, head[Maxn], col[Maxn], x[Maxn], y[Maxn], v[Maxn];
vector <pair <int, int> > Ve[Maxn];
bool flag;
struct edg
{
	int nxt, to, w;
} edge[2 * Maxn];
void add(int x, int y, int w)
{
	edge[++cnt] = (edg){head[x], y, w};
	head[x] = cnt;
	edge[++cnt] = (edg){head[y], x, w};
	head[y] = cnt;
}
void dfs(int u, int fa)
{
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
		{
			if (edge[i].w != -1)
			{
				Ve[u].push_back(make_pair(to, edge[i].w));
				Ve[to].push_back(make_pair(u, edge[i].w));
			}
			dfs(to, u);
		}
	}
}
void dfs(int u)
{
	for (auto to : Ve[u])
		if (col[to.first] == -1)
		{
			col[to.first] = col[u] ^ to.second;
			dfs(to.first);
			if (flag) return ;
		}
		else if (col[to.first] != (col[u] ^ to.second))
		{
			flag = true;
			return ;
		}
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		flag = false;
		scanf("%d%d", &n, &m);
		cnt = 0;
		memset(head, 0, sizeof(int[n + 1]));
		for (int i = 1; i <= n; i++) Ve[i].clear();
		for (int i = 1; i < n; i++)
		{
			scanf("%d%d%d", &x[i], &y[i], &v[i]);
			add(x[i], y[i], v[i] == -1 ? -1 : __builtin_popcount(v[i]) & 1);
		}
		dfs(1, 0);
		for (int i = 1; i <= m; i++)
		{
			int a, b, p;
			scanf("%d%d%d", &a, &b, &p);
			Ve[a].push_back(make_pair(b, p));
			Ve[b].push_back(make_pair(a, p));
		}
		memset(col, -1, sizeof(int[n + 1]));
		for (int i = 1; i <= n; i++)
			if (col[i] == -1)
			{
				col[i] = 0, dfs(i);
				if (flag)
				{
					puts("NO");
					goto END;
				}
			}
		puts("YES");
		for (int i = 1; i < n; i++)
			printf("%d %d %d\n", x[i], y[i], v[i] == -1 ? col[x[i]] ^ col[y[i]] : v[i]);
		END:;
	}
	return 0;
}