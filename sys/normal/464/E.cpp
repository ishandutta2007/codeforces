#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100055, p = 1e9 + 7;
int n, m, s, t, cnt, tree_ct, half_null, from[Maxn], Head[Maxn], head[Maxn];
long long P2[Maxn];
bool vis[Maxn];
struct edg
{
	int nxt, to, w;
} edge[2 * Maxn];
void add(int x, int y, int w)
{
	edge[++cnt] = (edg){head[x], y, w};
	head[x] = cnt;
}
struct Tree
{
	int lson, rson, dis;
	long long hash;
} tree[60 * Maxn];
void build_first(int root, int lt, int rt)
{
	if (lt + 1 != rt)
	{
		int mid = (lt + rt) >> 1;
		tree[root].lson = ++tree_ct;
		tree[root].rson = ++tree_ct;
		build_first(tree[root].lson, lt, mid);
		build_first(tree[root].rson, mid, rt);
	}
}
int get_pos(int now, int lt, int rt, int pos)
{
	if (lt + 1 == rt)
	{
		if (tree[now].hash) return lt;
		return lt - 1;
	}
	else
	{
		int mid = (lt + rt) >> 1;
		if (pos >= mid)
			return get_pos(tree[now].rson, mid, rt, pos);
		else
		{
			int tmp = get_pos(tree[now].lson, lt, mid, pos);
			if (tmp == mid - 1) return mid - 1 + tree[tree[now].rson].dis;
			return tmp;
		}
	}
}
void build(int now, int las, int lt, int rt, int pos)
{
	if (lt + 1 == rt)
	{
		tree[now].hash = P2[lt];
		tree[now].dis = 1;
	}
	else
	{
		int mid = (lt + rt) >> 1;
		if (pos >= mid)
		{
			tree[now].lson = tree[las].lson;
			tree[now].rson = ++tree_ct;
			build(tree[now].rson, tree[las].rson, mid, rt, pos);
		}
		else
		{
			tree[now].rson = tree[las].rson;
			tree[now].lson = ++tree_ct;
			build(tree[now].lson, tree[las].lson, lt, mid, pos);
		}
		tree[now].hash = (tree[tree[now].lson].hash + tree[tree[now].rson].hash) % p;
		tree[now].dis = tree[tree[now].lson].dis == mid - lt ? tree[tree[now].lson].dis + tree[tree[now].rson].dis : tree[tree[now].lson].dis;
	}
}
void build(int now, int las, int lt, int rt, int L, int R)
{
	if (lt == L && rt == R) tree_ct--;
	else
	{
		int mid = (lt + rt) >> 1;
		if (L >= mid)
		{
			tree[now].lson = tree[las].lson;
			tree[now].rson = ++tree_ct;
			build(tree[now].rson, tree[las].rson, mid, rt, L, R);
			if (tree[now].rson > tree_ct) tree[now].rson = half_null;
		}
		else if (R <= mid)
		{
			tree[now].rson = tree[las].rson;
			tree[now].lson = ++tree_ct;
			build(tree[now].lson, tree[las].lson, lt, mid, L, R);
			if (tree[now].lson > tree_ct) tree[now].lson = half_null;
		}
		else
		{
			tree[now].lson = ++tree_ct;
			build(tree[now].lson, tree[las].lson, lt, mid, L, mid);
			if (tree[now].lson > tree_ct) tree[now].lson = half_null;
			tree[now].rson = ++tree_ct;
			build(tree[now].rson, tree[las].rson, mid, rt, mid, R);
			if (tree[now].rson > tree_ct) tree[now].rson = half_null;
		}
		tree[now].hash = (tree[tree[now].lson].hash + tree[tree[now].rson].hash) % p;
		tree[now].dis = tree[tree[now].lson].dis == mid - lt ? tree[tree[now].lson].dis + tree[tree[now].rson].dis : tree[tree[now].lson].dis;
	}
}
bool cmp(int A, int B, int lt, int rt)
{
	if (lt + 1 == rt) return tree[A].hash < tree[B].hash;
	else
	{
		int mid = (lt + rt) >> 1;
		if (tree[tree[A].rson].hash == tree[tree[B].rson].hash) return cmp(tree[A].lson, tree[B].lson, lt, mid);
		else return cmp(tree[A].rson, tree[B].rson, mid, rt);
	}
}
struct sta
{
	int u, id;
	bool operator < (const sta &tmp) const
	{
		return !cmp(id, tmp.id, 1, m + 1);
	}
};
priority_queue <sta> Pr;
void dijkstra(void)
{
	build_first(++tree_ct, 1, m + 1);
	Pr.push((sta){s, Head[s] = 1});
	while (!Pr.empty())
	{
		int u = Pr.top().u;
		Pr.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int to = edge[i].to, tmp, pos = get_pos(Head[u], 1, m + 1, edge[i].w), las = Head[u];
			if (edge[i].w <= pos)
			{
				tmp = tree_ct + 1;
				build(++tree_ct, las, 1, m + 1, edge[i].w, pos + 1);
				las = tmp;
			}
			tree_ct++, tmp = tree_ct, build(tree_ct, las, 1, m + 1, pos + 1);
			if (!Head[to] || cmp(tmp, Head[to], 1, m + 1))
			{
				Head[to] = tmp;
				Pr.push((sta){to, Head[to]});
				from[to] = u;
			}
		}
	}
}
stack <int> St;
int main()
{
	half_null = 60 * Maxn - 1;
	tree[half_null].lson = tree[half_null].rson = half_null;
	scanf("%d%d", &n, &m);
	P2[0] = 1;
	for (int i = 1; i <= 100025; i++)
		P2[i] = P2[i - 1] * 2 % p;
	for (int i = 1; i <= m; i++)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		add(x, y, w + 1), add(y, x, w + 1);
	}
	scanf("%d%d", &s, &t);
	m = 100025;
	dijkstra();
	if (!Head[t])
	{
		puts("-1");
		return 0;
	}
	printf("%lld\n", tree[Head[t]].hash * (p + 1) / 2 % p);
	int u = t;
	while (u)
	{
		St.push(u);
		u = from[u];
	}
	printf("%d\n", (int)St.size());
	while (!St.empty()) printf("%d ", St.top()), St.pop();
	return 0;
}