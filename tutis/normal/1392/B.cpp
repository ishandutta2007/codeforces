/*input
3
2 1
-199 192
5 19
5 -1 4 2 0
1 2
69

*/
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
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
		ll a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		if (k >= 8)
		{
			k %= 4;
			k += 4;
		}
		while (k > 0)
		{
			k--;
			ll d = *max_element(a, a + n);
			for (ll &i : a)
				i = d - i;
		}
		for (ll &i : a)
			cout << i << " ";
		cout << "\n";
	}


	return 0;
}