/*input
6
2
2 3 1 4
2
3 1 2 4
4
3 2 6 1 5 7 8 4
3
1 2 3 4 5 6
4
6 1 3 7 4 5 8 2
6
4 3 2 5 1 11 9 12 8 6 10 7

*/
#pragma GCC optimize ("O3")
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
		int p[2 * n];
		for (int i = 0; i < 2 * n; i++)
			cin >> p[i];
		int j = 2 * n - 1;
		vector<pair<int, pair<int, int>>>A;
		while (j >= 0)
		{
			pair<int, int>mx = { -1, -1};
			for (int i = 0; i <= j; i++)
				mx = max(mx, {p[i], i});
			A.push_back({j - mx.second + 1, {mx.second, j}});
			j = mx.second - 1;
		}
		vector<vector<bool>>DP((int)A.size() + 1, vector<bool>(n + 1, false));
		DP[0][0] = true;
		for (int i = 0; i < (int)A.size(); i++)
		{
			DP[i + 1] = DP[i];
			int sz = A[i].first;
			for (int t = 0; t + sz <= n; t++)
				DP[i + 1][t + sz] = DP[i + 1][t + sz] || DP[i][t];
		}
		if (DP[(int)A.size()][n])
		{
			cout << "YES\n";
		}
		else
			cout << "NO\n";
	}
	return 0;
}