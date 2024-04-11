/*input
2
1
00
11
01
3
011001
111010
010001
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
//using ull = __uint128_t;
using ull = unsigned long long;
using ll = long long;
using ld = double;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename T>
void sort_unique(T x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
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
		string a[3];
		cin >> a[0] >> a[1] >> a[2];
		auto check = [&](string x)
		{
			int cnt = 0;
			for (string i : a)
			{
				int id = 0;
				bool ok = true;
				for (char c : i)
				{
					while (id < x.size() && x[id] != c)
					{
						id++;
					}
					if (id < x.size())
					{
						id++;
					}
					else
					{
						ok = false;
						break;
					}
				}
				if (ok)
					cnt++;
			}
			if (cnt >= 2)
			{
				cout << x << "\n";
				return true;
			}
			else
				return false;
		};
		while (true)
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (i == j)
						continue;
					for (char c : {'0', '1'})
					{
						int k0 = 0;
						int k1 = 0;
						string test;
						while (k0 < 2 * n && k1 < 2 * n)
						{
							if (a[i][k0] == a[j][k1])
							{
								test.push_back(a[i][k0]);
								k0++;
								k1++;
							}
							else if (a[i][k0] != c)
							{
								test.push_back(a[i][k0]);
								k0++;
							}
							else
							{
								test.push_back(a[j][k1]);
								k1++;
							}
						}
						while (k0 < 2 * n)
						{
							test.push_back(a[i][k0]);
							k0++;
						}
						while (k1 < 2 * n)
						{
							test.push_back(a[j][k1]);
							k1++;
						}
						if (test.size() <= 3 * n)
						{
							cout << test << "\n";
							goto X;
						}
					}
				}
			}
		assert(false);
X:;
	}
}