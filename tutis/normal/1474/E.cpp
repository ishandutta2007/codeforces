/*input
3
2
3
4

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
		int p[n + 1];
		for (int i = 1; i <= n; i++)
			p[i] = i;
		vector<pair<int, int>>ans;
		ans.push_back({1, n});
		swap(p[1], p[n]);
		for (int i = 2; i < n; i++)
		{
			if (abs(i - 1) > abs(i - n))
			{
				swap(p[i], p[1]);
				ans.push_back({i, 1});
			}
			else
			{
				swap(p[i], p[n]);
				ans.push_back({i, n});
			}
		}
		reverse(ans.begin(), ans.end());
		ll s = 0;
		for (auto i : ans)
		{
			ll x = i.first - i.second;
			s += x * x;
		}
		cout << s << "\n";
		for (int i = 1; i <= n; i++)
			cout << p[i] << " ";
		cout << "\n";
		cout << ans.size() << "\n";
		for (auto i : ans)
			cout << i.first << " " << i.second << "\n";
	}
}