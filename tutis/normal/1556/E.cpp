/*input
8 5
0 1 2 9 3 2 7 5
2 2 1 9 4 1 5 8
2 6
1 7
2 4
7 8
5 8

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
void sort_unique(T &x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
//const ll mod = 998244353;
const ll mod = 1000000007;
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
const ll inf = 1e17;
struct ST
{
	int l, r;
	ll mn, mx;
	ST *left, *right;
	ST(int l, int r, ll a[]): l(l), r(r)
	{
		if (l < r)
		{
			left = new ST(l, (l + r) / 2, a);
			right = new ST((l + r) / 2 + 1, r, a);
			mn = min(left->mn, right->mn);
			mx = max(left->mx, right->mx);
		}
		else
		{
			mn = mx = a[l];
		}
	}
	pair<ll, ll>get(int x, int y)
	{
		if (r < x || y < l)
			return {inf, -inf};
		if (x <= l && r <= y)
			return {mn, mx};
		pair<ll, ll>a = left->get(x, y);
		pair<ll, ll>b = right->get(x, y);
		return {min(a.first, b.first), max(a.second, b.second)};
	};
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	ll a[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		int b;
		cin >> b;
		a[i] -= b;
	}
	ll sum[n + 1];
	sum[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + a[i];
	}
	ST medis(1, n, sum);
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		if ((sum[r] - sum[l - 1]) != 0)
		{
			cout << "-1\n";
		}
		else
		{
			pair<ll, ll>x = medis.get(l, r);
			x.first -= sum[l - 1];
			x.second -= sum[l - 1];
			//cout << l << " " << r << " " << x.first << " " << x.second << endl;
			if (x.second > 0)
			{
				cout << "-1\n";
			}
			else
				cout << -x.first << "\n";
		}
	}
}