#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, q, a[Maxn];
struct basis
{
	int val[31];
	basis()
	{
		memset(val, 0, sizeof(val));
	}
	void clear(void)
	{
		memset(val, 0, sizeof(val));
	}
	void insert(int x, int pos = 30)
	{
		if (pos == -1) return ;
		if (!x) return ;
		if ((1 << pos) & x)
		{
			if (!val[pos])
				val[pos] = x;
			x ^= val[pos];
		}
		insert(x, pos - 1);
	}
	int cal(void)
	{
		int cnt = 0;
		for (int i = 0; i <= 30; i++)
			if (val[i]) cnt++;
		return cnt;
	}	
} Empty;
basis merge(basis x, basis y)
{
	basis tmp;
	for (int i = 0; i <= 30; i++)
	{
		if (x.val[i]) tmp.insert(x.val[i]);
		if (y.val[i]) tmp.insert(y.val[i]);
	}
	return tmp;
}
struct Tree
{
	int lt, rt, sum, lazy;
	basis now;
} tree[4 * Maxn];
void build(int root, int lt, int rt)
{
	tree[root] = (Tree){lt, rt, a[lt]};
	if (lt + 1 == rt)
		tree[root].now.insert(a[lt] ^ a[lt + 1]);
	else
	{
		int mid = (lt + rt) >> 1;
		build(root << 1, lt, mid);
		build(root << 1 | 1, mid, rt);
		tree[root].now = merge(tree[root << 1].now, tree[root << 1 | 1].now);
	}
}
void pushdown(int root)
{
	if (tree[root].lazy)
	{
		tree[root << 1].sum ^= tree[root].lazy;
		tree[root << 1 | 1].sum ^= tree[root].lazy;
		tree[root << 1].lazy ^= tree[root].lazy;
		tree[root << 1 | 1].lazy ^= tree[root].lazy;
		tree[root].lazy = 0;
	}
}
void modify(int root, int pos, int val)
{
	if (tree[root].lt + 1 == tree[root].rt)
	{
		tree[root].now.clear();
		tree[root].now.insert(val);
	}
	else
	{
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (pos >= mid) modify(root << 1 | 1, pos, val);
		else modify(root << 1, pos, val);
		tree[root].now = merge(tree[root << 1].now, tree[root << 1 | 1].now);
	}
}
void modify2(int root, int lt, int rt, int val)
{
	if (lt == tree[root].lt && rt == tree[root].rt)
	{
		tree[root].sum ^= val;
		tree[root].lazy ^= val;
	}
	else
	{
		pushdown(root);
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (lt >= mid) modify2(root << 1 | 1, lt, rt, val);
		else if (rt <= mid) modify2(root << 1, lt, rt, val);
		else modify2(root << 1, lt, mid, val), modify2(root << 1 | 1, mid, rt, val);
		tree[root].sum = tree[root << 1].sum ^ tree[root << 1 | 1].sum;
	}
}
basis query(int root, int lt, int rt)
{
	if (lt == rt) return Empty;
	if (lt == tree[root].lt && rt == tree[root].rt)
		return tree[root].now;
	else
	{
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (lt >= mid) return query(root << 1 | 1, lt, rt);
		else if (rt <= mid) return query(root << 1, lt, rt);
		else return merge(query(root << 1, lt, mid), query(root << 1 | 1, mid, rt));
	}
}
int query2(int root, int lt, int rt)
{
	if (lt == tree[root].lt && rt == tree[root].rt)
		return tree[root].sum;
	else
	{
		pushdown(root);
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (lt >= mid) return query2(root << 1 | 1, lt, rt);
		else if (rt <= mid) return query2(root << 1, lt, rt);
		else return query2(root << 1, lt, mid) ^ query2(root << 1 | 1, mid, rt);
	}
}
int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	build(1, 1, n + 1);
	for (int i = 1; i <= q; i++)
	{
		int opt;
		scanf("%d", &opt);
		if (opt == 1)
		{
			int lt, rt, k;
			scanf("%d%d%d", &lt, &rt, &k);
			modify2(1, lt, rt + 1, k);
			if (lt > 1) modify(1, lt - 1, query2(1, lt - 1, lt + 1));
			if (rt < n) modify(1, rt, query2(1, rt, rt + 2));
		}
		else
		{
			int lt, rt;
			scanf("%d%d", &lt, &rt);
			basis now = query(1, lt, rt);
			now.insert(query2(1, lt, lt + 1));
			printf("%d\n", 1 << now.cal());
		}
	}
	return 0;
}