/*input
1 1

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
template<typename T>
using treee = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, p;
	cin >> n >> p;
	for (int k = 1; k <= 1000; k++)
	{
		ll sk = n - p * k;
		if (sk >= k && __builtin_popcount(sk) <= k)
		{
			cout << k << "\n";
			return 0;
		}
	}
	cout << "-1\n";
}