/*input
6
4
1 2
4 3
2 1
3 4
6
1 2
4 5
1 3
4 6
2 3
5 6
2
1 1
2 2
2
1 2
2 1
8
2 1
1 2
4 3
4 3
5 6
5 7
8 6
7 8
8
1 2
2 1
4 3
5 3
5 4
6 7
8 6
7 8

*/

#pragma GCC optimize ("O3")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using oset = tree<T,  null_type,  less<T>,  rb_tree_tag,  tree_order_statistics_node_update>;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937_64 rng(0);
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
		vector<int>C(n + 1, 0);
		int id[n + 1];
		bool ok = true;
		vector<int>adj[n];
		for (int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			if (C[a] == 1)
			{
				adj[i].push_back(id[a]);
				adj[id[a]].push_back(i);
			}
			if (C[b] == 1)
			{
				adj[i].push_back(id[b]);
				adj[id[b]].push_back(i);
			}
			C[a]++;
			C[b]++;
			if (a == b)
				ok = false;
			if (C[a] == 3 || C[b] == 3)
				ok = false;
			id[a] = i;
			id[b] = i;
		}
		if (!ok)
		{
			cout << "NO\n";
		}
		else
		{
			vector<bool>vis(n, false);
			vector<bool>col(n, false);
			bool ok = true;
			for (int i = 0; i < n; i++)
			{
				if (vis[i] == false)
				{
					vector<int>V = {i};
					while (!V.empty())
					{
						int a = V.back();
						V.pop_back();
						for (int b : adj[a])
						{
							if (vis[b] == false)
							{
								vis[b] = true;
								col[b] = !col[a];
								V.push_back(b);
							}
							else if (col[a] == col[b])
								ok = false;
						}
					}
				}
			}
			if (!ok)
			{
				cout << "NO\n";
			}
			else
				cout << "YES\n";
		}
	}
}