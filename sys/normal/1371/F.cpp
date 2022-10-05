#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 1000005;
int n, m;
string str;
struct Tree
{
	int lt, rt, ll, lr, rl, rr, lmaxi1, lmaxi2, rmaxi1, rmaxi2, maxi1, maxi2;
	bool tag;
} tree[4 * Maxn];
Tree Swap(Tree x)
{
	swap(x.ll, x.lr), swap(x.rr, x.rl), swap(x.lmaxi1, x.lmaxi2), swap(x.rmaxi1, x.rmaxi2), swap(x.maxi1, x.maxi2);
	return x;
}
Tree merge(Tree x, Tree y)
{
	if (x.tag) x.tag = false, x = Swap(x);
	if (y.tag) y.tag = false, y = Swap(y);
	Tree ans;
	ans.tag = false;
	ans.lt = x.lt, ans.rt = y.rt;
	if (x.ll == x.rt - x.lt) ans.ll = x.ll + y.ll;
	else ans.ll = x.ll;
	if (y.rr == y.rt - y.lt) ans.rr = y.rr + x.rr;
	else ans.rr = y.rr;
	if (x.lr == x.rt - x.lt) ans.lr = x.lr + y.lr;
	else ans.lr = x.lr;
	if (y.rl == y.rt - y.lt) ans.rl = y.rl + x.rl;
	else ans.rl = y.rl;
	ans.maxi1 = max(x.maxi1, y.maxi1);
	ans.maxi1 = max(ans.maxi1, max(x.rr + y.lmaxi1, x.rmaxi1 + y.ll));
	ans.maxi2 = max(x.maxi2, y.maxi2);
	ans.maxi2 = max(ans.maxi2, max(x.rl + y.lmaxi2, x.rmaxi2 + y.lr));
	ans.lmaxi1 = max(x.lmaxi1 + (x.lmaxi1 == x.rt - x.lt) * y.ll, (x.lr == x.rt - x.lt) ? x.lr + y.lmaxi1 : 0);
	ans.rmaxi1 = max(y.rmaxi1 + (y.rmaxi1 == y.rt - y.lt) * x.rr, (y.rl == y.rt - y.lt) ? y.rl + x.rmaxi1 : 0);
	ans.lmaxi2 = max(x.lmaxi2 + (x.lmaxi2 == x.rt - x.lt) * y.lr, (x.ll == x.rt - x.lt) ? x.ll + y.lmaxi2 : 0);
	ans.rmaxi2 = max(y.rmaxi2 + (y.rmaxi2 == y.rt - y.lt) * x.rl, (y.rr == y.rt - y.lt) ? y.rr + x.rmaxi2 : 0);
	return ans;
}
void pushdown(int root)
{
	if (tree[root].tag)
	{
		tree[root].tag = 0;
		tree[root << 1].tag ^= 1, tree[root << 1 | 1].tag ^= 1;
		tree[root] = Swap(tree[root]);
	}
}
void build(int root, int lt, int rt)
{
	tree[root] = (Tree){lt, rt};
	if (lt + 1 == rt)
	{
		if (str[lt - 1] == '<') tree[root].ll = tree[root].rl = tree[root].maxi1 = tree[root].maxi2 = tree[root].lmaxi1 = tree[root].rmaxi2 = tree[root].rmaxi1 = tree[root].lmaxi2 = 1;
		else tree[root].lr = tree[root].rr = tree[root].maxi1 = tree[root].maxi2 = tree[root].lmaxi1 = tree[root].rmaxi2 = tree[root].rmaxi1 = tree[root].lmaxi2 = 1;
	}
	else
	{
		int mid = (lt + rt) >> 1;
		build(root << 1, lt, mid);
		build(root << 1 | 1, mid, rt);
		tree[root] = merge(tree[root << 1], tree[root << 1 | 1]);
	}
}
void modify(int root, int lt, int rt)
{
	if (lt == tree[root].lt && rt == tree[root].rt)
		tree[root].tag ^= 1;
	else
	{
		pushdown(root);
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (lt >= mid) modify(root << 1 | 1, lt, rt);
		else if (rt <= mid) modify(root << 1, lt, rt);
		else modify(root << 1, lt, mid), modify(root << 1 | 1, mid, rt);
		tree[root] = merge(tree[root << 1], tree[root << 1 | 1]);
	}
}
Tree ask(int root, int lt, int rt)
{
	if (lt == tree[root].lt && rt == tree[root].rt)
	{
		pushdown(root);
		return tree[root];
	}
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
	scanf("%d%d", &n, &m);
	cin >> str;
	build(1, 1, n + 1);
	for (int i = 1; i <= m; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		modify(1, l, r + 1);
		Tree res = ask(1, l, r + 1);
		printf("%d\n", res.tag ? res.maxi2 : res.maxi1);
	}
	return 0;
}