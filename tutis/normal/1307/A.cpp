/*input
3
4 5
1 0 3 2
2 2
100 1
1 8
0

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
	ll t, n, d;
	cin >> t;
	while (t--) {
		cin >> n >> d;
		ll a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 1; i < n; i++)
		{
			ll k = min(a[i], d / i);
			a[i] -= k;
			a[0] += k;
			d -= k * i;
		}
		cout << a[0] << "\n";
	}
}