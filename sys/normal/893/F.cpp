#include <bits/stdc++.h>
using namespace std;
const int Maxn = 100005;
int cc, q, n, r, cnt, ct, tot, it, siz[Maxn], dfn[Maxn], bel[Maxn], dep[Maxn], Head[Maxn], val[Maxn], id[Maxn];
struct edg
{
	int nxt, to;
}edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){Head[x], y};
	Head[x] = cnt;
}
vector <int> Ve[Maxn];
void dfs(int u, int fa)
{
	siz[u] = 1; 
	dfn[u] = ++it;
	bel[it] = u;
	dep[u] = dep[fa] + 1;
	Ve[dep[u]].push_back(u);
	for (int i = Head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
		{
			dfs(to, u);
			siz[u] += siz[to];
		}
	}
}
struct Tree
{
	Tree * lson, * rson;
	int mini;
}*head[Maxn], pool[30 * Maxn];
void create(Tree * &t)
{
	t = &pool[++cc];
}
void build_first(Tree * now, int lt, int rt)
{
	if (lt + 1 == rt)
		now -> mini = 0x3f3f3f3f;
	else
	{
		int mid = (lt + rt) >> 1;
		create(now -> lson);
		create(now -> rson);
		build_first(now -> lson, lt, mid);
		build_first(now -> rson, mid, rt);
		now -> mini = 0x3f3f3f3f;
	}
}
void build(Tree * now, Tree * las, int lt, int rt, int pos)
{
	if (lt + 1 == rt)
		now -> mini = val[bel[pos]];
	else
	{
		int mid = (lt + rt) >> 1;
		if (pos >= mid)
		{
			create(now -> rson);
			now -> lson = las -> lson;
			build(now -> rson, las -> rson, mid, rt, pos);
		}
		else
		{
			create(now -> lson);
			now -> rson = las -> rson;
			build(now -> lson, las -> lson, lt, mid, pos);
		}
		now -> mini = min(now -> lson -> mini, now -> rson -> mini);
	}
}
int ask(Tree * now, int lt, int rt, int L, int R)
{
	if (lt == L && rt == R)
		return now -> mini;
	else
	{
		int mid = (lt + rt) >> 1;
		if (L >= mid) return ask(now -> rson, mid, rt, L, R);
		else if (R <= mid) return ask(now -> lson, lt, mid, L, R);
		else return min(ask(now -> lson, lt, mid, L, mid), ask(now -> rson, mid, rt, mid, R));
	}
}
int main()
{
	scanf("%d%d", &n, &r);
	for (int i = 1; i <= n; i++)
		scanf("%d", &val[i]);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	dfs(r, 0);
	create(head[0]);
	head[0] -> mini = 0x3f3f3f3f;
	build_first(head[0], 1, n + 1);
	for (int i = 1; i <= n; i++)
	{
		for (vector <int> ::iterator it = Ve[i].begin(); it != Ve[i].end(); it++)
		{
			ct++;
			create(head[ct]);
			build(head[ct], head[ct - 1], 1, n + 1, dfn[*it]);
		}
		id[i] = ct;
	}
	scanf("%d", &q); 
	int lastans = 0;
	for (int i = 1; i <= q; i++)
	{
		int x, k;
		scanf("%d%d", &x, &k);
		x = (x + lastans) % n + 1;
		k = (k + lastans) % n;
		printf("%d\n", lastans = ask(head[id[min(n, dep[x] + k)]], 1, n + 1, dfn[x], dfn[x] + siz[x]));
	}
	return 0;
}