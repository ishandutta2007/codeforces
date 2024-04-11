/*input
4
0101
1000
0001
1010

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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll ans[1 << 13];
vector<ll>dp[1 << 14][14];
int G[14][14];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
			G[i][j] = s[j] == '1';
	}
	for (int msk = 0; msk < (1 << n); msk++)
		for (int x = 0; x < n; x++)
		{
			if ((msk & (1 << x)) != 0)
				continue;
			vector<int>Y;
			for (int i = 0; i < n; i++)
			{
				if ((msk & (1 << i)) != 0)
					Y.push_back(i);
			}
			dp[msk][x] = vector<ll>(1 << Y.size(), 0);
			if (Y.empty())
			{
				dp[msk][x][0] = 1;
			}
			else
			{
				for (int y : Y)
				{
					int msk1 = msk ^ (1 << y);
					int d = G[y][x] << (Y.size() - 1);
					for (int i = 0; i < (1 << (Y.size() - 1)); i++)
					{
						dp[msk][x][i + d] += dp[msk1][y][i];
					}
				}
			}
		}
	for (int x = 0; x < n; x++)
	{
		int msk = ((1 << n) - 1) ^ (1 << x);
		for (int i = 0; i < (1 << (n - 1)); i++)
			ans[i] += dp[msk][x][i];
	}
	for (int i = 0; i < (1 << (n - 1)); i++)
		cout << ans[i] << " ";
	cout << "\n";
	return 0;
}