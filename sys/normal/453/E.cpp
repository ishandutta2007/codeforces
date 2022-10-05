#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, q, tree_ct, k[Maxn], r[Maxn], ord[Maxn], Head[Maxn];
struct Tree
{
	int lson, rson;
	long long k, b;
} tree[24 * Maxn];
void build_first(int root, int lt, int rt)
{
	if (lt + 1 == rt)
		tree[root].k = k[lt], tree[root].b = 0;
	else
	{
		int mid = (lt + rt) >> 1;
		tree[root].lson = ++tree_ct;
		tree[root].rson = ++tree_ct;
		build_first(tree[root].lson, lt, mid);
		build_first(tree[root].rson, mid, rt);
		tree[root].k = tree[tree[root].lson].k + tree[tree[root].rson].k;
		tree[root].b = tree[tree[root].lson].b + tree[tree[root].rson].b;
	}
}
void build(int root, int las, int lt, int rt, int pos)
{
	if (lt + 1 == rt)
		tree[root].k = 0, tree[root].b = r[lt];
	else
	{
		int mid = (lt + rt) >> 1;
		if (pos >= mid)
		{
			tree[root].rson = ++tree_ct;
			tree[root].lson = tree[las].lson;
			build(tree[root].rson, tree[las].rson, mid, rt, pos);
		}
		else
		{
			tree[root].lson = ++tree_ct;
			tree[root].rson = tree[las].rson;
			build(tree[root].lson, tree[las].lson, lt, mid, pos);
		}
		tree[root].k = tree[tree[root].lson].k + tree[tree[root].rson].k;
		tree[root].b = tree[tree[root].lson].b + tree[tree[root].rson].b;
	}
}
pair <long long, long long> operator + (pair <long long, long long> a, pair <long long, long long> b)
{
	return make_pair(a.first + b.first, a.second + b.second);
}
pair <long long, long long> ask(int root, int lt, int rt, int L, int R)
{
	if (lt == L && rt == R) return make_pair(tree[root].k, tree[root].b);
	else
	{
		int mid = (lt + rt) >> 1;
		if (L >= mid) return ask(tree[root].rson, mid, rt, L, R);
		else if (R <= mid) return ask(tree[root].lson, lt, mid, L, R);
		else return ask(tree[root].lson, lt, mid, L, mid) + ask(tree[root].rson, mid, rt, mid, R);
	}
}
struct sta
{
	int lt, rt;
	double t;
	bool operator < (const sta &tmp) const
	{
		return lt < tmp.lt;
	}
};
set <sta> Se;
set <sta> :: iterator spilt(int x)
{
	if (x > n) return Se.end();
	sta tmp = *(--Se.upper_bound((sta){x, 0, 0}));
	Se.erase(tmp);
	if (tmp.lt != x) Se.insert((sta){tmp.lt, x - 1, tmp.t});
	return Se.insert((sta){x, tmp.rt, tmp.t}).first;
}
pair <long long, long long> cal(double t, int lt, int rt)
{
	int L = 0, R = n;
	while (L + 1 <= R)
	{
		int mid = (L + R + 1) >> 1;
		if (r[ord[mid]] > t * k[ord[mid]]) R = mid - 1;
		else L = mid;
	}
	return ask(Head[L], 1, n + 1, lt, rt + 1);
}
set <pair <int, int> > S;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d%d%d", &x, &r[i], &k[i]), ord[i] = i;
		if (!r[i] && !k[i]) r[i] = 1;
		if (k[i])
			Se.insert((sta){i, i, -x / (double) k[i]});
		else Se.insert((sta){i, i, 0}), S.insert(make_pair(i, x));
	}
	S.insert(make_pair(n + 1, 0));
	Head[0] = ++tree_ct;
	build_first(Head[0], 1, n + 1);
	sort(ord + 1, ord + 1 + n, [](int x, int y){return r[x] * (long long) k[y] < r[y] * (long long) k[x];});
	for (int i = 1; i <= n; i++)
		Head[i] = ++tree_ct, build(Head[i], Head[i - 1], 1, n + 1, ord[i]);
	scanf("%d", &q);
	while (q--)
	{
		int t, lt, rt;
		long long ans = 0;
		scanf("%d%d%d", &t, &lt, &rt);
		set <pair <int, int> > :: iterator it;
		while (S.size() > 1 && (it = S.lower_bound(make_pair(lt, 0))) -> first <= rt)
		{
			ans += it -> second;
			S.erase(it);
		}
		set <sta> :: iterator it_r = spilt(rt + 1), it_l = spilt(lt), tmp_it;
		tmp_it = it_l;
		for (; it_l != it_r; it_l++)
		{
			pair <long long, long long> now = cal(t - it_l -> t, it_l -> lt, it_l -> rt);
			ans += now.second + (long long) (now.first * (t - it_l -> t) + 0.5);
		}
		Se.erase(tmp_it, it_r);
		Se.insert((sta){lt, rt, (double) t});
		printf("%lld\n", ans);
	}
	return 0;
}