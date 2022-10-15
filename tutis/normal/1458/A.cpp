/*input
4 4
1 25 121 169
1 2 7 23
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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	ll a0, g = 0;
	cin >> a0;
	n--;
	while (n--)
	{
		ll a;
		cin >> a;
		if (a != a0)
			g = __gcd(g, a0 - a);
	}
	while (m--)
	{
		ll x;
		cin >> x;
		cout << abs(__gcd(x + a0, g)) << " ";
	}
}