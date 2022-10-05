#include <bits/stdc++.h>
using namespace std;

const int Maxn = 400005;
int n, m, s, t, ct, cnt, ans, dis[Maxn], cur[Maxn], head[Maxn];
vector <pair <int, int> > Ve1[Maxn], Ve2[Maxn];
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
	Qu.push(s);
	memset(dis, 0, sizeof(int[ct + 1]));
	while (!Qu.empty())
	{
		int u = Qu.front();
		Qu.pop();
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			if (!dis[to] && to != s && edge[i].w) dis[to] = dis[u] + 1, Qu.push(to);
		}
	}
	return dis[t];
}
int dfs(int u, int mini)
{
	if (!mini || u == t) return mini;
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
struct Tree
{
	int lt, rt, id;
} out[4 * Maxn], in[4 * Maxn];
void build(int root, int lt, int rt)
{
	out[root] = (Tree){lt, rt, ++ct};
	in[root] = (Tree){lt, rt, ++ct};
	if (lt + 1 == rt)
		add(s, ct, 1), add(ct - 1, t, 1);
	else	
	{
		int mid = (lt + rt) >> 1;
		build(root << 1, lt, mid);
		build(root << 1 | 1, mid, rt);
		add(out[root].id, out[root << 1].id, 0x3f3f3f3f), add(out[root].id, out[root << 1 | 1].id, 0x3f3f3f3f);
		add(in[root << 1].id, in[root].id, 0x3f3f3f3f), add(in[root << 1 | 1].id, in[root].id, 0x3f3f3f3f);
	}
}
void out_insert(int root, int lt, int rt, int id)
{
	if (out[root].lt == lt && out[root].rt == rt)
		add(id, out[root].id, 0x3f3f3f3f);
	else
	{
		int mid = (out[root].lt + out[root].rt) >> 1;
		if (lt >= mid) out_insert(root << 1 | 1, lt, rt, id);
		else if (rt <= mid) out_insert(root << 1, lt, rt, id);
		else out_insert(root << 1, lt, mid, id), out_insert(root << 1 | 1, mid, rt, id);
	}
}
void in_insert(int root, int lt, int rt, int id)
{
	if (in[root].lt == lt && in[root].rt == rt)
		add(in[root].id, id, 0x3f3f3f3f);
	else
	{
		int mid = (in[root].lt + in[root].rt) >> 1;
		if (lt >= mid) in_insert(root << 1 | 1, lt, rt, id);
		else if (rt <= mid) in_insert(root << 1, lt, rt, id);
		else in_insert(root << 1, lt, mid, id), in_insert(root << 1 | 1, mid, rt, id);
	}
}
void link(int a1, int a2, int b1, int b2)
{
	if (a1 > a2 || b1 > b2) return ;
	ct++, in_insert(1, a1, a2 + 1, ct), out_insert(1, b1, b2 + 1, ct);
}
struct line
{
	int l, r, w;
	bool operator < (const line &tmp) const
	{
		return l < tmp.l;
	}
};
set <line> Se;
set <line> :: iterator spilt(int x)
{
	if (x > n) return Se.end();
	set <line> :: iterator it = --Se.upper_bound((line){x, 0, 0});
	if (it -> l == x) return it;
	line tmp = *it;
	Se.erase(it);
	Se.insert((line){tmp.l, x - 1, tmp.w});
	return Se.insert((line){x, tmp.r, tmp.w}).first;
}
void assign(pair <int, int> p, int w)
{
	set <line> :: iterator it_r = spilt(p.second + 1), it_l = spilt(p.first);
	Se.erase(it_l, it_r);
	Se.insert((line){p.first, p.second, w});
}
void work(pair <int, int> p, int w)
{
	set <line> :: iterator it_r = spilt(p.second + 1), it_l = spilt(p.first);
	for (set <line> :: iterator it = it_l; it != it_r; it++)
		link(it -> l, it -> r, it -> w, w - 1);
}
int main()
{
	scanf("%d%d", &n, &m);
	s = ++ct, t = ++ct;
	build(1, 1, n + 1);
	for (int i = 1; i <= m; i++)
	{
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		Ve1[b].push_back(make_pair(a, c));
		Ve2[d + 1].push_back(make_pair(a, c));
	}
	Ve1[n + 1].push_back(make_pair(1, n));
	Se.insert((line){1, n, 1});
	for (int i = 1; i <= n + 1; i++)
	{
		for (auto p : Ve2[i])
			assign(p, i);
		for (auto p : Ve1[i])
			work(p, i);
	}
	dinic();
	printf("%d", ans);
	return 0;
}