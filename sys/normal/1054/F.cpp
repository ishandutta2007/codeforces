#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;
int n, ct, ct1, ct2, cnt, ans_ct, head[Maxn], cur[Maxn], dis[Maxn], x[Maxn], y[Maxn], tmp[Maxn];
pair <pair <int, int>, pair <int, int> > e[Maxn], ans[Maxn];
bool vis[Maxn];
map <pair <pair <int, int>, pair <int, int> >, int> Ma1, Ma2;
vector <pair <int, int> > Ve1[Maxn], Ve2[Maxn];
bool cross(pair <pair <int, int>, pair <int, int> > x, pair <pair <int, int>, pair <int, int> > y)
{
	return y.first.second > x.first.second && y.first.second < x.second.second && x.first.first > y.first.first && x.first.first < y.second.first;
}
struct edg
{
	int nxt, to, w;
} edge[Maxn * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y, 1};
	head[x] = cnt;
	edge[++cnt] = (edg){head[y], x, 0};
	head[y] = cnt;
}
queue <int> Qu;
bool bfs(void)
{
	Qu.push(ct2 + 1);
	memset(dis, 0, sizeof(int[ct2 + 3]));
	while (!Qu.empty())
	{
		int u = Qu.front();
		Qu.pop();
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			if (to != ct2 + 1 && !dis[to] && edge[i].w)
			{
				dis[to] = dis[u] + 1;
				Qu.push(to);
			}
		}
	}
	return dis[ct2 + 2];
}
int dfs(int u, int mini)
{
	if (u == ct2 + 2 || !mini)
		return mini;
	int w, used = 0;
	for (int & i = cur[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (dis[u] + 1 == dis[to] && edge[i].w)
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
		memcpy(cur, head, sizeof(int[ct2 + 3]));
		dfs(ct2 + 1, 0x3f3f3f3f);
	}
}
void DFS(int u)
{
	vis[u] = true;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (!vis[to] && !edge[i].w) DFS(to);
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &x[i], &y[i]), tmp[++ct] = x[i], tmp[++ct] = y[i];
	sort(tmp + 1, tmp + 1 + 2 * n);
	ct = unique(tmp + 1, tmp + 1 + 2 * n) - tmp - 1;
	for (int i = 1; i <= n; i++)
	{
		x[i] = lower_bound(tmp + 1, tmp + 1 + ct, x[i]) - tmp;
		y[i] = lower_bound(tmp + 1, tmp + 1 + ct, y[i]) - tmp;
		Ve1[x[i]].push_back(make_pair(x[i], y[i]));
		Ve2[y[i]].push_back(make_pair(x[i], y[i]));
	}
	for (int i = 1; i <= ct; i++)
		sort(Ve1[i].begin(), Ve1[i].end()), sort(Ve2[i].begin(), Ve2[i].end());
	for (int i = 1; i <= ct; i++)
		for (int j = 0; j < (int)Ve1[i].size() - 1; j++)
		{
			Ma1[make_pair(Ve1[i][j], Ve1[i][j + 1])] = ++ct1;
			e[ct1] = make_pair(Ve1[i][j], Ve1[i][j + 1]);
		}
	ct2 = ct1;
	for (int i = 1; i <= ct; i++)
		for (int j = 0; j < (int)Ve2[i].size() - 1; j++)
		{
			Ma2[make_pair(Ve2[i][j], Ve2[i][j + 1])] = ++ct2;
			e[ct2] = make_pair(Ve2[i][j], Ve2[i][j + 1]);
		}
	for (int i = 1; i <= ct1; i++)
		for (int j = ct1 + 1; j <= ct2; j++)
			if (cross(e[i], e[j]))
				add(i, j);
	for (int i = 1; i <= ct1; i++)
		add(ct2 + 1, i);
	for (int i = ct1 + 1; i <= ct2; i++)
		add(i, ct2 + 2);
	dinic();
	for (int i = head[ct2 + 2]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (!edge[i].w) DFS(to);
	}
	for (int i = head[ct2 + 1]; i; i = edge[i].nxt)
		vis[edge[i].to] ^= 1;
	pair <int, int> las;
	for (int i = 1; i <= ct; i++)
	{
		if (Ve2[i].size()) las = Ve2[i][0];
		for (int j = 0; j < (int)Ve2[i].size() - 1; j++)
			if (!vis[Ma2[make_pair(Ve2[i][j], Ve2[i][j + 1])]])
				ans[++ans_ct] = make_pair(las, Ve2[i][j]), las = Ve2[i][j + 1];
		if (Ve2[i].size()) ans[++ans_ct] = make_pair(las, *Ve2[i].rbegin());
	}
	printf("%d\n", ans_ct);
	for (int i = 1; i <= ans_ct; i++)
		printf("%d %d %d %d\n", tmp[ans[i].first.first], tmp[ans[i].first.second], tmp[ans[i].second.first], tmp[ans[i].second.second]);
	ans_ct = 0;
	for (int i = 1; i <= ct; i++)
	{
		if (Ve1[i].size()) las = Ve1[i][0];
		for (int j = 0; j < (int)Ve1[i].size() - 1; j++)
			if (!vis[Ma1[make_pair(Ve1[i][j], Ve1[i][j + 1])]])
				ans[++ans_ct] = make_pair(las, Ve1[i][j]), las = Ve1[i][j + 1];
		if (Ve1[i].size()) ans[++ans_ct] = make_pair(las, *Ve1[i].rbegin());
	}
	printf("%d\n", ans_ct);
	for (int i = 1; i <= ans_ct; i++)
		printf("%d %d %d %d\n", tmp[ans[i].first.first], tmp[ans[i].first.second], tmp[ans[i].second.first], tmp[ans[i].second.second]);
	return 0;
}