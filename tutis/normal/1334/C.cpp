/*input
1
3
7 15
2 14
5 3

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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		ll a[n], b[n];
		for (int i = 0; i < n; i++)
			cin >> a[i] >> b[i];
		ll c[n];
		for (int i = 0; i < n; i++)
			c[i] = max(0ll, a[i] - b[(i + n - 1) % n]);
		ll suma = 0;
		for (int i = 0; i < n; i++)
			suma += c[i];

		ll ans = 2e18;
		for (int i = 0; i < n; i++)
			ans = min(ans, suma - c[i] + a[i]);
		cout << ans << "\n";
	}



	return 0;
}