#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int T, n, m, ct, las, cnt, pos1, pos2, p[5], siz[Maxn], deg[Maxn], val[Maxn], head[Maxn];
double v;
bool loop, vis[Maxn];
struct edg
{
	int nxt, to;
} edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void find_loop(int u, int fa)
{
	if (deg[u] == 3 && !pos1) pos1 = u;
	else if (deg[u] == 3) pos2 = u;
	vis[u] = true;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to == fa) continue;
		if (vis[to])
		{
			loop = true;
			las = to;
			val[u] = 1;
			return ;
		}
		else find_loop(to, u);
		if (las)
		{
			val[u] = 1;
			if (u == las) las = 0;
		}
		if (loop) return ;
	}
}
void dfs(int u, int fa)
{
	siz[u] = 1;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
		{
			dfs(to, u);
			siz[u] += siz[to];
		}
	}
}
void dfs2(int u, int fa, int v)
{
	val[u] = val[fa] - v;
	if (!val[u]) return ;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa) dfs2(to, u, v);
	}
}
void print(void)
{
	puts("YES");
	for (int i = 1; i <= n; i++)
		printf("%d ", val[i]);
	puts("");
}
void modify(int u, int fa, int v)
{
	if (u == v)
	{
		val[u] = 2;
		return ;
	}
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
		{
			modify(to, u, v);
			if (val[to])
			{
				val[u] = 2;
				return ;
			}
		}
	}
}
int lcm(int x, int y)
{
	return x / __gcd(x, y) * y;
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		las = cnt = 0;
		loop = false;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) head[i] = deg[i] = val[i] = 0, vis[i] = false;
		for (int i = 1; i <= m; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			add(x, y), add(y, x);
			deg[x]++, deg[y]++;
		}
		for (int i = 1; i <= n; i++)
		{
			if (vis[i]) continue;
			pos1 = pos2 = 0;
			find_loop(i, 0);
			if (loop)
			{
				print();
				goto END;
			}
			if (pos2)
			{
				modify(pos1, 0, pos2);
				for (int i = head[pos1]; i; i = edge[i].nxt)
					if (!val[edge[i].to]) val[edge[i].to] = 1;
				for (int i = head[pos2]; i; i = edge[i].nxt)
					if (!val[edge[i].to]) val[edge[i].to] = 1;
				print();
				goto END;
			}
			if (pos1)
			{
				v = ct = 0;
				dfs(pos1, 0);
				for (int i = head[pos1]; i; i = edge[i].nxt)
					v += 1.0 / (siz[edge[i].to] + 1), p[++ct] = edge[i].to;
				sort(p + 1, p + 4, [](int x, int y){return siz[x] < siz[y];});
				if (v <= 1)
				{
					if (siz[p[1]] >= 2)
					{
						val[pos1] = 3;
						dfs2(p[1], pos1, 1);
						dfs2(p[2], pos1, 1);
						dfs2(p[3], pos1, 1);
						print();
						goto END;
					}
					if (siz[p[2]] >= 3)
					{
						val[pos1] = 4;
						val[p[1]] = 2;
						dfs2(p[2], pos1, 1);
						dfs2(p[3], pos1, 1);
						print();
						goto END;
					}
					val[pos1] = lcm(siz[p[1]] + 1, lcm(siz[p[2]] + 1, siz[p[3]] + 1));
					dfs2(p[1], pos1, val[pos1] / (siz[p[1]] + 1));
					dfs2(p[2], pos1, val[pos1] / (siz[p[2]] + 1));
					dfs2(p[3], pos1, val[pos1] / (siz[p[3]] + 1));
					print();
					goto END;
				}
			}
		}
		for (int i = 1; i <= n; i++)
			if (deg[i] >= 4)
			{
				val[i] = 2;
				for (int j = head[i]; j; j = edge[j].nxt)
					val[edge[j].to] = 1;
				print();
				goto END;
			}
		puts("NO");
		END:;
	}
	return 0;
}