#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 2000005;
int T, n, ct, a[Maxn], f[Maxn];
long long l[Maxn], r[Maxn], b1[Maxn], b2[Maxn], tmp[Maxn];
struct Tree
{
	int lt, rt, mini, tag, clear_tag;
} tree[4 * Maxn];
void build(int root, int lt, int rt)
{
	tree[root] = (Tree){lt, rt, 0x3f3f3f3f, 0x3f3f3f3f, false};
	if (lt + 1 != rt)
	{
		int mid = (lt + rt) >> 1;
		build(root << 1, lt, mid);
		build(root << 1 | 1, mid, rt);
	}
}
void pushdown(int root)
{
	if (tree[root].clear_tag != 0x3f3f3f3f)
	{
		tree[root << 1].tag = tree[root << 1 | 1].tag = 0x3f3f3f3f;
		tree[root << 1].mini = tree[root << 1 | 1].mini = tree[root << 1].clear_tag = tree[root << 1 | 1].clear_tag = tree[root].clear_tag;
		tree[root].clear_tag = 0x3f3f3f3f;
	}
	else if (tree[root].tag != 0x3f3f3f3f)
	{
		if (tree[root << 1].clear_tag == 0x3f3f3f3f)
			tree[root << 1].tag = min(tree[root << 1].tag, tree[root].tag);
		else tree[root << 1].clear_tag = min(tree[root << 1].clear_tag, tree[root].tag);
		tree[root << 1].mini = min(tree[root << 1].mini, tree[root].tag);
		tree[root << 1 | 1].mini = min(tree[root << 1 | 1].mini, tree[root].tag);
		if (tree[root << 1 | 1].clear_tag == 0x3f3f3f3f)
			tree[root << 1 | 1].tag = min(tree[root << 1 | 1].tag, tree[root].tag);
		else tree[root << 1 | 1].clear_tag = min(tree[root << 1 | 1].clear_tag, tree[root].tag);
		tree[root].tag = 0x3f3f3f3f;
	}
}
void modify1(int root, int lt, int rt, int val)
{
	if (lt >= rt) return ;
	if (lt == tree[root].lt && rt == tree[root].rt)
	{
		tree[root].mini = min(tree[root].mini, val);
		if (tree[root].clear_tag == 0x3f3f3f3f)
			tree[root].tag = min(tree[root].tag, val);
		else tree[root].clear_tag = min(tree[root].clear_tag, val);
	}
	else
	{
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		pushdown(root);
		if (lt >= mid) modify1(root << 1 | 1, lt, rt, val);
		else if (rt <= mid) modify1(root << 1, lt, rt, val);
		else modify1(root << 1, lt, mid, val), modify1(root << 1 | 1, mid, rt, val);
		tree[root].mini = min(tree[root << 1].mini, tree[root << 1 | 1].mini);
	}
}
void modify2(int root, int pos)
{
	if (tree[root].lt + 1 == tree[root].rt)
		tree[root].mini--;
	else
	{
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		pushdown(root);
		if (pos >= mid) modify2(root << 1 | 1, pos);
		else modify2(root << 1, pos);
		tree[root].mini = min(tree[root << 1].mini, tree[root << 1 | 1].mini);
	}
}
void clear(int root, int lt, int rt)
{
	if (lt >= rt) return ;
	if (lt == tree[root].lt && rt == tree[root].rt)
		tree[root].mini = tree[root].clear_tag = 0x3f3f3f3e, tree[root].tag = 0x3f3f3f3f;
	else
	{
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		pushdown(root);
		if (lt >= mid) clear(root << 1 | 1, lt, rt);
		else if (rt <= mid) clear(root << 1, lt, rt);
		else clear(root << 1, lt, mid), clear(root << 1 | 1, mid, rt);
		tree[root].mini = min(tree[root << 1].mini, tree[root << 1 | 1].mini);
	}
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		ct = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]), a[i] -= 2;
		for (int i = 1; i <= n; i++)
		{
			b2[i] = a[i] - b1[i];
			b1[i + 1] = b2[i];
			if (i & 1)
				l[i] = -b2[i], r[i] = b1[i];
			else l[i] = -b1[i], r[i] = b2[i];
			tmp[++ct] = l[i], tmp[++ct] = r[i] + 1;
			if (!(a[i] & 1)) tmp[++ct] = (l[i] + r[i]) / 2, tmp[++ct] = (l[i] + r[i]) / 2 + 1;
		}
		sort(tmp + 1, tmp + 1 + ct);
		ct = unique(tmp + 1, tmp + 1 + ct) - tmp - 1;
		build(1, 1, ct + 1);
		for (int i = 1; i <= n; i++)
		{
			int mid;
			if (!(a[i] & 1)) mid = lower_bound(tmp + 1, tmp + 1 + ct, (l[i] + r[i]) / 2) - tmp;
			l[i] = lower_bound(tmp + 1, tmp + 1 + ct, l[i]) - tmp;
			r[i] = lower_bound(tmp + 1, tmp + 1 + ct, r[i] + 1) - tmp;
			clear(1, 1, l[i]), clear(1, r[i], ct + 1);
			modify1(1, l[i], r[i], f[i] - i + 1);
			if (!(a[i] & 1)) modify2(1, mid);
			f[i + 1] = i + 1 + tree[1].mini;
		}
		printf("%d\n", f[n + 1]);
	}
	return 0;
}