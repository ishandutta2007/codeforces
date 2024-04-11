#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, m, l[Maxn];
long long tot, ans[Maxn];
struct Tree
{
	int lt, rt;
	long long val;
} tree[4 * Maxn];
void build(int root, int lt, int rt)
{
	tree[root] = (Tree){lt, rt};
	if (lt + 1 == rt)
		tree[root].val = ans[lt];
	else
	{
		int mid = (lt + rt) >> 1;
		build(root << 1, lt, mid);
		build(root << 1 | 1, mid, rt);
	}
}
void insert(int root, int lt, int rt, int val)
{
	if (lt == tree[root].lt && rt == tree[root].rt)
		tree[root].val -= val;
	else
	{
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (lt >= mid) insert(root << 1 | 1, lt, rt, val);
		else if (rt <= mid) insert(root << 1, lt, rt, val);
		else insert(root << 1, lt, mid, val), insert(root << 1 | 1, mid, rt, val);
	}
}
long long ask(int root, int pos)
{
	if (tree[root].lt + 1 == tree[root].rt) return tree[root].val;
	else
	{
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (pos >= mid) return tree[root].val + ask(root << 1 | 1, pos);
		else return tree[root].val + ask(root << 1, pos);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d", &l[i]), tot += l[i];
	if (m > n || tot < n)
	{
		puts("-1");
		return 0;
	}
	ans[1] = 1;
	for (int i = 2; i <= m; i++)
		ans[i] = ans[i - 1] + l[i - 1];
	build(1, 1, m + 1);
	int pnt = 1;
	while (pnt < m && ask(1, m) > n - l[m] + 1)
		insert(1, pnt + 1, m + 1, min((long long) l[pnt] - 1, ask(1, m) - n + l[m] - 1)), pnt++;
	for (int i = m; i >= 1; i--)
		if (ask(1, i) > n - l[i] + 1)
		{
			puts("-1");
			return 0;
		}
	for (int i = 1; i <= m; i++)
		printf("%lld ", ask(1, i));
	return 0;
}