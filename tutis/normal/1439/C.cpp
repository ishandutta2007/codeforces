/*input
10 6
10 10 10 6 6 5 5 5 3 1
2 3 50
2 4 10
1 3 10
2 2 36
1 4 7
2 2 17

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
using ull = unsigned long long;
using ll = long long;
using ld = long double;
const ll mod = 1000000007;
ll power(ll x, ll p)
{
	x %= mod;
	if (x < 0)
		x += mod;
	ll r = 1;
	while (p)
	{
		if (p % 2 == 1)
			r = (r * x) % mod;
		p /= 2;
		x = (x * x) % mod;
	}
	return r;
}
struct ST
{
	ll l, r;
	ST *left = NULL, *right = NULL;
	ll sum;
	ll setv = -1;
	ll mx, mn;
	ST(const vector<int>&a, int l, int r): l(l), r(r)
	{
		if (l < r)
		{
			left = new ST(a, l, (l + r) / 2);
			right = new ST(a, (l + r) / 2 + 1, r);
			sum = left->sum + right->sum;
			mx = left->mx;
			mn = right->mn;
		}
		else
		{
			sum = mx = mn = a[l];
		}
	}
	void fix()
	{
		if (setv != -1)
		{
			if (l < r)
			{
				left->setv = setv;
				right->setv = setv;
			}
			sum = setv * (r - l + 1);
			mx = mn = setv;
			setv = -1;
		}
	}
	void set(ll x, ll y, int v)
	{
		if (r < x || y < l)
			return fix();
		if (x <= l && r <= y)
		{
			setv = v;
			return fix();
		}
		else
		{
			fix();
			left->set(x, y, v);
			right->set(x, y, v);
			sum = left->sum + right->sum;
			mx = left->mx;
			mn = right->mn;
		}
	}
	pair<ll, ll> get(ll x, ll suma)
	{
		fix();
		if (x > (l + r) / 2)
			return right->get(x, suma);
		if (suma < mn)
			return {0, suma};
		x = max(x, l);
		assert(x <= r);
		if (x == l)
		{
			if (suma >= sum)
			{
				return {r - l + 1, suma - sum};
			}
		}
		pair<ll, ll>a = left->get(x, suma);
		pair<ll, ll>b = right->get(x, a.second);
		return {a.first + b.first, b.second};
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, q;
	cin >> n >> q;
	vector<int>a(n);
	for (int &i : a)
		cin >> i;
	ST medis(a, 0, n - 1);
	map<int, int>M;
	M[-1] = 1000000001;
	M[n] = -1;
	for (int i = 0; i < n; i++)
		M[i] = a[i];
	while (q--)
	{
		ll t, x, y;
		cin >> t >> x >> y;
		x--;
		if (t == 1)
		{
			auto it = M.lower_bound(x);
			if (it->second < y)
			{
				M[x] = y;
				while (true)
				{
					auto it = M.find(x);
					it--;
					if (it->second <= y)
					{
						M.erase(it);
					}
					else
						break;
				}
				auto it = M.find(x);
				it--;
				medis.set(it->first + 1, x, y);
			}
		}
		else
			cout << medis.get(x, y).first << "\n";
	}


}