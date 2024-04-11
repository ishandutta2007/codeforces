#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, k;
struct Tree
{
	int lt, rt;
	long long val;
}tree[4 * Maxn];
void build(int root, int lt, int rt)
{
	tree[root] = (Tree){lt, rt, 0x3f3f3f3f3f3f3f3f};
	if (lt + 1 != rt)
	{
		int mid = (lt + rt) >> 1;
		build(root << 1, lt, mid);
		build(root << 1 | 1, mid, rt);
	}
}
void insert(int root, int lt, int rt, long long val)
{
	if (tree[root].lt == lt && tree[root].rt == rt)
		tree[root].val = min(tree[root].val, val);
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
	if (!pos) return 0;
	if (tree[root].lt + 1 == tree[root].rt)
		return tree[root].val;
	else
	{
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (pos >= mid) return min(tree[root].val, ask(root << 1 | 1, pos));
		else return min(tree[root].val, ask(root << 1, pos));
	}
}
string tmp, str;
int main()
{
	scanf("%d%d", &n, &k);
	cin >> tmp;
	str += '0';
	str += tmp;
	build(1, 1, n + 1);
	for (int i = 1; i <= n + k; i++)
	{
		if (i <= n && str[i] == '1')
			insert(1, max(1, i - k), min(i + k, n) + 1, ask(1, max(0, i - k - 1)) + i);
		if (i - k > 0) insert(1, i - k, i - k + 1, ask(1, i - k - 1) + i - k);
	}
	printf("%lld", ask(1, n));
	return 0;
}