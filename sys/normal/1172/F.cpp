#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;
int n, m, l, r, ct;
long long pool[50 * Maxn], p, a[Maxn];
struct Tree
{
	int lt, rt;
	long long * mini, sum;
} tree[4 * Maxn];
void merge(int root, int len1, int len2)
{
	memset(tree[root].mini, 0x3f, sizeof(long long[len1 + len2 + 1]));
	int pnt = 0;
	for (int i = 0; i <= len1; i++)
	{
		if (pnt > len2) pnt--;
		for (; pnt <= len2; pnt++)
		{
			long long tmp = tree[root << 1 | 1].mini[pnt] + i * p - tree[root << 1].sum;
			long long maxi = tree[root << 1].mini[i + 1] - 1 - i * p + tree[root << 1].sum;
			if (maxi < tree[root << 1 | 1].mini[pnt])
			{
				if (pnt) pnt--;
				break;
			}
			tree[root].mini[i + pnt] = min(tree[root].mini[i + pnt], max(tmp, tree[root << 1].mini[i]));
		}
	}
}
void build(int root, int lt, int rt)
{
	tree[root] = (Tree){lt, rt, pool + ct}, ct += rt - lt + 2, tree[root].mini[rt - lt + 1] = 0x3f3f3f3f3f3f3f3fLL;
	if (lt + 1 == rt)
		tree[root].mini[0] = -0x3f3f3f3f3f3f3f3fLL, tree[root].mini[1] = p - a[lt], tree[root].sum = a[lt];
	else
	{
		int mid = (lt + rt) >> 1;
		build(root << 1, lt, mid);
		build(root << 1 | 1, mid, rt);
		merge(root, mid - lt, rt - mid);
		tree[root].sum = tree[root << 1].sum + tree[root << 1 | 1].sum;
	}
}
long long result;
void ask(int root, int lt, int rt)
{
	if (lt == tree[root].lt && rt == tree[root].rt)
		result += tree[root].sum - p * (upper_bound(tree[root].mini, tree[root].mini + rt - lt + 1, result) - tree[root].mini - 1);
	else
	{
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (lt >= mid) ask(root << 1 | 1, lt, rt);
		else if (rt <= mid) ask(root << 1, lt, rt);
		else ask(root << 1, lt, mid), ask(root << 1 | 1, mid, rt);
	}
}
int main()
{
	scanf("%d%d%lld", &n, &m, &p);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	build(1, 1, n + 1);
	while (m--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		result = 0;
		ask(1, l, r + 1);
		printf("%lld\n", result);
	}
	return 0;
}