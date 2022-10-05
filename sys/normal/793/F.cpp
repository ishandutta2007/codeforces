#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, m, q, ans[Maxn];
vector <int> R[Maxn];
vector <pair <int, int> > Q[Maxn];
struct Tree
{
	int lt, rt;
	pair <int, int> maxi, tag;
} tree[4 * Maxn];
pair <int, int> merge(pair <int, int> x, pair <int, int> y)
{
	int tmp[] = {x.first, x.second, y.first, y.second};
	sort(tmp, tmp + 4, greater <int> ());
	if (unique(tmp, tmp + 4) - tmp - 1 == 1)
		return make_pair(tmp[0], 0);
	return make_pair(tmp[0], tmp[1]);
}
void build(int root, int lt, int rt)
{
	tree[root] = (Tree){lt, rt};
	tree[root].tag = make_pair(0x3f3f3f3f, 0);
	if (lt + 1 == rt)
		tree[root].maxi.first = lt;
	else
	{
		int mid = (lt + rt) >> 1;
		build(root << 1, lt, mid);
		build(root << 1 | 1, mid, rt);
		tree[root].maxi = merge(tree[root << 1].maxi, tree[root << 1 | 1].maxi);
	}
}
pair <int, int> tag_merge(pair <int, int> x, pair <int, int> y)
{
	return make_pair(min(x.first, y.first), max(x.second, y.second));
}
void pushdown(int root)
{
	if (tree[root << 1].maxi.first >= tree[root].tag.first)
	{
		tree[root << 1].maxi.first = tree[root].tag.second;
		tree[root << 1].tag = tag_merge(tree[root].tag, tree[root << 1].tag);
	}
	if (tree[root << 1 | 1].maxi.first >= tree[root].tag.first)
	{
		tree[root << 1 | 1].maxi.first = tree[root].tag.second;
		tree[root << 1 | 1].tag = tag_merge(tree[root].tag, tree[root << 1 | 1].tag);
	}
	tree[root].tag = make_pair(0x3f3f3f3f, 0);
}
void modify(int root, int lt, int rt, int w, int val)
{
	if (lt == tree[root].lt && rt == tree[root].rt)
	{
		if (lt + 1 == rt)
		{
			if (tree[root].maxi.first >= w) tree[root].maxi.first = val;
		}
		else
		{
			int mid = (lt + rt) >> 1;
			if (w > tree[root].maxi.first) return ;
			if (w > tree[root].maxi.second) tree[root].maxi.first = val, tree[root].tag = tag_merge(tree[root].tag, make_pair(w, val));
			else
			{
				pushdown(root);
				modify(root << 1, lt, mid, w, val), modify(root << 1 | 1, mid, rt, w, val);
				tree[root].maxi = merge(tree[root << 1].maxi, tree[root << 1 | 1].maxi);
			}
		}
	}
	else
	{
		pushdown(root);
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (lt >= mid) modify(root << 1 | 1, lt, rt, w, val);
		else if (rt <= mid) modify(root << 1, lt, rt, w, val);
		else modify(root << 1, lt, mid, w, val), modify(root << 1 | 1, mid, rt, w, val);
		tree[root].maxi = merge(tree[root << 1].maxi, tree[root << 1 | 1].maxi);
	}
}
int ask(int root, int pos)
{
	if (tree[root].lt + 1 == tree[root].rt)
		return tree[root].maxi.first;
	else
	{
		pushdown(root);
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (pos >= mid) return ask(root << 1 | 1, pos);
		else return ask(root << 1, pos);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	build(1, 1, n + 1);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		R[y].push_back(x);
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		Q[y].push_back(make_pair(x, i));
	}
	for (int i = 1; i <= n; i++)
	{
		for (vector <int> :: iterator it = R[i].begin(); it != R[i].end(); it++)
			modify(1, 1, *it + 1, *it, i);
		for (vector <pair <int, int> > :: iterator it = Q[i].begin(); it != Q[i].end(); it++)
			ans[it -> second] = ask(1, it -> first);
	}
	for (int i = 1; i <= q; i++)
		printf("%d\n", ans[i]);
	return 0;
}