#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;
int maxi, ct, n, a[Maxn], ans[Maxn], b[Maxn];
map <int, int> Ma;
struct Tree
{
	int lt, rt, val;
}tree[8 * Maxn];
void build(int root, int lt, int rt)
{
	tree[root] = (Tree){lt, rt, 0x3f3f3f3f};
	if (lt + 1 != rt)
	{
		int mid = (lt + rt) / 2;
		build(root << 1, lt, mid);
		build(root << 1 | 1, mid, rt);
	}
}
void insert(int root, int pos, int val)
{
	if (tree[root].lt + 1 == tree[root].rt)
		tree[root].val = min(tree[root].val, val);
	else
	{
		int mid = (tree[root].lt + tree[root].rt) / 2;
		if (pos < mid) insert(root << 1, pos, val);
		else insert(root << 1 | 1, pos, val);
		tree[root].val = min(tree[root << 1].val, tree[root << 1 | 1].val);
	}
}
int ask(int root, int lt, int rt)
{
	if (lt >= rt) return 0x3f3f3f3f;
	if (tree[root].lt == lt && tree[root].rt == rt)
		return tree[root].val;
	else
	{
		int mid = (tree[root].lt + tree[root].rt) / 2;
		if (mid <= lt) return ask(root << 1 | 1, lt, rt);
		else if (rt <= mid) return ask(root << 1, lt, rt);
		else return min(ask(root << 1, lt, mid), ask(root << 1 | 1, mid, rt));
	}
}
int main()
{
	memset(ans, -1, sizeof(ans));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), b[i] = a[i];
	sort(b + 1, b + 1 + n);
	ct = unique(b + 1, b + 1 + n) - b - 1;
	for (int i = 1; i <= ct; i++)
		Ma[b[i]] = i;
	build(1, 1, 3 * n);
	a[0] = a[n];
	for (int i = n; i < 3 * n; i++)
	{
		a[i] = a[i - n];
		insert(1, Ma[a[i]], i);
		maxi = max(maxi, a[i]);
		if (maxi > 2 * a[i] && ans[n] == -1) ans[n] = i - n;
	}
	for (int i = n - 1; i >= 1; i--)
	{
		insert(1, Ma[a[i]], i);
		if (ans[i + 1] != -1)
			ans[i] = ans[i + 1] + 1;
		if (a[i] > a[i + 1])
			ans[i] = min(ans[i], ask(1, 1, ((a[i] & 1) ? upper_bound(b + 1, b + 1 + ct, a[i] / 2) : lower_bound(b + 1, b + 1 + ct, a[i] / 2)) - b) - i);
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	return 0;
}