/*input
4
5 2
00000
00111
1 5
1 3
2 1
00
01
1 2
10 6
1111111111
0110001110
1 10
5 9
7 10
1 7
3 5
6 10
5 2
10000
11000
2 5
1 3

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
//using ull = __uint128_t;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
mt19937_64 rng(123);
const ll mod = 1000000007;
struct ST
{
	int l, r;
	ST *left, *right;
	int setv;
	bool set = false;
	int sum;
	bool eq(const string&a)
	{
		fix();
		if (l == r)
			return sum == a[l] - '0';
		else
			return left->eq(a) && right->eq(a);
	}
	ST(int l, int r, const string&a): l(l), r(r)
	{
		if (l < r)
		{
			left = new ST(l, (l + r) / 2, a);
			right = new ST((l + r) / 2 + 1, r, a);
			sum = left->sum + right->sum;
		}
		else
			sum = a[l] - '0';
	}
	void fix()
	{
		if (set)
		{
			set = false;
			sum = (r - l + 1) * setv;
			if (l < r)
			{
				left->set = true;
				right->set = true;
				left->setv = setv;
				right->setv = setv;
			}
		}
	}
	void upd(int x, int y, int v)
	{
		if (set && v == setv)
			return fix();
		if (y < l || r < x)
			return fix();
		if (x <= l && r <= y)
		{
			set = true;
			setv = v;
			return fix();
		}
		fix();
		left->upd(x, y, v);
		right->upd(x, y, v);
		sum = left->sum + right->sum;
	}
	int get(int x, int y)
	{
		if (set)
		{
			if (setv == 0)
				return 0;
			y = min(y, r);
			x = max(x, l);
			return max(0, y - x + 1);
		}
		if (y < l || r < x)
			return 0;
		if (x <= l && r <= y)
			return sum;
		return left->get(x, y) + right->get(x, y);
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, q;
		cin >> n >> q;
		string s, f;
		cin >> s >> f;
		ST med(0, n - 1, f);
		int l[q], r[q];
		for (int i = 0; i < q; i++) {
			cin >> l[i] >> r[i];
			l[i]--;
			r[i]--;
		}
		bool ok = true;
		for (int i = q - 1; i >= 0; i--)
		{
			int k1 = med.get(l[i], r[i]);
			int k0 = (r[i] - l[i] + 1) - k1;
			if (k0 * 2 < k0 + k1)
			{
				med.upd(l[i], r[i], 1);
			}
			else if (k1 * 2 < k0 + k1)
			{
				med.upd(l[i], r[i], 0);
			}
			else
			{
				ok = false;
				break;
			}
		}
		ok &= med.eq(s);
		if (ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}