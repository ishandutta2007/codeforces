/*input
5
2 2
10
01
3 3
011
101
110
4 4
1111
0110
0110
1111
5 5
01011
11001
00010
11011
10000
2 3
011
101
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
const ll mod = 1000000007;
ll power(ll x, ll p)
{
	x %= mod;
	if (x < 0)
		x += mod;
	ll r = 1;
	while (p)
	{
		if (p % 2 == 1)
			r = (r * x) % mod;
		p /= 2;
		x = (x * x) % mod;
	}
	return r;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		string s[n];
		for (int i = 0; i < n; i++)
			cin >> s[i];
		vector<vector<int>>ans;
		while (n > 2)
		{
			int i = n - 1;
			for (int j = 0; j < m; j++)
			{
				if (s[i][j] == '1')
				{
					s[i][j] ^= '0'^'1';
					s[i - 1][j] ^= '0'^'1';
					int j1 = j - 1;
					if (j == 0)
						j1 = j + 1;
					s[i - 1][j1] ^= '0'^'1';
					ans.push_back({i, j, i - 1, j, i - 1, j1});
				}
			}
			n--;
		}
		while (m > 2)
		{
			int j = m - 1;
			for (int i = 0; i < n; i++)
			{
				if (s[i][j] == '1')
				{
					s[i][j] ^= '0'^'1';
					s[i][j - 1] ^= '0'^'1';
					int i1 = i - 1;
					if (i == 0)
						i1 = i + 1;
					s[i1][j - 1] ^= '0'^'1';
					ans.push_back({i, j, i, j - 1, i1, j - 1});
				}
			}
			m--;
		}
		for (int t = 0; t < (1 << 4); t++)
		{
			bool ok = true;
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					char c = '0';
					int k = i + j * 2;
					for (int k1 = 0; k1 < 4; k1++)
					{
						if (k1 != k && (t & (1 << k1)) != 0)
						{
							c ^= '0'^'1';
						}
					}
					if (c != s[i][j])
						ok = false;
				}
			}
			if (ok)
			{
				for (int k1 = 0; k1 < 4; k1++)
				{
					if ((t & (1 << k1)) != 0)
					{
						vector<int>xx;
						for (int i = 0; i < 2; i++)
						{
							for (int j = 0; j < 2; j++)
							{
								int k = i + j * 2;
								if (k1 != k)
								{
									xx.push_back(i);
									xx.push_back(j);
								}
							}
						}
						ans.push_back(xx);
					}
				}
				break;
			}
		}

		cout << ans.size() << "\n";
		for (auto i : ans)
		{
			for (int j : i)
				cout << j + 1 << " ";
			cout << "\n";
		}
	}
}