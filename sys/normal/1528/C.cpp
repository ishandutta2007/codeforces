#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 300005;
int T, n, ct, now, ans, cnt, dfn_cnt, sum[Maxn], siz[Maxn], dfn[Maxn], head1[Maxn], head2[Maxn];
pair <int *, int> op[60 * Maxn];
struct edg
{
	int nxt, to;
} edge[2 * Maxn];
void add1(int x, int y)
{
	edge[++cnt] = (edg){head1[x], y};
	head1[x] = cnt;
}
void add2(int x, int y)
{
	edge[++cnt] = (edg){head2[x], y};
	head2[x] = cnt;
}
void init_dfs(int u)
{
	dfn[u] = ++dfn_cnt, siz[u] = 1;
	for (int i = head2[u]; i; i = edge[i].nxt)
		init_dfs(edge[i].to), siz[u] += siz[edge[i].to];
}
int lowbit(int x)
{
	return x & -x;
}
void add(int x, int y)
{
	for (int i = x; i <= n; i += lowbit(i)) sum[i] += y;
}
int ask(int x)
{
	int result = 0;
	for (int i = x; i; i -= lowbit(i)) result += sum[i];
	return result;
}
struct Tree
{
	int lt, rt, val, tag;
} tree[4 * Maxn];
void build(int root, int lt, int rt)
{
	tree[root] = (Tree){lt, rt, 0, -1};
	if (lt + 1 != rt)
	{
		int mid = (lt + rt) >> 1;
		build(root << 1, lt, mid), build(root << 1 | 1, mid, rt);
	}
}
void pushdown(int root)
{
	if (tree[root].tag != -1)
	{
		op[++ct] = make_pair(&tree[root << 1].tag, tree[root << 1].tag);
		op[++ct] = make_pair(&tree[root << 1].val, tree[root << 1].val);
		op[++ct] = make_pair(&tree[root << 1 | 1].tag, tree[root << 1 | 1].tag);
		op[++ct] = make_pair(&tree[root << 1 | 1].val, tree[root << 1 | 1].val);
		op[++ct] = make_pair(&tree[root].tag, tree[root].tag);
		tree[root << 1].tag = tree[root << 1 | 1].tag = tree[root << 1].val = tree[root << 1 | 1].val = tree[root].tag;
		tree[root].tag = -1;
	}
}
void modify(int root, int lt, int rt, int val)
{
	if (lt == tree[root].lt && rt == tree[root].rt)
	{
		op[++ct] = make_pair(&tree[root].val, tree[root].val);
		op[++ct] = make_pair(&tree[root].tag, tree[root].tag);
		tree[root].val = tree[root].tag = val;
	}
	else
	{
		pushdown(root);
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (lt >= mid) modify(root << 1 | 1, lt, rt, val);
		else if (rt <= mid) modify(root << 1, lt, rt, val);
		else modify(root << 1, lt, mid, val), modify(root << 1 | 1, mid, rt, val);
	}
}
int ask(int root, int pos)
{
	if (tree[root].lt + 1 == tree[root].rt)
		return tree[root].val;
	else
	{
		pushdown(root);
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (pos >= mid) return ask(root << 1 | 1, pos);
		else return ask(root << 1, pos);
	}
}
void roll_back(int las)
{
	while (ct != las)
		*op[ct].first = op[ct].second, ct--;
}
void dfs(int u)
{
	int las_ct = ct, F = 0, las_now = now;
	bool flag = false;
	if (!(ask(dfn[u] + siz[u] - 1) - ask(dfn[u] - 1)))
	{
		flag = true;
		int fa = ask(1, dfn[u]);
		if (fa) modify(1, dfn[fa], dfn[fa] + siz[fa], 0), F = fa, add(dfn[fa], -1);
		else now++;
		modify(1, dfn[u], dfn[u] + siz[u], u);
		add(dfn[u], 1);
	}
	ans = max(ans, now);
	for (int i = head1[u]; i; i = edge[i].nxt)
		dfs(edge[i].to);
	roll_back(las_ct);
	now = las_now;
	if (flag)
	{
		add(dfn[u], -1);
		if (F) add(dfn[F], 1);
	}
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		ct = cnt = dfn_cnt = ans = now = 0;
		scanf("%d", &n);
		build(1, 1, n + 1);
		memset(sum, 0, sizeof(int[n + 1]));
		memset(head1, 0, sizeof(int[n + 1]));
		memset(head2, 0, sizeof(int[n + 1]));
		for (int i = 2; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			add1(x, i);
		}
		for (int i = 2; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			add2(x, i);
		}
		init_dfs(1);
		dfs(1);
		printf("%d\n", ans);
	}
	return 0;
}