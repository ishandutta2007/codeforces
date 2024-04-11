/*input
3
3 5
1 2
3 4
2 1000000000
1 1
999999999 999999999
10 3
5 10
7 8

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename K>
using ordered_map = tree<T, K, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		ll n, k;
		cin >> n >> k;
		ll l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		if (l1 > l2)
		{
			swap(l1, l2);
			swap(r1, r2);
		}
		ll l = max(l1, l2);
		ll r = min(r1, r2);
		ll dab = max(0ll, r - l) * n;
		k -= dab;
		if (k <= 0)
		{
			cout << "0\n";
			continue;
		}
		ll ans = 1e18;
		for (ll c = 1; c <= n; c++)
		{
			ll bendr = max(0ll, l2 - r1);
			ll x = bendr * c;
			ll k1 = (max(r1, r2) - min(l1, l2) - max(0ll, r - l)) * c;
			k1 = min(k1, k);
			x += k1;
			x += (k - k1) * 2;
			ans = min(ans, x);
		}
		cout << ans << "\n";
	}


	return 0;
}