#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 400005;
int n, m, r, b, s, t, S, T, ct, cnt, ans, tmp_ct1, tmp_ct2, e[Maxn], x[Maxn], y[Maxn], tmp1[Maxn], tmp2[Maxn], cur[Maxn], deg[Maxn], id1[Maxn], id2[Maxn], mini1[Maxn], mini2[Maxn], cnt1[Maxn], cnt2[Maxn], dis[Maxn], head[Maxn];
struct edg
{
	int nxt, to, w;
} edge[4 * Maxn];
void add(int x, int y, int w)
{
	edge[++cnt] = (edg){head[x], y, w};
	head[x] = cnt;
	edge[++cnt] = (edg){head[y], x, 0};
	head[y] = cnt;
}
queue <int> Qu;
bool bfs(int _s, int _t)
{
	Qu.push(_s);
	memset(dis, 0, sizeof(int[ct + 1]));
	while (!Qu.empty())
	{
		int u = Qu.front();
		Qu.pop();
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			if (to != _s && edge[i].w && !dis[to])
				dis[to] = dis[u] + 1, Qu.push(to);
		}
	}
	return dis[_t];
}
int dfs(int u, int mini, int _t)
{
	if (u == _t || !mini) return mini;
	int w, used = 0;
	for (int & i = cur[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (dis[to] == dis[u] + 1 && edge[i].w)
		{
			w = dfs(to, min(mini - used, edge[i].w), _t);
			used += w, edge[i].w -= w, edge[((i - 1) ^ 1) + 1].w += w;
			if (used == mini) return used;
		}
	}
	return used;
}
void dinic(int _s, int _t, int w)
{
	while (bfs(_s, _t))
	{
		memcpy(cur, head, sizeof(int[ct + 1]));
		ans += w * dfs(_s, 0x3f3f3f3f, _t);
	}
}
int main()
{
	memset(mini1, 0x3f, sizeof(mini1));
	memset(mini2, 0x3f, sizeof(mini2));
	scanf("%d%d%d%d", &n, &m, &r, &b);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &x[i], &y[i]), tmp1[++tmp_ct1] = x[i], tmp2[++tmp_ct2] = y[i];
	sort(tmp1 + 1, tmp1 + 1 + tmp_ct1);
	sort(tmp2 + 1, tmp2 + 1 + tmp_ct2);
	tmp_ct1 = unique(tmp1 + 1, tmp1 + 1 + tmp_ct1) - tmp1 - 1;
	tmp_ct2 = unique(tmp2 + 1, tmp2 + 1 + tmp_ct2) - tmp2 - 1;
	s = ++ct, t = ++ct;
	for (int i = 1; i <= tmp_ct1; i++) id1[i] = ++ct;
	for (int i = 1; i <= tmp_ct2; i++) id2[i] = ++ct;
	for (int i = 1; i <= n; i++)
	{
		x[i] = lower_bound(tmp1 + 1, tmp1 + 1 + tmp_ct1, x[i]) - tmp1;
		y[i] = lower_bound(tmp2 + 1, tmp2 + 1 + tmp_ct2, y[i]) - tmp2;
		add(id1[x[i]], id2[y[i]], 1);
		e[i] = cnt - 1;
		cnt1[x[i]]++, cnt2[y[i]]++;
	}
	for (int i = 1; i <= m; i++)
	{
		int opt, l, d;
		scanf("%d%d%d", &opt, &l, &d);
		if (opt == 1)
		{
			if (*lower_bound(tmp1 + 1, tmp1 + 1 + tmp_ct1, l) != l) continue;
			l = lower_bound(tmp1 + 1, tmp1 + 1 + tmp_ct1, l) - tmp1;
			mini1[l] = min(mini1[l], d);
		}
		else
		{
			if (*lower_bound(tmp2 + 1, tmp2 + 1 + tmp_ct2, l) != l) continue;
			l = lower_bound(tmp2 + 1, tmp2 + 1 + tmp_ct2, l) - tmp2;
			mini2[l] = min(mini2[l], d);
		}
	}
	for (int i = 1; i <= tmp_ct1; i++)
	{
		int down = max(0, (cnt1[i] - mini1[i] + 1) / 2), up = (cnt1[i] + mini1[i]) / 2;
		if (up < down)
		{
			puts("-1");
			return 0;
		}
		add(s, id1[i], up - down);
		deg[s] -= down, deg[id1[i]] += down;
	}
	for (int i = 1; i <= tmp_ct2; i++)
	{
		int down = max(0, (cnt2[i] - mini2[i] + 1) / 2), up = (cnt2[i] + mini2[i]) / 2;
		add(id2[i], t, up - down);
		if (up < down)
		{
			puts("-1");
			return 0;
		}
		deg[id2[i]] -= down, deg[t] += down;
	}
	S = ++ct, T = ++ct;
	for (int i = 1; i <= ct; i++)
		if (deg[i] > 0) add(S, i, deg[i]);
		else add(i, T, -deg[i]);
	add(t, s, 0x3f3f3f3f);
	dinic(S, T, 0);
	ans = edge[cnt].w;
	for (int i = head[S]; i; i = edge[i].nxt)
		if (edge[i].w)
		{
			puts("-1");
			return 0;
		}
	edge[cnt].w = edge[cnt - 1].w = 0;
	if (r > b) dinic(t, s, -1);
	else dinic(s, t, 1);
	printf("%lld\n", ans * (long long) r + (n - ans) * (long long) b);
	for (int i = 1; i <= n; i++)
			putchar("rb"[edge[e[i]].w]);
	return 0;
}