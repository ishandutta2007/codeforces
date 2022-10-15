/*input
3
2:3,2
1:1-1:3
2:1,2

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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	int cnt[n + 1];

	set<int>*R[n + 1][n + 1];
	set<set<int>>L[n + 1];
	for (int i = 1; i <= n; i++)
	{
		int kiek = 0;
		cnt[i] = 0;
		while (kiek < n - 1)
		{
			char xx;
			if (kiek != 0)
				cin >> xx;
			cnt[i]++;
			set<int>*aaa = new set<int>();
			int c;
			cin >> c;
			kiek += c;
			while (c--)
			{
				cin >> xx;
				int j;
				cin >> j;
				aaa->insert(j);
				R[i][j] = aaa;
			}
			L[i].insert(*aaa);
		}
	}
	vector<pair<int, int>>ans;
	vector<int>adj[n + 1];
	for (int t = 0; t + 1 < n; t++)
	{
		bool ok1 = false;
		for (int i = 1; i <= n; i++)
			if (cnt[i] == 1)
			{
				cnt[i] = -1;
				ok1 = true;
				int kiek = 0;
				for (int j = 1; j <= n; j++)
				{
					if (j != i)
						if (R[j][i]->size() == 1)
						{
							adj[i].push_back(j);
							adj[j].push_back(i);
							kiek++;
							ans.push_back({i, j});
						}
				}
				if (kiek != 1)
				{
					cout << "-1\n";
					return 0;
				}
				for (int j = 1; j <= n; j++)
				{
					if (j != i)
					{
						if (R[j][i]->count(i))
						{
							R[j][i]->erase(i);
							if (R[j][i]->empty())
								cnt[j]--;
						}
					}
				}
				for (int j = 1; j <= n; j++)
					if (i != j)
						R[i][j]->clear();
				break;
			}
		if (!ok1)
		{
			cout << "-1\n";
			return 0;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j : adj[i])
		{
			set<int>LL;
			function<void(int, int)>dfs = [&](int v, int p)
			{
				LL.insert(v);
				for (int w : adj[v])
				{
					if (w != p)
						dfs(w, v);
				}
			};
			dfs(j, i);
			if (L[i].count(LL) == 0)
			{
				cout << "-1\n";
				return 0;
			}
		}
	}
	cout << ans.size() << "\n";
	for (auto i : ans)
		cout << i.first << " " << i.second << "\n";
}