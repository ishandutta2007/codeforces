/*input
5
1 1
1
2 1
1 2
3 1
1 2 1
4 2
1 4 3 1
5 2
5 1 2 4 3

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
		int n, q;
		cin >> n >> q;
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			a[i] -= q;
		}
		ST med(0, n - 1, a);
		set<int>B;
		int cnt = n;
		ll l[n], r[n];
		for (int i = 0; i < n; i++)
		{
			l[i] = -1;
			r[i] = -1;
		}
		pair<int, int>mx = { -10, -1};
		set<int>V;
		for (int t = 0;; t++)
		{
			pair<ll, int>v = med.mx;
			if (v.first > 0)
			{
				B.insert(v.second);
				med.add(v.second, v.second, -1e12);
				cnt--;
				l[v.second] = t;
				r[v.second] = 1e9;
			}
			else {
				mx = max(mx, {cnt, t});
				if (B.size() > 0 && (int)V.size() < q)
				{
					int i = *(--B.end());
					B.erase(--B.end());
					V.insert(i);
					med.add(i + 1, n, 1);
					cnt++;
					r[i] = t;
					if ((int)V.size() == q)
					{
						med.add((*(--V.end())) + 1, n, 1e10);
					}
				}
				else
					break;
			}
		}
		int t = mx.second;
		assert(t >= 0);
		string s(n, '1');
		for (int i = 0; i < n; i++)
		{
			if (l[i] <= t && t <= r[i])
				s[i] = '0';
		}
		cout << s << "\n";
	}
}