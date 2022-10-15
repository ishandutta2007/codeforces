/*input
5 3

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
	ll n, k;
	cin >> n >> k;
	set<ll>X;
	for (int i = 1; i <= k && i <= 100000; i++)
	{
		ll a = n % i;
		if (X.count(a))
		{
			cout << "No\n";
			return 0;
		}
		X.insert(a);
	}
	cout << "Yes\n";
	return 0;
}