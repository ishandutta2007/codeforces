/*input
13 30
6 4
25 5 1
7 1 2
9 4 2
10 2 1
12 3 1
5 2 3
10 9 6
2 1 1
5 3 9
10 2 10
10 9 6
3 2 11
*/
#pragma GCC optimize ("O3")
//#pragma GCC target ("avx2")
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
const int mod = 1000000007;
const int inf = 200008;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, b;
	cin >> n >> b;
	int c[n + 1], d[n + 1];
	vector<int>ch[n + 1];
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i] >> d[i];
		if (i >= 2)
		{
			int x;
			cin >> x;
			ch[x].push_back(i);
		}
	}
	int dp[2][n + 1][n + 1];
	int sz[n + 1];
	for (int i = n; i >= 1; i--)
	{
		sz[i] = 1;
		dp[0][i][0] = 0;
		dp[0][i][1] = c[i];
		dp[1][i][0] = b + 1;
		dp[1][i][1] = c[i] - d[i];
		for (int j = 2; j <= n; j++)
			dp[0][i][j] = dp[1][i][j] = b + 1;
		sort(ch[i].begin(), ch[i].end(), [&](int x, int y) {return sz[x] > sz[y];});
		for (int j : ch[i])
		{
			for (int xy = sz[j] + sz[i]; xy > 0; xy--)
			{
				for (int y = min(xy, sz[j]); y >= 0 && xy - y <= sz[i]; y--)
				{
					int x = xy - y;
					dp[0][i][x + y] = min(dp[0][i][x + y], dp[0][i][x] + dp[0][j][y]);
					dp[1][i][x + y] = min(dp[1][i][x + y], dp[1][i][x] + dp[1][j][y]);
				}
			}
			sz[i] += sz[j];
		}
		for (int j = 0; j <= n; j++)
			dp[1][i][j] = min(dp[0][i][j], dp[1][i][j]);
	}
	int ans = 0;
	for (int a = 1; a <= n; a++)
		if (dp[1][1][a] <= b)
			ans = a;
	cout << ans << "\n";
}