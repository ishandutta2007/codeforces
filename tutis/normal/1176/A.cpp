/*input
7
1
10
25
30
14
27
1000000000000000000

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename A, typename B>
using hash_set = cc_hash_table<A, B>;
typedef long long ll;
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--)
	{
		ll n;
		cin >> n;
		int ans = 0;
		while (n % 2 == 0)
		{
			n /= 2;
			ans++;
		}
		while (n % 3 == 0)
		{
			n /= 3;
			ans += 2;
		}
		while (n % 5 == 0)
		{
			n /= 5;
			ans += 3;
		}
		if (n == 1)
			cout << ans << "\n";
		else
			cout << "-1\n";
	}



}