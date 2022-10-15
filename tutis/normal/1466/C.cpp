/*input
7
babba
abaac
codeforces
zeroorez
abcdcba
bbbbbbb
a

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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1000000007;
int dp[100000][2][2];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		int n = s.size();
		for (int id = 0; id < n; id++)
			for (int i = 0; i < 2; i++)
				for (int j = 0; j < 2; j++)
					dp[id][i][j] = n + 1000;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
			{
				dp[0][i][j] = j;
			}
		for (int i = 1; i < n; i++)
		{
			for (int a = 0; a < 2; a++)
			{
				char l1 = '*';
				if (i >= 2 && a == 0)
					l1 = s[i - 2];
				for (int b = 0; b < 2; b++)
				{
					char l2 = '&';
					if (b == 0)
						l2 = s[i - 1];
					for (int c = 0; c < 2; c++)
					{
						char l3 = '2';
						if (c == 0)
							l3 = s[i];
						if (l3 != l2 && l3 != l1 && l2 != l1)
						{
							dp[i][b][c] = min(dp[i][b][c], dp[i - 1][a][b] + c);
						}
					}
				}
			}
		}
		int ans = n;
		for (int a = 0; a < 2; a++)
			for (int b = 0; b < 2; b++)
				ans = min(ans, dp[n - 1][a][b]);
		cout << ans << "\n";
	}
}