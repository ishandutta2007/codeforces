/*input
11 10
9 0 0 10 3 4 8 11 10 8
6
1 2 1 3 1
1 2 1 3 2
4 3 4 5 2
5 3 11 5 3
5 3 11 5 2
11 9 9 10 1

*/

#pragma GCC optimize ("O3")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using oset = tree<T,  null_type,  less<T>,  rb_tree_tag,  tree_order_statistics_node_update>;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1e9 + 7;
ll power(ll x, ll y)
{
	if (abs(x) >= mod)
		x %= mod;
	if (x < 0)
		x += mod;
	if (abs(y) >= mod - 1)
		y %= mod - 1;
	if (y < 0)
		y += mod - 1;
	ll r = 1;
	while (y != 0)
	{
		if (y % 2 == 1)
			r = (r * x) % mod;
		x = (x * x) % mod;
		y /= 2;
	}
	return r;
}
struct ST
{
	int l, r;
	pair<ll, int> mx;
	ll lazy = 0;
	ST *left;
	ST *right;
	ST(int l, int r, int* a): l(l), r(r)
	{
		if (l < r)
		{
			left = new ST(l, (l + r) / 2, a);
			right = new ST((l + r) / 2 + 1, r, a);
			mx = max(left->mx, right->mx);
		}
		else
		{
			mx = {a[l], l};
		}
	}
	void fix()
	{
		mx.first += lazy;
		if (lazy != 0 && l < r)
		{
			left->lazy += lazy;
			right->lazy += lazy;
		}
		lazy = 0;
	}
	pair<int, int>get(int x, int y)
	{
		if (y < l || r < x)
			return { -1e18, -1};
		fix();
		if (x <= l && r <= y)
			return mx;
		return max(left->get(x, y), right->get(x, y));
	}
	void add(int x, int y, ll val)
	{
		if (y < l || r < x)
			return fix();
		if (x <= l && r <= y)
		{
			lazy += val;
			fix();
		}
		else
		{
			fix();
			left->add(x, y, val);
			right->add(x, y, val);
			mx = max(left->mx, right->mx);
		}
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	int a[m + 1];
	for (int i = 1; i <= m; i++)
		cin >> a[i];
	ST med(1, m, a);
	int q;
	cin >> q;
	while (q--)
	{
		int x1, y1, x2, y2, k;
		cin >> x1 >> y1 >> x2 >> y2 >> k;
		int c1 = (n - x1) / k;
		int c2 = (n - x2) / k;
		x1 += c1 * k;
		x2 += c2 * k;
		if (x1 != x2 || ((y1 % k) != (y2 % k)))
		{
			cout << "NO\n";
		}
		else
		{
			if (y1 > y2)
				swap(y1, y2);
			if (med.get(y1, y2).first < x1)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}