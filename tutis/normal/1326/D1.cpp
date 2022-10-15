/*input
5
a
abcdfdcecba
abbaxyzyx
codeforces
acbba
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
bool dp[5000][5000];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		int n = s.size();
		int kiek = 0;
		while ((kiek + 1) * 2 <= n + 1)
		{
			if (s[kiek] == s[n - kiek - 1])
			{
				kiek++;
			}
			else
				break;
		}
		string ans;
		ans.push_back(s[0]);
		for (int sz = 1; sz <= n; sz++)
		{
			for (int l = 0; l + sz - 1 < n; l++)
			{
				int r = l + sz - 1;
				if (sz == 1)
				{
					dp[l][r] = true;
				}
				else if (sz == 2)
				{
					dp[l][r] = s[l] == s[r];
				}
				else
				{
					dp[l][r] = dp[l + 1][r - 1] & (s[l] == s[r]);
				}
				if (dp[l][r])
				{
					if (l <= kiek)
					{
						int sz = r - l + 1 + 2 * (l);
						if (sz > (int)ans.size() && sz <= n)
						{
							ans = s.substr(0, r + 1) + s.substr(n - l, l);
						}
					}
					if (r >= n - kiek - 1)
					{
						int sz = r - l + 1 + 2 * (n - r - 1);
						if (sz > (int)ans.size() && sz <= n)
						{
							ans = s.substr(0, n - r - 1) + s.substr(l, n - l);
						}
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}