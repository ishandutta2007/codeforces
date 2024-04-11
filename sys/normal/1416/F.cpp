#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;
int n, m, ct, cnt, s, t, S, T, ans, Cases, head[Maxn], cur[Maxn], dis[Maxn], deg[Maxn];
pair <int, int> pos[Maxn];
vector <vector <int> > id, a, A, B;
bool must[Maxn];
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
	Qu.push(S);
	memset(dis, 0, sizeof(int[ct + 1]));
	while (!Qu.empty())
	{
		int u = Qu.front();
		Qu.pop();
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			if (to != S && !dis[to] && edge[i].w)
				dis[to] = dis[u] + 1, Qu.push(to);
		}
	}
	return dis[T];
}
int dfs(int u, int mini)
{
	if (u == T) return mini;
	int w, used = 0;
	for (int & i = cur[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (dis[to] == dis[u] + 1 && edge[i].w)
		{
			w = dfs(to, min(mini - used, edge[i].w));
			edge[i].w -= w, edge[((i - 1) ^ 1) + 1].w += w, used += w;
			if (mini == used) return used;
		}
	}
	return used;
}
void dinic(void)
{
	while (bfs())
	{
		memcpy(cur, head, sizeof(int[ct + 1]));
		ans += dfs(S, 0x3f3f3f3f);
	}
}
void link(pair <int, int> x, pair <int, int> y)
{
	if (x.first + x.second > y.first + y.second) swap(x, y);
	if (x.first != y.first) B[x.first][x.second] = 'D', B[y.first][y.second] = 'U';
	else B[x.first][x.second] = 'R', B[y.first][y.second] = 'L';
	A[x.first][x.second] = a[x.first][x.second] - 1, A[y.first][y.second] = 1;
}
int main()
{
	scanf("%d", &Cases);
	while (Cases--)
	{
		memset(deg, 0, sizeof(int[ct + 1]));
		memset(head, 0, sizeof(int[ct + 1]));
		ct = cnt = ans = 0;
		s = ++ct, t = ++ct;
		scanf("%d%d", &n, &m);
		id.resize(n + 1), a.resize(n + 1), A.resize(n + 1), B.resize(n + 1);
		for (int i = 1; i <= n; i++)
			id[i].resize(m + 1), a[i].resize(m + 1), A[i].resize(m + 1), B[i].resize(m + 1);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				id[i][j] = a[i][j] = A[i][j] = B[i][j] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%d", &a[i][j]);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				id[i][j] = ++ct, pos[ct] = make_pair(i, j);
				if ((i == 1 || a[i][j] <= a[i - 1][j]) && (i == n || a[i][j] <= a[i + 1][j]) && (j == 1 || a[i][j] <= a[i][j - 1]) && (j == m || (a[i][j] <= a[i][j + 1])))
					must[ct] = true, ((i + j) & 1) ? (deg[s]--, deg[id[i][j]]++) : (deg[id[i][j]]--, deg[t]++);
				else
				{
					must[ct] = false;
					if ((i + j) & 1) add(s, id[i][j], 1);
					else add(id[i][j], t, 1);
				}
			}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				if (i != n && a[i][j] == a[i + 1][j])
					((i + j) & 1) ? add(id[i][j], id[i + 1][j], 1) : add(id[i + 1][j], id[i][j], 1);
				if (j != m && a[i][j] == a[i][j + 1])
					((i + j) & 1) ? add(id[i][j], id[i][j + 1], 1) : add(id[i][j + 1], id[i][j], 1);
			}
		add(t, s, 0x3f3f3f3f);
		S = ++ct, T = ++ct;
		int tot = 0;
		for (int i = 1; i <= ct - 2; i++)
		{
			if (deg[i]) deg[i] > 0 ? add(S, i, deg[i]) : add(i, T, -deg[i]);
			if (deg[i] > 0) tot += deg[i];
		}
 	 	dinic();
		if (ans != tot)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (((i + j) & 1))
					for (int k = head[id[i][j]]; k; k = edge[k].nxt)
					{
						int to = edge[k].to;
						if (to != s && to != t && to != S && to != T && !edge[k].w)
							link(make_pair(i, j), pos[to]);
					}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (!B[i][j])
				{
					if (i != 1 && a[i][j] > a[i - 1][j]) B[i][j] = 'U';
					if (i != n && a[i][j] > a[i + 1][j]) B[i][j] = 'D';
					if (j != 1 && a[i][j] > a[i][j - 1]) B[i][j] = 'L';
					if (j != m && a[i][j] > a[i][j + 1]) B[i][j] = 'R';
				}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (!A[i][j])
				{
					if (B[i][j] == 'L') A[i][j] = a[i][j] - a[i][j - 1];
					if (B[i][j] == 'R') A[i][j] = a[i][j] - a[i][j + 1];
					if (B[i][j] == 'U') A[i][j] = a[i][j] - a[i - 1][j];
					if (B[i][j] == 'D') A[i][j] = a[i][j] - a[i + 1][j];
				}
				printf("%d ", A[i][j]);
			}
			puts("");
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				putchar(B[i][j]), putchar(' ');
			puts("");
		}
	}
	return 0;
}