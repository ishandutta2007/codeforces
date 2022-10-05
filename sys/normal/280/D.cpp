#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, m, ct, a[Maxn];
pair <int, int> sta[Maxn];
struct Tree
{
	int lt, rt, lmaxi_pos, rmaxi_pos, lmini_pos, rmini_pos;
	long long maxi, mini, lmaxi, rmaxi, lmini, rmini, sum;
	pair <int, int> maxi_pos, mini_pos;
	bool tag;
} tree[4 * Maxn];
Tree merge(Tree root1, Tree root2)
{
	Tree tmp;
	tmp.tag = false;
	tmp.lt = root1.lt, tmp.rt = root2.rt;
	tmp.sum = root1.sum + root2.sum;
	
	tmp.mini = root1.mini, tmp.mini_pos = root1.mini_pos;
	if (tmp.mini > root2.mini)
		tmp.mini = root2.mini, tmp.mini_pos = root2.mini_pos;
	if (tmp.mini > root1.rmini + root2.lmini)
		tmp.mini = root1.rmini + root2.lmini, tmp.mini_pos = make_pair(root1.rmini_pos, root2.lmini_pos);
	
	tmp.maxi = root1.maxi, tmp.maxi_pos = root1.maxi_pos;
	if (tmp.maxi < root2.maxi)
		tmp.maxi = root2.maxi, tmp.maxi_pos = root2.maxi_pos;
	if (tmp.maxi < root1.rmaxi + root2.lmaxi)
		tmp.maxi = root1.rmaxi + root2.lmaxi, tmp.maxi_pos = make_pair(root1.rmaxi_pos, root2.lmaxi_pos);
	
	tmp.lmini = root1.lmini, tmp.lmini_pos = root1.lmini_pos;
	if (tmp.lmini > root1.sum + root2.lmini)
		tmp.lmini = root1.sum + root2.lmini, tmp.lmini_pos = root2.lmini_pos;
	
	tmp.lmaxi = root1.lmaxi, tmp.lmaxi_pos = root1.lmaxi_pos;
	if (tmp.lmaxi < root1.sum + root2.lmaxi)
		tmp.lmaxi = root1.sum + root2.lmaxi, tmp.lmaxi_pos = root2.lmaxi_pos;
		
	tmp.rmini = root2.rmini, tmp.rmini_pos = root2.rmini_pos;
	if (tmp.rmini > root2.sum + root1.rmini)
		tmp.rmini = root2.sum + root1.rmini, tmp.rmini_pos = root1.rmini_pos;
		
	tmp.rmaxi = root2.rmaxi, tmp.rmaxi_pos = root2.rmaxi_pos;
	if (tmp.rmaxi < root2.sum + root1.rmaxi)
		tmp.rmaxi = root2.sum + root1.rmaxi, tmp.rmaxi_pos = root1.rmaxi_pos;
	return tmp;
}
void rev(int root)
{
	swap(tree[root].mini, tree[root].maxi), swap(tree[root].lmaxi, tree[root].lmini), swap(tree[root].rmaxi, tree[root].rmini);
	tree[root].sum = -tree[root].sum;
	tree[root].mini = -tree[root].mini, tree[root].maxi = -tree[root].maxi;
	tree[root].lmaxi = -tree[root].lmaxi, tree[root].lmini = -tree[root].lmini;
	tree[root].rmaxi = -tree[root].rmaxi, tree[root].rmini = -tree[root].rmini;
	swap(tree[root].maxi_pos, tree[root].mini_pos), swap(tree[root].lmaxi_pos, tree[root].lmini_pos), swap(tree[root].rmaxi_pos, tree[root].rmini_pos);
}
void pushdown(int root)
{
	if (tree[root].tag)
	{
		tree[root << 1].tag ^= 1, tree[root << 1 | 1].tag ^= 1;
		rev(root << 1), rev(root << 1 | 1);
		tree[root].tag = false;
	}
}
Tree gen(int l, int v)
{
	return (Tree){l, l + 1, l, l, l, l, v, v, v, v, v, v, v, make_pair(l, l), make_pair(l, l), false};
}
void build(int root, int lt, int rt)
{
	tree[root] = (Tree){lt, rt};
	if (lt + 1 == rt)
		tree[root] = gen(lt, a[lt]);
	else
	{
		int mid = (lt + rt) >> 1;
		build(root << 1, lt, mid);
		build(root << 1 | 1, mid, rt);
		tree[root] = merge(tree[root << 1], tree[root << 1 | 1]);
	}
}
void modify1(int root, int pos, int val)
{
	if (tree[root].lt + 1 == tree[root].rt)
		tree[root] = gen(tree[root].lt, val);
	else
	{
		pushdown(root);
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (pos >= mid) modify1(root << 1 | 1, pos, val);
		else modify1(root << 1, pos, val);
		tree[root] = merge(tree[root << 1], tree[root << 1 | 1]);
	}
}
void modify2(int root, int lt, int rt)
{
	if (tree[root].lt == lt && tree[root].rt == rt)
		tree[root].tag ^= 1, rev(root);
	else
	{
		pushdown(root);
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (lt >= mid) modify2(root << 1 | 1, lt, rt);
		else if (rt <= mid) modify2(root << 1, lt, rt);
		else modify2(root << 1, lt, mid), modify2(root << 1 | 1, mid, rt);
		tree[root] = merge(tree[root << 1], tree[root << 1 | 1]);
	}
}
Tree ask(int root, int lt, int rt)
{
	if (lt == tree[root].lt && rt == tree[root].rt)
		return tree[root];
	else
	{
		pushdown(root);
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (lt >= mid) return ask(root << 1 | 1, lt, rt);
		else if (rt <= mid) return ask(root << 1, lt, rt);
		else return merge(ask(root << 1, lt, mid), ask(root << 1 | 1, mid, rt));
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	build(1, 1, n + 1);
	scanf("%d", &m);
	while (m--)
	{
		int opt;
		scanf("%d", &opt);
		if (!opt)
		{
			int pos, val;
			scanf("%d%d", &pos, &val);
			modify1(1, pos, val);
		}
		else
		{
			int l, r, k;
			long long ans = 0;
			scanf("%d%d%d", &l, &r, &k);
			while (k--)
			{
				Tree now = ask(1, l, r + 1);
				if (now.maxi < 0) break;
				sta[++ct] = make_pair(now.maxi_pos.first, now.maxi_pos.second);
				ans += now.maxi;
				modify2(1, now.maxi_pos.first, now.maxi_pos.second + 1);
			}
			while (ct)
				modify2(1, sta[ct].first, sta[ct].second + 1), ct--;
			printf("%lld\n", ans);
		}
	}
	return 0;
}