/*input
3
5
1 2 3 4 5
5
4 4 4 4 2
6
1 3 1 5 3 1
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
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int ans[n + 1];
		fill_n(ans, n + 1, -1);
		map<int, vector<int>>M;
		for (int i = 0; i < n; i++)
			M[a[i]].push_back(i);
		for (auto c : M)
		{
			int a_i = c.first;
			vector<int>v = c.second;
			int x = max(v[0] + 1, n - v.back());
			for (int t = 1; t < v.size(); t++)
				x = max(x, v[t] - v[t - 1]);
			if (ans[x] == -1)
				ans[x] = a_i;
			ans[x] = min(ans[x], a_i);
		}
		for (int i = 2; i <= n; i++)
		{
			if (ans[i - 1] != -1)
			{
				if (ans[i] == -1 || ans[i - 1] <= ans[i])
					ans[i] = ans[i - 1];
			}
		}
		for (int i = 1; i <= n; i++)
			cout << ans[i] << " ";
		cout << "\n";
	}
	return 0;
}