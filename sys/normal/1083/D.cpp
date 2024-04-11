#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005, p = 1e9 + 7;
int n, m, a[Maxn], b[Maxn], cnt[Maxn], pos[Maxn], las[Maxn], nxt[Maxn];
long long ans;
struct Tree
{
	int lt, rt, a, b, tag_a, tag_b;
	long long sum[4];
} tree[4 * Maxn];
void build(int root, int lt, int rt)
{
	tree[root] = (Tree){lt, rt, 0, 0x3f3f3f3f, 0, 0x3f3f3f3f};
	if (lt + 1 != rt)
	{
		int mid = (lt + rt) >> 1;
		build(root << 1, lt, mid), build(root << 1 | 1, mid, rt);
	}
}
void update(int root)
{
	tree[root].a = max(tree[root << 1].a, tree[root << 1 | 1].a);
	tree[root].b = min(tree[root << 1].b, tree[root << 1 | 1].b);
	for (int i = 0; i <= 3; i++)
		tree[root].sum[i] = (tree[root << 1].sum[i] + tree[root << 1 | 1].sum[i]) % p;
}
void modify_a(int root, int val)
{
	int lt = tree[root].lt, rt = tree[root].rt;
	tree[root].tag_a = tree[root].a = val;
	tree[root].sum[0] = (rt - lt) * val % p;
	tree[root].sum[2] = (lt + rt - 1LL) * (rt - lt) / 2 % p * val % p;
	tree[root].sum[3] = val * tree[root].sum[1] % p;
}
void modify_b(int root, int val)
{
	int lt = tree[root].lt, rt = tree[root].rt;
	tree[root].tag_b = tree[root].b = val;
	tree[root].sum[1] = (rt - lt) * (long long) val % p;
	tree[root].sum[3] = val * tree[root].sum[0] % p;
}
void pushdown(int root)
{
	if (tree[root].tag_a)
		modify_a(root << 1, tree[root].tag_a), modify_a(root << 1 | 1, tree[root].tag_a), tree[root].tag_a = 0;
	if (tree[root].tag_b != 0x3f3f3f3f)
		modify_b(root << 1, tree[root].tag_b), modify_b(root << 1 | 1, tree[root].tag_b), tree[root].tag_b = 0x3f3f3f3f;
}
void modify_max(int root, int lt, int rt, int val)
{
	if (lt == tree[root].lt && rt == tree[root].rt)
	{
		if (tree[root].a <= val)
			modify_a(root, val);
		else
		{
			if (lt + 1 == rt) return ;
			pushdown(root);
			int mid = (lt + rt) >> 1;
			if (tree[root << 1].a < val) modify_max(root << 1 | 1, mid, rt, val);
			modify_max(root << 1, lt, mid, val);
			update(root);
		}
	}
	else
	{
		pushdown(root);
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (lt >= mid) modify_max(root << 1 | 1, lt, rt, val);
		else if (rt <= mid) modify_max(root << 1, lt, rt, val);
		else modify_max(root << 1, lt, mid, val), modify_max(root << 1 | 1, mid, rt, val);
		update(root);
	}
}
void modify_min(int root, int lt, int rt, int val)
{
	if (lt == tree[root].lt && rt == tree[root].rt)
	{
		if (tree[root].b >= val)
			modify_b(root, val);
		else
		{
			if (lt + 1 == rt) return ;
			pushdown(root);
			int mid = (lt + rt) >> 1;
			if (tree[root << 1].b > val) modify_min(root << 1 | 1, mid, rt, val);
			modify_min(root << 1, lt, mid, val);
			update(root);
		}
	}
	else
	{
		pushdown(root);
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (lt >= mid) modify_min(root << 1 | 1, lt, rt, val);
		else if (rt <= mid) modify_min(root << 1, lt, rt, val);
		else modify_min(root << 1, lt, mid, val), modify_min(root << 1 | 1, mid, rt, val);
		update(root);
	}
}
long long ask(int root, int lt, int rt, int type)
{
	if (tree[root].lt == lt && tree[root].rt == rt)
		return tree[root].sum[type];
	else
	{
		pushdown(root);
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (lt >= mid) return ask(root << 1 | 1, lt, rt, type);
		else if (rt <= mid) return ask(root << 1, lt, rt, type);
		else return (ask(root << 1, lt, mid, type) + ask(root << 1 | 1, mid, rt, type)) % p;
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), b[i] = a[i];
	sort(b + 1, b + 1 + n);
	m = unique(b + 1, b + 1 + n) - b - 1;
	for (int i = 1; i <= n; i++)
		a[i] = lower_bound(b + 1, b + 1 + m, a[i]) - b;
	build(1, 1, n + 1);
	int pnt = n;
	for (int i = 1; i <= n; i++)
		las[i] = pos[a[i]] + 1, pos[a[i]] = i;
	for (int i = 1; i <= m; i++) pos[i] = n + 1;
	for (int i = n; i >= 1; i--)
		nxt[i] = pos[a[i]] - 1, pos[a[i]] = i;
	for (int i = n; i >= 1; i--)
	{
		cnt[a[i]]++;
		modify_max(1, i, pnt + 1, las[i]);
		modify_min(1, i, pnt + 1, nxt[i]);
		while (cnt[a[i]] > 1) cnt[a[pnt]]--, pnt--;
		(ans += i * ask(1, i, pnt + 1, 1) + ask(1, i, pnt + 1, 2) + 2 * p - ask(1, i, pnt + 1, 3) - i * (p + pnt * (pnt + 1LL) / 2 % p - i * (i - 1LL) / 2 % p) % p) %= p;
	}
	printf("%lld", ans);
	return 0;
}