/*input
5
4
RLRL
6
LRRRRL
8
RLLRRRLL
12
LLLLRRLRRRLL
5
RRRRR

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
bool ger[2][2][2];
int main()
{
	ger[0][1][0] = true;

	ger[0][0][1] = true;
	ger[0][1][1] = true;

	ger[1][0][1] = true;

	ger[1][0][0] = true;
	ger[1][1][0] = true;
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		int a[n];
		for (int i = 0; i < n; i++)
			if (s[i] == 'L')
				a[i] = 0;
			else
				a[i] = 1;
		int ans = n + 1000;
		for (int fi : {0, 1})
		{
			for (int se : {0, 1})
			{
				int dp[n][2][2];
				for (int i = 0; i < n; i++)
					for (int x : {0, 1})
						for (int y : {0, 1})
							dp[i][x][y] = n + 10000;
				dp[1][fi][se] = 0;
				if (a[0] != fi)
					dp[1][fi][se]++;
				if (a[1] != se)
					dp[1][fi][se]++;
				for (int i = 2; i < n; i++)
				{
					for (int x : {0, 1})
						for (int y : {0, 1})
						{
							for (int z : {0, 1})
							{
								if (ger[z][x][y])
								{
									int kiek = dp[i - 1][z][x];
									if (a[i] != y)
										kiek++;
									dp[i][x][y] = min(dp[i][x][y], kiek);
								}
							}
						}
				}
				for (int lst : {0, 1})
				{
					for (int lst1 : {0, 1})
					{
						if (ger[lst1][lst][fi] && ger[lst][fi][se])
						{
							ans = min(ans, dp[n - 1][lst1][lst]);
						}
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}