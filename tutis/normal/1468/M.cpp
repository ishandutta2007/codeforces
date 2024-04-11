/*input
3
4
2 1 10
3 1 3 5
5 5 4 3 2 1
3 10 20 30
3
4 1 2 3 4
4 2 3 4 5
4 3 4 5 6
2
3 1 3 5
3 4 3 2
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
mt19937_64 rng(123);
const ll mod = 1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		map<int, vector<int>>M;
		set<int>A;
		set<int>B;
		int tim = 0;
		for (int i = 1; i <= n; i++)
		{
			int k;
			cin >> k;
			while (k--)
			{
				int x;
				cin >> x;
				M[x].push_back(i);
			}
		}
		vector<pair<int, vector<int>>>MM;
		for (auto i : M)
			MM.push_back(i);
		vector<int>t;
		vector<bool>cnt(n + 1, false);
		vector<vector<int>>VV(n + 1);
		for (auto i : MM)
		{
			if (i.second.size() >= 170)
			{
				t.push_back(i.first);
			}
			else
			{
				for (int v : i.second)
				{
					for (int w : i.second)
					{
						if (w >= v)
							break;
						VV[v].push_back(w);
					}
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			sort(VV[i].begin(), VV[i].end());
			for (int t = 1; t < VV[i].size(); t++)
			{
				if (VV[i][t] == VV[i][t - 1])
				{
					cout << i << " " << VV[i][t] << "\n";
					goto E;
				}
			}
		}
		for (int i : t)
		{
			for (int v : M[i])
				cnt[v] = true;
			for (auto jj : MM)
			{
				int j = jj.first;
				if (i == j)
					continue;
				int c1 = -1;
				for (int v : jj.second)
				{
					if (cnt[v])
					{
						if (c1 == -1)
							c1 = v;
						else
						{
							cout << c1 << " " << v << "\n";
							goto E;
						}
					}
				}
			}
			for (int v : M[i])
				cnt[v] = false;
		}
		cout << "-1\n";
E:;
	}
}