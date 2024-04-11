/*input
1
7 4
3 1
5 2
6 2
7 2
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using ordered_map = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using fast_map = cc_hash_table<T, X>;
//using ull = __ull128_t;
using ull = unsigned long long;
using ll = long long;
using ld = double;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename T>
void sort_unique(T x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
const ll mod = 998244353;
//const ll mod = 1000000007;
ll power(ll a, ll b)
{
	if (abs(a) >= mod)
		a %= mod;
	if (abs(b) >= mod - 1)
		b %= (mod - 1);
	if (a < 0)
		a += mod;
	if (b < 0)
		b += mod - 1;
	ll r = 1;
	if (b % 2 == 1)
		r = a;
	b /= 2;
	while (b)
	{
		a = (a * a) % mod;
		if (b % 2 == 1)
			r = (r * a) % mod;
		b /= 2;
	}
	return r;
}
ll F[400009];
ll C(ll a, ll b)
{
	ll x = F[a];
	ll y = F[b] * F[a - b];
	y %= mod;
	return (x * power(y, -1)) % mod;
}
struct node
{
	int w;
	int sz;
	int k;
	int l, r;
	node(): sz(0), k(0), l(0), r(0)
	{
		w = rng();
	}
	node(int sz): sz(sz), k(sz), l(0), r(0)
	{
		w = rng();
	}
};
vector<node> med(1, node(0));
int make(int sz)
{
	med.push_back(node(sz));
	return med.size() - 1;
}
int merge(int x, int y)
{
	if (x == 0 || y == 0)
		return x | y;
	if (med[x].w < med[y].w)
	{
		med[x].sz += med[y].sz;
		med[x].r = merge(med[x].r, y);
		return x;
	}
	else
	{
		med[y].sz += med[x].sz;
		med[y].l = merge(x, med[y].l);
		return y;
	}
}
void split(int x, int bentl, int &l, int &r)
{
	if (x == 0)
	{
		l = 0;
		r = 0;
		return;
	}
	if (bentl <= 0)
	{
		l = 0;
		r = x;
		return;
	}
	if (bentl >= med[x].sz)
	{
		l = x;
		r = 0;
		return;
	}
	if (med[med[x].l].sz >= bentl)
	{
		split(med[x].l, bentl, l, r);
		med[x].l = r;
		med[x].sz = med[x].k + med[med[x].l].sz + med[med[x].r].sz;
		r = x;
	}
	else
	{
		split(med[x].r, bentl - med[med[x].l].sz - med[x].k, l, r);
		med[x].r = l;
		med[x].sz = med[x].k + med[med[x].l].sz + med[med[x].r].sz;
		l = x;
	}
}
int getr(int x)
{
	if (x == 0)
		return 0;
	if (med[x].r == 0)
		return med[x].k;
	return getr(med[x].r);
}
void addr(int x, int val)
{
	if (x == 0)
		return;
	if (med[x].r == 0)
		med[x].k += val;
	med[x].sz += val;
	addr(med[x].r, val);
}
int getsz(int x)
{
	if (x == 0)
		return 0;
	return 1 + getsz(med[x].l) + getsz(med[x].r);
}
void print(int x)
{
	if (x == 0)
		return;
	print(med[x].l);
	cout << med[x].k << " ";
	print(med[x].r);
}
int main()
{
	med[0].sz = 0;
	F[0] = 1;
	for (int i = 1; i < 400009; i++)
	{
		F[i] = F[i - 1] * i;
		F[i] %= mod;
	}
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int x[m + 1], y[m + 1];
		for (int i = 1; i <= m; i++)
			cin >> x[i] >> y[i];
		int root = m > 0 ? make(x[1] - 1) : make(n);
		for (int i = 1; i <= m; i++)
		{
			if (i >= 2 && x[i - 1] < x[i] - 1)
				addr(root, x[i] - x[i - 1] - 1);
			int l, r;
			split(root, y[i], l, r);
			int sz1 = getr(l);
			int sz = med[l].sz;
			int del = sz - y[i];
			if (y[i] == sz - sz1 + 1 && y[i] != 1)
			{
				int l_;
				split(l, y[i] - 1, l, l_);
				addr(l, 1);
				root = merge(merge(l, l_), r);
			}
			else
			{
				addr(l, -del);
				root = merge(merge(l, make(del + 1)), r);
			}
		}
		cout << C(n * 2 - getsz(root), n) << "\n";
	}



}