/*input
4
5 4 0
1 5 4 3 2
5 4 1
1 5 4 3 2
5 4 4
10 20 30 40 50
10 7 3
4 6 8 2 9 9 7 4 10 9

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
		int n, k, z;
		cin >> n >> k >> z;
		ll a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		ll ans = 0;
		for (int c = 0; c <= z; c++)
		{
			if (c * 2 <= k)
			{
				int kiek = k - 2 * c;
				ll sum = a[0];
				ll mx = a[kiek] + a[kiek + 1];
				for (int i = 1; i <= kiek; i++)
				{
					sum += a[i];
					mx = max(mx, a[i] + a[i - 1]);
				}
				sum += mx * c;
				ans = max(ans, sum);
			}
		}
		cout << ans << "\n";
	}


	return 0;
}