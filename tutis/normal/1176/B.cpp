/*input
2
5
3 1 2 3 1
7
1 1 1 1 1 2 2

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
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int k[3] = {0, 0, 0};
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			k[a % 3]++;
		}
		int ans = k[0];
		while (k[1] > 0 && k[2] > 0)
		{
			k[1]--;
			k[2]--;
			ans++;
		}
		ans += k[1] / 3;
		ans += k[2] / 3;
		cout << ans << "\n";
	}



}