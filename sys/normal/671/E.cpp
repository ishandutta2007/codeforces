#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, k, top, ans, sta[Maxn];
long long a[Maxn], b[Maxn], c[Maxn], d[Maxn];
struct Tree
{
	int lt, rt;
	long long maxi, tag, maxi_d;
} tree[4 * Maxn];
void build(int root, int lt, int rt)
{
	tree[root] = (Tree){lt, rt, -0x3f3f3f3f3f3f3f3fLL, 0};
	if (lt + 1 == rt)
		tree[root].maxi_d = d[lt];
	else
	{
		int mid = (lt + rt) >> 1;
		build(root << 1, lt, mid);
		build(root << 1 | 1, mid, rt);
		tree[root].maxi_d = max(tree[root << 1].maxi_d, tree[root << 1 | 1].maxi_d);
	}
}
void pushdown(int root)
{
	tree[root << 1].tag += tree[root].tag;
	tree[root << 1].maxi += tree[root].tag;
	tree[root << 1 | 1].tag += tree[root].tag;
	tree[root << 1 | 1].maxi += tree[root].tag;
	tree[root].tag = 0;
}
void modify(int root, int lt, int rt, long long val)
{
	if (lt == tree[root].lt && rt == tree[root].rt)
		tree[root].maxi += val, tree[root].tag += val;
	else
	{
		pushdown(root);
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (lt >= mid) modify(root << 1 | 1, lt, rt, val);
		else if (rt <= mid) modify(root << 1, lt, rt, val);
		else modify(root << 1, lt, mid, val), modify(root << 1 | 1, mid, rt, val);
		tree[root].maxi = max(tree[root << 1].maxi, tree[root << 1 | 1].maxi);
	}
}
long long maxi_now;
int work(int root, int lt, int rt)
{
	if (lt + 1 == rt) return lt;
	else
	{
		pushdown(root);
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (lt >= mid)
		{
			maxi_now = max(maxi_now, tree[root << 1].maxi);
			return work(root << 1 | 1, lt, rt);
		}
		else if (rt <= mid) return work(root << 1, lt, rt);
		else if (tree[root << 1 | 1].maxi_d + k >= max(maxi_now, tree[root << 1].maxi))
		{
			maxi_now = max(maxi_now, tree[root << 1].maxi);
			return work(root << 1 | 1, mid, rt);
		}
		return work(root << 1, lt, mid);
	}
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; i++)
		scanf("%lld", &a[i]), a[i] += a[i - 1];
	for (int i = 1; i <= n; i++)
		scanf("%lld", &b[i]), b[i] += b[i - 1], c[i] = a[i - 1] - b[i - 1], d[i] = b[i] - a[i - 1];
	build(1, 1, n + 1);
	for (int i = n; i >= 1; i--)
	{
		modify(1, i, i + 1, 0x3f3f3f3f3f3f3f3fLL + d[i]);
		while (top && c[sta[top]] <= c[i])
		{
			if (top > 1) modify(1, sta[top - 1] - 1, n + 1, c[sta[top]] - c[sta[top - 1]]);
			top--;
		}
		if (top) modify(1, sta[top] - 1, n + 1, c[sta[top]] - c[i]);
		sta[++top] = i;
		int lt = 1, rt = top;
		while (lt + 1 <= rt)
		{
			int mid = (lt + rt) >> 1;
			if (c[sta[mid]] - c[i] <= k) rt = mid;
			else lt = mid + 1;
		}
		int maxr;
		if (lt == 1) maxr = n;
		else maxr = sta[lt - 1] - 1;
		maxi_now = -0x3f3f3f3f3f3f3f3fLL;
		ans = max(ans, work(1, 1, maxr + 1) - i + 1);
	}
	printf("%d", ans);
	return 0;
}