#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005, p = 1e9 + 7;
int n, q, tree_ct, head_ct, a[Maxn], head[20 * Maxn], root[Maxn];
vector <pair <int, int> > Ve[Maxn];
struct Tree
{
	int lson, rson, val;
} tree[150 * Maxn];
void build_first(int root, int lt, int rt)
{
	tree[root].val = 1;
	if (lt + 1 != rt)
	{
		int mid = (lt + rt) >> 1;
		tree[root].lson = ++tree_ct;
		tree[root].rson = ++tree_ct;
		build_first(tree[root].lson, lt, mid);
		build_first(tree[root].rson, mid, rt);
	}
}
void build(int root, int las, int lt, int rt, int L, int R, long long val)
{
	tree[root].val = tree[las].val;
	if (lt == L && rt == R) tree[root].val = (tree[root].val * val) % p, tree[root].lson = tree[las].lson, tree[root].rson = tree[las].rson;
	else
	{
		int mid = (lt + rt) >> 1;
		if (L >= mid)
		{
			tree[root].lson = tree[las].lson;
			tree[root].rson = ++tree_ct;
			build(tree[root].rson, tree[las].rson, mid, rt, L, R, val);
		}
		else if (R <= mid)
		{
			tree[root].lson = ++tree_ct;
			tree[root].rson = tree[las].rson;
			build(tree[root].lson, tree[las].lson, lt, mid, L, R, val);
		}
		else
		{
			tree[root].lson = ++tree_ct;
			tree[root].rson = ++tree_ct;
			build(tree[root].lson, tree[las].lson, lt, mid, L, mid, val);
			build(tree[root].rson, tree[las].rson, mid, rt, mid, R, val);
		}
	}
}
long long ask(int root, int lt, int rt, int pos)
{
	if (lt + 1 == rt)
		return tree[root].val;
	else
	{
		int mid = (lt + rt) >> 1;
		if (pos >= mid) return tree[root].val * ask(tree[root].rson, mid, rt, pos) % p;
		else return tree[root].val * ask(tree[root].lson, lt, mid, pos) % p;
	}
}
long long fast_pow(long long x, long long y)
{
	long long ans = 1, now = x;
	while (y)
	{
		if (y & 1) ans = ans * now % p;
		now = now * now % p;
		y >>= 1;
	}
	return ans;
}
void work(int u, int val, int cnt)
{
	while (Ve[val].back().first <= cnt)
	{
		++head_ct;
		build(head[head_ct] = ++tree_ct, head[head_ct - 1], 1, n + 1, Ve[val][Ve[val].size() - 2].second + 1, Ve[val].back().second + 1, fast_pow(val, p - 1 - Ve[val].back().first));
		Ve[val].pop_back();
	}
	++head_ct;
	build(head[head_ct] = ++tree_ct, head[head_ct - 1], 1, n + 1, Ve[val].back().second + 1, u + 1, fast_pow(val, cnt));
	Ve[val].push_back(make_pair(cnt, u));
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	build_first(head[++head_ct] = ++tree_ct, 1, n + 1);
	for (int i = 2; i <= 200000; i++)
		Ve[i].push_back(make_pair(0x3f3f3f3f, 0));
	for (int i = 1; i <= n; i++)
	{
		int maxi = sqrt(a[i]);
		for (int j = 2; j <= maxi; j++)
			if (a[i] % j == 0)
			{
				int ct = 0;
				while (a[i] % j == 0) a[i] /= j, ct++;
				work(i, j, ct);
			}
		if (a[i] != 1) work(i, a[i], 1);
		root[i] = head[head_ct];
	}
	scanf("%d", &q);
	int lastans = 0;
	for (int i = 1; i <= q; i++)
	{
		int lt, rt;
		scanf("%d%d", &lt, &rt);
		lt = (lt + lastans) % n + 1, rt = (rt + lastans) % n + 1;
		if (lt > rt) swap(lt, rt);
		printf("%d\n", lastans = ask(root[rt], 1, n + 1, lt));
	}
	return 0;
}