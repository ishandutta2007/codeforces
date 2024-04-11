/*input
4
4 3
5 1 2 1
4 10
11 9 11 9
2 5
4 3
3 7
9 4 9

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
		ll n, x, sum = 0;
		cin >> n >> x;
		ll a[n];
		for (ll&i : a)
			cin >> i;
		sort(a, a + n, greater<ll>());
		ll ret = 0;
		ll kiek = 0;
		for (ll i : a)
		{
			sum += i;
			kiek++;
			if (sum >= x * kiek)
				ret = kiek;
		}
		cout << ret << "\n";
	}



	return 0;
}