/*input
5
3
1 2 1
3
1 1 2
5
2 2 2 1 3
5
2100 1900 1600 3000 1600
2
2443 2445

*/
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using ordered_map = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using fast_map = cc_hash_table<T, X>;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
mt19937_64 rng(123);
const ll mod = 1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n + 2];
		a[0] = a[n + 1] = 0;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		int dp[n + 2];
		int dpr[n + 2];
		dp[0] = 0;
		dpr[n + 1] = 0;
		for (int i = 1; i <= n; i++)
		{
			dp[i] = a[i] - dp[i - 1];
			if (dp[i - 1] < 0)
				dp[i] = -1;
		}
		for (int i = n; i >= 1; i--)
		{
			dpr[i] = a[i] - dpr[i + 1];
			if (dpr[i + 1] < 0)
				dpr[i] = -1;
		}
		bool ok = false;
		for (int i = 1; i + 1 <= n; i++)
		{
			for (int r = 0; r < 2; r++)
			{
				swap(a[i], a[i + 1]);
				int a_[4] = {dp[i - 1], a[i], a[i + 1], dpr[i + 2]};
				if (a_[0] >= 0 && a_[3] >= 0)
				{
					a_[1] -= a_[0];
					a_[2] -= a_[3];
					if (a_[1] >= 0 && a_[1] == a_[2])
						ok = true;
				}
			}
		}
		cout << (ok ? "YES" : "NO") << "\n";
	}
}