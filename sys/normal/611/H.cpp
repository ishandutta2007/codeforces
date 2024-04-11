#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, ct, s, t, m, lg10[Maxn], a[Maxn], b[Maxn], node_cnt[8], edge_cnt[8][8];
namespace Flow
{
	int cnt, ans, head[Maxn], dis[Maxn], cur[Maxn];
	struct edg
	{
		int nxt, to, w;
	} edge[2 * Maxn];
	void add(int x, int y, int w)
	{
		edge[++cnt] = (edg){head[x], y, w};
		head[x] = cnt;
		edge[++cnt] = (edg){head[y], x, 0};
		head[y] = cnt;
	}
	queue <int> Qu;
	bool bfs(void)
	{
		memset(dis, 0, sizeof(int[ct + 1]));
		Qu.push(s);
		while (!Qu.empty())
		{
			int u = Qu.front();
			Qu.pop();
			for (int i = head[u]; i; i = edge[i].nxt)
			{
				int to = edge[i].to;
				if (to != s && !dis[to] && edge[i].w) dis[to] = dis[u] + 1, Qu.push(to);
			}
		}
		return dis[t];
	}
	int dfs(int u, int mini)
	{
		if (u == t || !mini) return mini;
		int w, used = 0;
		for (int & i = cur[u]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			if (dis[to] == dis[u] + 1 && edge[i].w)
			{
				w = dfs(to, min(mini - used, edge[i].w));
				used += w, edge[i].w -= w, edge[((i - 1) ^ 1) + 1].w += w;
				if (used == mini) return used;
			}
		}
		return used;
	}
	void dinic(void)
	{
		while (bfs())
		{
			memcpy(cur, head, sizeof(int[ct + 1]));
			ans += dfs(s, 0x3f3f3f3f);
		}
	}
}
namespace Tree
{
	int now, cnt[8], id[8][8], C[8][8], node_id[8], spec[8], R[8], fa[8];
	bool G[8][8];
	void print(void)
	{
		for (int i = 1; i <= m; i++)
			for (int j = i; j <= m; j++)
			{
				int u = id[i][j];
				for (int k = Flow::head[u]; k; k = Flow::edge[k].nxt)
				{
					int to = Flow::edge[k].to;
					if (to == R[i]) C[i][j] = Flow::edge[((k - 1) ^ 1) + 1].w;
				}
			}
		for (int i = 1; i <= m; i++)
			node_id[i] = spec[i] = spec[i - 1] * 10 + (i == 1);
		for (int i = 1; i < n; i++)
		{
			if (G[a[i]][b[i]]) printf("%d %d\n", spec[a[i]], spec[b[i]]), G[a[i]][b[i]] = G[b[i]][a[i]] = false;
			else if (C[a[i]][b[i]]) printf("%d %d\n", ++node_id[a[i]], spec[b[i]]), C[a[i]][b[i]]--;
			else printf("%d %d\n", spec[a[i]], ++node_id[b[i]]);
		}
	}
	void work(void)
	{
		bool vis[8];
		memset(vis, 0, sizeof(bool[m + 1]));
		for (int i = 2; i <= m; i++)
			G[i][fa[i]] = G[fa[i]][i] = true;
		memset(Flow::head, 0, sizeof(int[ct + 1]));
		Flow::cnt = 0;
		ct = 0, s = ++ct, t = ++ct;
		for (int i = 1; i <= m; i++)
		{
			R[i] = ++ct;
			Flow::add(R[i], t, node_cnt[i] - 1);
		}
		for (int i = 1; i <= m; i++)
			for (int j = i; j <= m; j++)
			{
				id[i][j] = ++ct;
				if (edge_cnt[i][j] - G[i][j] < 0) goto A;
				Flow::add(s, id[i][j], edge_cnt[i][j] - G[i][j]);
				Flow::add(id[i][j], R[i], 0x3f3f3f3f);
				if (i != j) Flow::add(id[i][j], R[j], 0x3f3f3f3f);
			}
		Flow::ans = 0;
		Flow::dinic();
		if (Flow::ans == n - m)
		{
			print();
			exit(0);
		}
		A:for (int i = 2; i <= m; i++)
			G[i][fa[i]] = G[fa[i]][i] = false;
	}
	void dfs(int u)
	{
		if (u == 2 * m - 1) work();
		else
		{
			int las = now;
			for (int i = 2; i <= m; i++)
				if (cnt[i] <= 1)
				{
					if (!cnt[i]) fa[i] = now, now = i;
					else if (now == i) now = fa[now];
					else continue;
					cnt[i]++;
					dfs(u + 1);
					now = las;
					cnt[i]--;
				}
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		string s, t;
		cin >> s >> t;
		a[i] = s.size(), b[i] = t.size();
		if (a[i] > b[i]) swap(a[i], b[i]);
		edge_cnt[a[i]][b[i]]++;
	}
	for (int i = 1; i <= n; i++)
	{
		lg10[i] = lg10[i / 10] + 1;
		node_cnt[lg10[i]]++;
	}
	m = lg10[n];
	Tree::now = 1;
	Tree::dfs(1);
	puts("-1");
	return 0;
}