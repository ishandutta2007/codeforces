/*input
7
5
acbac
8
acabacba
12
aaaaaaaaaaaa
10
abacabadac
8
dcbaabcd
3
cba
6
sparky

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
//using ull = __ull128_t;
using ull = unsigned long long;
using ll = long long;
using ld = double;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename T>
void sort_unique(T x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
//const ll mod = 998244353;
int a[5000][5000];
int dp[5000][5000];
int m[5000][5000];
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
		string s;
		cin >> s;
		s.push_back(0);
		int ans = n;
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = n - 1; j >= 0; j--)
			{
				if (s[i] == s[j])
				{
					if ((i == n - 1) || j == (n - 1))
						a[i][j] = 1;
					else
						a[i][j] = 1 + a[i + 1][j + 1];
				}
				else
				{
					a[i][j] = 0;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				dp[i][j] = j - i + 1;
				m[i][j] = 0;
			}
			for (int j = 0; j < i; j++)
			{
				if (i + a[i][j] < n && s[i + a[i][j]] > s[j + a[i][j]])
					dp[i][i + a[i][j]] = max(dp[i][i + a[i][j]], dp[j][n - 1] + 1);
			}
			vector<int>x = {0};
			for (int j = 1; j <= i; j++)
			{
				if (a[i][j] > a[i][x.back()])
					x.push_back(j);
			}
			int id = 0;
			for (int j = i; j < n; j++)
			{
				if (j > i)
					dp[i][j] = max(dp[i][j], m[x[id]][j - i - 1] + 1);
				while (a[i][x[id]] < j - i + 1)
					id++;
				m[x[id]][j - i] = max(m[x[id]][j - i], dp[i][j]);
			}
			ans = max(ans, dp[i][n - 1]);
		}
		cout << ans << "\n";
	}
}