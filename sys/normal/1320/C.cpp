#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;
int n, m, p;
pair <int ,int> a[Maxn], b[Maxn];
struct point
{
	int x, y, w;
	bool operator < (const point &tmp) const
	{
		return x < tmp.x;
	}
} P[Maxn];
long long ans = -0x3f3f3f3f3f3f3f3fLL;
struct Tree
{
	int lt, rt;
	long long maxi, lazy;
} tree[4 * Maxn];
void build(int root, int lt, int rt)
{
	tree[root] = (Tree){lt, rt, 0, 0};
	if (lt + 1 == rt)
		tree[root].maxi = -b[lt].second;
	else
	{
		int mid = (lt + rt) >> 1;
		build(root << 1, lt, mid);
		build(root << 1 | 1, mid, rt);
		tree[root].maxi = max(tree[root << 1].maxi, tree[root << 1 | 1].maxi);
	}
}
void pushdown(int root)
{
	if (tree[root].lazy)
	{
		int tmp = tree[root].lazy;
		tree[root << 1].lazy += tmp;
		tree[root << 1].maxi += tmp;
		tree[root << 1 | 1].lazy += tmp;
		tree[root << 1 | 1].maxi += tmp;
		tree[root].lazy = 0;
	}
}
void insert(int root, int lt, int rt, int val)
{
	if (lt >= rt) return ;
	if (lt == tree[root].lt && rt == tree[root].rt)
		tree[root].maxi += val, tree[root].lazy += val;
	else
	{
		pushdown(root);
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (lt >= mid) insert(root << 1 | 1, lt, rt, val);
		else if (rt <= mid) insert(root << 1, lt, rt, val);
		else insert(root << 1, lt, mid, val), insert(root << 1 | 1, mid, rt, val);
		tree[root].maxi = max(tree[root << 1].maxi, tree[root << 1 | 1].maxi);
	}
}
int main()
{
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i].first, &a[i].second);
	for (int i = 1; i <= m; i++)
		scanf("%d%d", &b[i].first, &b[i].second);
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + m);
	for (int i = 1; i <= p; i++)
		scanf("%d%d%d", &P[i].x, &P[i].y, &P[i].w);
	sort(P + 1, P + 1 + p);
	build(1, 1, m + 1);
	int pnt = 1;
	for (int i = 1; i <= n; i++)
	{
		while (pnt <= p && P[pnt].x < a[i].first)
		{
			insert(1, lower_bound(b + 1, b + 1 + m, make_pair(P[pnt].y, 0x3f3f3f3f)) - b, m + 1, P[pnt].w);
			pnt++;
		}
		ans = max(ans, tree[1].maxi - a[i].second);
	}
	printf("%lld", ans);
	return 0;
}