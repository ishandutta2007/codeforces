/*input
3
1 2
2 -1 1

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
	int n;
	cin >> n;
	int p[n + 1];
	vector<int>c[n + 1];
	for (int i = 2; i <= n; i++)
	{
		cin >> p[i];
		c[p[i]].push_back(i);
	}
	int s[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	ll ans = s[1];
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == -1)
		{
			ll sum = -s[p[i]];
			ll d = 1;
			//ans+=x-s[p[i]];
			int mn = 1e9 + 100;
			for (int j : c[i])
			{
				if (s[j] < s[p[i]])
				{
					cout << "-1\n";
					return 0;
				}
				//ans+=s[j]-x
				sum += s[j];
				d--;
				mn = min(mn, s[j]);
			}
			if (d <= 0)
				ans += d * mn + sum;
		}
	}
	cout << ans << "\n";
}