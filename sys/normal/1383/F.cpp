#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 10055;
int n, m, k, q, cnt, ans, u[11], v[11], f[Maxn], id[Maxn], lg2[Maxn], sum[Maxn], dis[Maxn], cur[Maxn], head[Maxn], las[Maxn];
int F[1 << 10 | 5][2 * Maxn], * W;
struct edg
{
	int nxt, to;
} edge[2 * Maxn];
void add(int x, int y, int w)
{
	edge[++cnt] = (edg){head[x], y};
	W[cnt] = w;
	head[x] = cnt;
	edge[++cnt] = (edg){head[y], x};
	W[cnt] = 0;
	head[y] = cnt;
}
queue <int> Qu;
bool bfs(void)
{
	memset(dis, 0, sizeof(int[n + 1]));
	Qu.push(1);
	while (!Qu.empty())
	{
		int u = Qu.front();
		Qu.pop();
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			if (to != 1 && !dis[to] && W[i]) dis[to] = dis[u] + 1, Qu.push(to);
		}
	}
	return dis[n];
}
int dfs(int u, int mini)
{
	if (u == n || !mini) return mini;
	int w, used = 0;
	for (int & i = cur[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (dis[to] == dis[u] + 1 && W[i])
		{
			w = dfs(to, min(mini - used, W[i]));
			W[i] -= w, W[((i - 1) ^ 1) + 1] += w, used += w;
			if (used == mini) return used;
		}
	}
	return used;
}
void dinic(void)
{
	while (bfs())
	{
		memcpy(cur, head, sizeof(int[n + 1]));
		int w = dfs(1, 0x3f3f3f3f);
		ans += w;
		if (!w) return ;
	}
}
bool ek_bfs(void)
{
	memset(dis, 0, sizeof(int[n + 1]));
	Qu.push(1);
	while (!Qu.empty())
	{
		int u = Qu.front();
		Qu.pop();
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			if (to != 1 && !dis[to] && W[i])
			{
				dis[to] = dis[u] + 1, las[to] = i;
				Qu.push(to);
				if (to == n)
				{
					while (!Qu.empty()) Qu.pop();
					goto A;
				}	
			}
		}
	}
	A:if (!dis[n]) return false;
	int u = n, flow = 0x3f3f3f3f;
	while (u != 1)
	{
		flow = min(flow, W[las[u]]);
		u = edge[((las[u] - 1) ^ 1) + 1].to;
	}
	ans += flow;
	u = n;
	while (u != 1)
	{
		W[las[u]] -= flow;
		W[((las[u] - 1) ^ 1) + 1] += flow;
		u = edge[((las[u] - 1) ^ 1) + 1].to;
	}
	return true;
}
void ek(void)
{
	for (; ek_bfs(); );
}
int main()
{
	srand(time(NULL));
	for (int i = 0; i <= 10; i++)
		lg2[1 << i] = i;
	scanf("%d%d%d%d", &n, &m, &k, &q);
	W = F[0];
	for (int i = 0; i < k; i++)
		scanf("%d%d%*d", &u[i], &v[i]), add(u[i], v[i], 0);
	for (int i = k + 1; i <= m; i++)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		add(x, y, w);
	}
	dinic();
	f[0] = ans;
	for (int i = 1; i < (1 << k); i++)
	{
		int maxi = -1, pos;
		for (int j = 0; j < k; j++)
			if (i & (1 << j))
			{
				if (f[i ^ (1 << j)] == maxi && (rand() & 1))
					maxi = f[i ^ (1 << j)], pos = j;
				if (f[i ^ (1 << j)] > maxi)
					maxi = f[i ^ (1 << j)], pos = j;
			}
		W = F[i];
		ans = f[i ^ (1 << pos)];
		memcpy(W, F[i ^ (1 << pos)], sizeof(int[cnt + 1]));
		W[(pos << 1) + 1] = 25;
		ek();
		f[i] = ans;
	}
	for (int i = 1; i <= q; i++)
	{
		int result = 0x3f3f3f3f, w[11];
		for (int j = 0; j < k; j++)
			scanf("%d", &w[j]);
		for (int j = 1; j < (1 << k); j++)
			sum[j] = sum[j - (j & -j)] + w[lg2[j & -j]];
		for (int j = 0; j < (1 << k); j++)
			result = min(result, f[j] + sum[((1 << k) - 1) ^ j]);
		printf("%d\n", result);
	}
	return 0;
}
//1