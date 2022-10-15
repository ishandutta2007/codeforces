/*input
4
2 4
1 3
3 12
3 4 5
1 5
5
2 10
15 4

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
template<typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		ll n, x;
		cin >> n >> x;
		ll ans = x + 10;
		ll a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (a[i] > x)
			{
				ans = min(ans, 2ll);
			}
			if (a[i] <= x)
			{
				if (x % a[i] == 0)
					ans = min(ans, x / a[i]);
				else
					ans = min(ans, x / a[i] + 1);
			}
		}
		cout << ans << "\n";
	}
}