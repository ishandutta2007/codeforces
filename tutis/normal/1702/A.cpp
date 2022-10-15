/*input
7
1
2
178
20
999999999
9000
987654321

*/

#pragma GCC optimize ("O3")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using oset = tree<T,  null_type,  less<T>,  rb_tree_tag,  tree_order_statistics_node_update>;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937_64 rng(0);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		ll m;
		cin >> m;
		ll ans = m;
		for (int x = 1; x <= m; x = x * 10)
		{
			ans = min(ans, m - x);
		}
		cout << ans << "\n";
	}
}