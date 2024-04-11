#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;
int T, n, m, ct, cnt, p[Maxn], q[Maxn], head[Maxn], siz[Maxn], fa[Maxn], deg[Maxn];
vector <int> node, G[Maxn];
set <int> Se;
bool vis[Maxn];
struct edg
{
	int nxt, to;
} edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void dfs1(int u)
{
	for (int i = head[u]; i; i = edge[i].nxt)
		vis[edge[i].to] = true;
	vector <int> tmp;
	for (auto now : Se)
		if (!vis[now]) tmp.push_back(now);
	for (int i = head[u]; i; i = edge[i].nxt)
		vis[edge[i].to] = false;
	for (auto now : tmp)
		Se.erase(now);
	for (auto now : tmp)
		G[u].push_back(now), dfs1(now);
}
int get_fa(int x)
{
	return x == fa[x] ? x : get_fa(fa[x]);
}
void merge(int x, int y)
{
	int a = get_fa(x), b = get_fa(y);
	fa[b] = a;
	siz[a] += siz[b];
}
bool dfs2(int u)
{
	node.push_back(u);
	if (!G[u].size()) return false;
	bool flag = false;
	int tmp1 = 0, tmp2 = 0;
	for (auto now : G[u])
	{
		bool ver = dfs2(now);
		if (G[now].size())
		{
			if (ver) tmp1 = now;
			else tmp2 = now;
		}
		else merge(u, now), flag = true;
	}
	if (flag) return true;
	if (tmp1) return merge(tmp1, u), false;
	else return siz[get_fa(tmp2)]--, fa[tmp2] = tmp2, siz[tmp2] = 1, merge(u, tmp2), true;
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		ct = cnt = 0;
		scanf("%d%d", &n, &m);
		memset(head, 0, sizeof(int[n + 1]));
		memset(deg, 0, sizeof(int[n + 1]));
		for (int i = 1; i <= m; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			add(x, y), add(y, x);
			deg[x]++, deg[y]++;
		}
		for (int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1, Se.insert(i), G[i].clear();
		for (int i = 1; i <= n; i++)
			if (deg[i] == n - 1) Se.erase(i), p[i] = q[i] = ++ct;
		for (int i = 1; i <= n; i++)
			if (Se.find(i) != Se.end())
			{
				node.clear();
				Se.erase(i), dfs1(i);
				dfs2(i);
				for (auto now : node)
					if (get_fa(now) == now) q[now] = p[now] = ++ct, ct += siz[now] - 1;
				for (auto now : node)
					if (get_fa(now) != now) q[now] = ++p[get_fa(now)], p[now] = q[now] - 1;
			}
		for (int i = 1; i <= n; i++)
			printf("%d ", p[i]);
		puts("");
		for (int i = 1; i <= n; i++)
			printf("%d ", q[i]);
		puts("");
	}
	return 0;
}