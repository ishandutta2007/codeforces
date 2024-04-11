/*input
3
10 4
12 6
179 822

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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		ll x, y;
		cin >> x >> y;
		if (x % y != 0)
		{
			cout << x << "\n";
		}
		else
		{
			ll ans = 1;
			vector<ll>P;
			ll Y = y;
			for (ll p = 2; p * p <= Y; p++)
			{
				if (Y % p == 0)
					P.push_back(p);
				while (Y % p == 0)
					Y /= p;
			}
			if (Y != 1)
				P.push_back(Y);
			for (ll p : P)
			{
				ll c = x;
				while (c % y == 0)
					c /= p;
				ans = max(ans, c);
			}
			cout << ans << "\n";
		}
	}
}