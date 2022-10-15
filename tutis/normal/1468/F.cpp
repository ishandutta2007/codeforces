/*input
3
2
0 0 0 1
1 0 2 0
3
0 0 1 1
1 1 0 0
1 0 2 0
6
0 0 0 1
1 0 1 2
2 0 2 3
3 0 3 -5
4 0 4 -5
5 0 5 -5

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
mt19937_64 rng(123);
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
		int n;
		cin >> n;
		map<pair<int, int>, int>M;
		ll ans = 0;
		while (n--)
		{
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			c -= a;
			d -= b;
			int g = abs(__gcd(c, d));
			c /= g;
			d /= g;
			ans += M[ { -c, -d}];
			M[ {c, d}]++;
		}
		cout << ans << "\n";
	}

}