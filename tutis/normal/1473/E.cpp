/*input
7 10
7 5 5
2 3 3
4 7 1
5 3 6
2 7 6
6 2 6
3 7 6
4 2 1
3 1 4
1 7 4

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
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>>adj[n + 1];
	while (m--)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	ll D[2][2][n + 1];
	bool buv[2][2][n + 1];
	for (int x = 0; x < 2; x++)
		for (int y = 0; y < 2; y++)
			for (int i = 1; i <= n; i++)
			{
				D[x][y][i] = 1e17;
				buv[x][y][i] = false;
			}
	D[0][0][1] = 0;
	priority_queue<pair<ll, int>>Q[2][2];
	Q[0][0].push({0, 1});
	for (int x = 0; x < 2; x++)
		for (int y = 0; y < 2; y++)
			while (!Q[x][y].empty())
			{
				int i = Q[x][y].top().second;
				Q[x][y].pop();
				if (buv[x][y][i])
					continue;
				buv[x][y][i] = true;
				for (pair<int, int>jj : adj[i])
				{
					int j = jj.first;
					int w = jj.second;
					for (int dx = 0; x + dx <= 1; dx++)
					{
						for (int dy = 0; y + dy <= 1; dy++)
						{
							ll s1 = D[x][y][i] + w * (1ll - dx + dy);
							if (D[x + dx][y + dy][j] > s1)
							{
								D[x + dx][y + dy][j] = s1;
								Q[x + dx][y + dy].push({ -s1, j});
							}
						}
					}
				}
			}
	for (int i = 2; i <= n; i++)
		cout << D[1][1][i] << " ";
}