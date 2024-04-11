/*input
5
(?))
??????
()
??
?(?)()?)

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
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		int bal = 0;
		int cnt = 0;
		for (char c : s) {
			if (c == '(')
				bal++;
			else if (c == ')')
				bal--;
			else
				cnt++;
		}
		//kp+km=cnt
		//kp-km=-bal
		int kp = (cnt - bal) / 2;
		int km = (cnt + bal) / 2;
		if (kp >= 1 && km >= 1)
		{
			bool ok = true;
			int bal = 0;
			for (char c : s) {
				if (c == '(')
					bal++;
				else if (c == ')')
					bal--;
				else
				{
					if (kp > 1)
					{
						kp--;
						bal++;
					}
					else if (kp == 1)
					{
						kp--;
						bal--;
					}
					else if (kp == 0)
					{
						kp--;
						bal++;
					}
					else
					{
						bal--;
					}
				}
				ok &= bal >= 0;
			}
			if (ok)
				cout << "NO\n";
			else
				cout << "YES\n";
		}
		else
		{
			cout << "YES\n";
		}
	}
}