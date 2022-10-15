/*input
6
2 1
1 2
3 0
2 3 7
2 -1
31415926 27182818
2 1000000000000000000
1 1000000000000000000
2 -1000000000000000000
-1000000000000000000 123
6 80
-5 -20 13 -14 -2 -11
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
		ll k;
		cin >> n >> k;
		ll x[n];
		for (ll &i : x)
			cin >> i;
		ll g = abs(x[1] - x[0]);
		for (int i = 1; i < n; i++)
			g = __gcd(g, abs(x[i] - x[0]));
		bool ok = false;
		for (int i = 0; i < n; i++)
		{
			ll num = k - x[i];
			if (num % g == 0)
				ok = true;
		}
		if (ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}