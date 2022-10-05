#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;
int n, m, ct, maxi, a[Maxn], ans[Maxn];
pair <int, int> Q[Maxn * 40];
vector <pair <int, int> > Ve[Maxn];
namespace maxi_tree
{
	int tree_ct;
	struct Tree
	{
		int lson, rson, maxi;
	} tree[30 * Maxn];
	void insert(int root, int L, int R, int pos, int val)
	{
		if (L + 1 == R)
			tree[root].maxi = val;
		else
		{
			int mid = (L + R) >> 1;
			if (pos >= mid)
			{
				if (!tree[root].rson) tree[root].rson = ++tree_ct;
				insert(tree[root].rson, mid, R, pos, val);
			}
			else
			{
				if (!tree[root].lson) tree[root].lson = ++tree_ct;
				insert(tree[root].lson, L, mid, pos, val);
			}
			tree[root].maxi = max(tree[tree[root].lson].maxi, tree[tree[root].rson].maxi);
		}
	}
	int ask(int root, int L, int R, int lt, int rt)
	{
		if (lt >= rt || !root) return 0;
		if (lt == L && rt == R)
			return tree[root].maxi;
		else
		{
			int mid = (L + R) >> 1;
			if (lt >= mid) return ask(tree[root].rson, mid, R, lt, rt);
			else if (rt <= mid) return ask(tree[root].lson, L, mid, lt, rt);
			else return max(ask(tree[root].lson, L, mid, lt, mid), ask(tree[root].rson, mid, R, mid, rt));
		}
	}
}
namespace mini_tree
{
	struct Tree
	{
		int lt, rt, mini;
	} tree[4 * Maxn];
	void build(int root, int lt, int rt)
	{
		tree[root] = (Tree){lt, rt, 0x3f3f3f3f};
		if (lt + 1 != rt)
		{
			int mid = (lt + rt) >> 1;
			build(root << 1, lt, mid), build(root << 1 | 1, mid, rt);
		}
	}
	void modify(int root, int lt, int rt, int val)
	{
		if (lt == tree[root].lt && rt == tree[root].rt)
			tree[root].mini = min(tree[root].mini, val);
		else
		{
			int mid = (tree[root].lt + tree[root].rt) >> 1;
			if (lt >= mid) modify(root << 1 | 1, lt, rt, val);
			else if (rt <= mid) modify(root << 1, lt, rt, val);
			else modify(root << 1, lt, mid, val), modify(root << 1 | 1, mid, rt, val);
		}
	}
	int ask(int root, int pos)
	{
		if (tree[root].lt + 1 == tree[root].rt)
			return tree[root].mini;
		else
		{
			int mid = (tree[root].lt + tree[root].rt) >> 1;
			if (pos >= mid) return min(ask(root << 1 | 1, pos), tree[root].mini);
			else return min(ask(root << 1, pos), tree[root].mini);
		}
	}
}
int main()
{
	maxi_tree::tree_ct = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), maxi = max(maxi, a[i]);
	for (int i = 1; i <= n; i++)
	{
		int l = 1;
		while (true)
		{
			int pos = maxi_tree::ask(1, 1, maxi + 1, l, a[i] + 1);
			if (!pos) break;
			Q[++ct] = make_pair(i, pos);
			l = (a[i] + a[pos]) / 2 + 1;
		}
		int r = maxi;
		while (true)
		{
			int pos = maxi_tree::ask(1, 1, maxi + 1, a[i], r + 1);
			if (!pos) break;
			Q[++ct] = make_pair(i, pos);
			r = (a[i] + a[pos] + 1) / 2 - 1;
		}
		maxi_tree::insert(1, 1, maxi + 1, a[i], i);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		Ve[r].push_back(make_pair(l, i));
	}
	sort(Q + 1, Q + 1 + ct);
	int pnt = 1;
	mini_tree::build(1, 1, n + 1);
	for (int i = 1; i <= n; i++)
	{
		while (pnt <= ct && Q[pnt].first == i)
			mini_tree::modify(1, 1, Q[pnt].second + 1, abs(a[i] - a[Q[pnt].second])), pnt++;
		for (auto now : Ve[i])
			ans[now.second] = mini_tree::ask(1, now.first);
	}
	for (int i = 1; i <= m; i++)
		printf("%d\n", ans[i]);
	return 0;
}