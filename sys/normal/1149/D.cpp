#include <bits/stdc++.h>
using namespace std;

const int Maxn = 205;
int n, m, a, b, id_ct, maxi, cnt, val[Maxn], head[Maxn], fa[Maxn], bel[Maxn], siz[Maxn], u[Maxn], v[Maxn], w[Maxn];
int f[1 << 17 | 5][Maxn];
int get_fa(int x)
{
	return x == fa[x] ? x : fa[x] = get_fa(fa[x]);
}
void merge(int x, int y)
{
	int a = get_fa(x), b = get_fa(y);
	if (a != b)
	{
		if (a < b) swap(a, b);
		fa[a] = b;
		siz[b] += siz[a];
	}
}
struct edg
{
	int nxt, to, w;
} edge[2 * Maxn];
void add(int x, int y, int w)
{
	edge[++cnt] = (edg){head[x], y, w};
	head[x] = cnt;
}
queue <pair <int, int> > Qu;
void SPFA(void)
{
	memset(f, 0x3f, sizeof(f));
	maxi = (1 << id_ct) - 1;
	Qu.push(make_pair(val[1], 1));
	f[val[1]][1] = 0;
	while (!Qu.empty())
	{
		pair <int, int> u = Qu.front();
		Qu.pop();
		for (int i = head[u.second]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			if (val[u.second] != val[to] && (u.first & val[to])) continue;
			if (get_fa(u.second) == get_fa(to) && edge[i].w == b) continue;
			if (f[u.first][u.second] + edge[i].w < f[u.first | val[u.second]][to])
			{
				f[u.first | val[u.second]][to] = f[u.first][u.second] + edge[i].w;
				Qu.push(make_pair(u.first | val[u.second], to));
			}
		}
	}
}
int main()
{
	scanf("%d%d%d%d", &n, &m, &a, &b);
	for (int i = 1; i <= n; i++)
		fa[i] = i, siz[i] = 1;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
		if (w[i] == a) merge(u[i], v[i]);
		add(u[i], v[i], w[i]), add(v[i], u[i], w[i]);
	}
	memset(bel, -1, sizeof(bel));
	for (int i = 1; i <= n; i++)
		if (get_fa(i) == i && siz[i] >= 4) bel[i] = id_ct++;
		else bel[i] = bel[get_fa(i)];
	for (int i = 1; i <= n; i++)
		val[i] = bel[i] != -1 ? (1 << bel[i]) : 0;
	SPFA();
	for (int u = 1; u <= n; u++)
	{
		int mini = 0x3f3f3f3f;
		for (int i = 0; i <= maxi; i++)
			mini = min(mini, f[i][u]);
		printf("%d ", mini);
	}
	return 0;
}