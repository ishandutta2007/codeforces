#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, m, ct, a[Maxn], b[Maxn], x[Maxn], y[Maxn], opt[Maxn], val[Maxn];
set <pair <int, int> > Se[Maxn];
struct ele
{
	int lt, rt, val;
	bool operator < (const ele &A) const
	{
		return lt < A.lt;
	}
};
set <ele> S;
struct Tree
{
	int lt, rt;
	pair <int, long long> tag;
} tree[4 * Maxn];
void build(int root, int lt, int rt)
{
	tree[root] = (Tree){lt, rt, make_pair(0, 0)};
	if (lt + 1 != rt)
	{
		int mid = (lt + rt) >> 1;
		build(root << 1, lt, mid);
		build(root << 1 | 1, mid, rt);
	}
}
pair <int, long long> operator + (const pair <int, long long> &A, const pair <int, long long> &B)
{
	return make_pair(A.first + B.first, A.second + B.second);
}
void pushdown(int root)
{
	tree[root << 1].tag = tree[root << 1].tag + tree[root].tag;
	tree[root << 1 | 1].tag = tree[root << 1 | 1].tag + tree[root].tag;
	tree[root].tag = make_pair(0, 0);
}
void modify(int root, int lt, int rt, pair <int, long long> val)
{
	lt = max(lt, 1);
	if (lt >= rt) return ;
	if (tree[root].lt == lt && tree[root].rt == rt)
		tree[root].tag = tree[root].tag + val;
	else
	{
		pushdown(root);
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (lt >= mid) modify(root << 1 | 1, lt, rt, val);
		else if (rt <= mid) modify(root << 1, lt, rt, val);
		else modify(root << 1, lt, mid, val), modify(root << 1 | 1, mid, rt, val);
	}
}
long long ask(int root, int pos)
{
	if (tree[root].lt + 1 == tree[root].rt)
		return tree[root].tag.first * (long long) tree[root].lt + tree[root].tag.second;
	else
	{
		pushdown(root);
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (pos >= mid) return ask(root << 1 | 1, pos);
		else return ask(root << 1, pos);
	}
}
void work(int u, int lt, int rt, int val)
{
	int las = (--Se[u].lower_bound(make_pair(lt, 0))) -> second + 1, nxt = Se[u].upper_bound(make_pair(rt, 0x3f3f3f3f)) -> first - 1;
	/*
		v: [max(las, lt - v + 1), min(rt, nxt - v + 1)]
		1. las <= lt - v + 1 && rt <= nxt - v + 1
			range: [1, min(lt - las + 1, nxt - rt + 1)]
			modify: [lt - v + 1, rt], ans[v] += rt - lt + v;
		2. las <= lt - v + 1 && rt >= nxt - v + 2
			range: [nxt - rt + 2, lt - las + 1]
			modify: [lt - v + 1, nxt - v + 1], ans[v] += nxt - lt + 1;
		3. las >= lt - v + 2 && rt <= nxt - v + 1
			range: [lt - las + 2, nxt - rt + 1]
			modify: [las, rt], ans[v] += rt - las + 1;
		4. las >= lt - v + 2 & rt >= nxt - v + 2
			range: [max(lt - las + 2, nxt - rt + 2), n]
			modify: [las, nxt - v + 1], ans[v] += nxt - v - las + 2;
	*/
	modify(1, 1, min(lt - las + 1, nxt - rt + 1) + 1, make_pair(val, (rt - lt) * val));
	modify(1, nxt - rt + 2, lt - las + 2, make_pair(0, (nxt - lt + 1) * val));
	modify(1, lt - las + 2, nxt - rt + 2, make_pair(0, (rt - las + 1) * val));
	modify(1, max(lt - las + 2, nxt - rt + 2), nxt - las + 2, make_pair(-val, (nxt - las + 2) * val));
}
set <pair <int, int> > :: iterator spilt(int u, int x)
{
	set <pair <int, int> > :: iterator it = --Se[u].lower_bound(make_pair(x, 0x3f3f3f3f));
	pair <int, int> now = *it;
	if (it -> first == x) return it;
	if (it -> second < x) return ++it;
	Se[u].erase(it);
	Se[u].insert(make_pair(now.first, x - 1));
	return Se[u].insert(make_pair(x, now.second)).first;
}
void erase(int lt, int rt, int u)
{
	set <pair <int, int> > :: iterator it_r = spilt(u, rt + 1), it_l = spilt(u, lt);
	for (auto it = it_l; it != it_r; )
	{
		work(u, it -> first, it -> second, -1);
		it = Se[u].erase(it);
	}
}
set <ele> :: iterator spilt(int x)
{
	if (x > n) return S.end();
	set <ele> :: iterator it = --S.upper_bound((ele){x, 0, 0});
	if (it -> lt == x) return it;
	ele now = *it;
	S.erase(it);
	S.insert((ele){now.lt, x - 1, now.val});
	return S.insert((ele){x, now.rt, now.val}).first;
}
void erase(int lt, int rt)
{
	set <ele> :: iterator it_r = spilt(rt + 1), it_l = spilt(lt);
	for (auto it = it_l; it != it_r; it++)
		erase(it -> lt, it -> rt, it -> val);
	S.erase(it_l, it_r);
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), b[++ct] = a[i];
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &opt[i]);
		if (opt[i] == 1) scanf("%d%d%d", &x[i], &y[i], &val[i]), b[++ct] = val[i];
		else scanf("%d", &val[i]);
	}
	sort(b + 1, b + 1 + ct);
	ct = unique(b + 1, b + 1 + ct) - b - 1;
	for (int i = 1; i <= ct; i++)
		Se[i].insert(make_pair(0, 0)), Se[i].insert(make_pair(n + 1, n + 1));
	build(1, 1, n + 1);
	for (int i = 1; i <= n; i++)
	{
		a[i] = lower_bound(b + 1, b + 1 + ct, a[i]) - b;
		work(a[i], i, i, 1);
		Se[a[i]].insert(make_pair(i, i));
		S.insert((ele){i, i, a[i]});
	}
	for (int i = 1; i <= m; i++)
		if (opt[i] == 1)
		{
			val[i] = lower_bound(b + 1, b + 1 + ct, val[i]) - b;
			erase(x[i], y[i]);
			S.insert((ele){x[i], y[i], val[i]});
			work(val[i], x[i], y[i], 1);
			Se[val[i]].insert(make_pair(x[i], y[i]));
		}
		else
			printf("%lld\n", ask(1, val[i]));
	return 0;
}