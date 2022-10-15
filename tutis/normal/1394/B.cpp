/*input
6 13 4
3 5 1
2 5 2
6 3 3
1 4 4
2 6 5
5 3 6
4 1 7
4 3 8
5 2 9
4 2 10
2 1 11
6 1 12
4 6 13

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
vector<pair<int, int>>adj[202020];
ll A[10][10];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	while (m--)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({w, v});
	}
	ll w[n + 1];
	ll sum = 0;
	for (int i = 1; i <= n; i++)
	{
		w[i] = rng();
		sum += w[i];
	}
	for (int i = 1; i <= n; i++)
	{
		sort(adj[i].begin(), adj[i].end());
		int x = (int)adj[i].size() - 1;
		for (int j = 0; j <= x; j++)
		{
			int v = adj[i][j].second;
			A[x][j] += w[v];
		}
	}
	ll ans = 0;
	int c[10];
	for (c[0] = 0; c[0] <= 0; c[0]++)
	{
		sum -= A[0][c[0]];
		for (c[1] = 0; c[1] <= 1; c[1]++)
		{
			sum -= A[1][c[1]];
			for (c[2] = 0; c[2] <= 2; c[2]++)
			{
				sum -= A[2][c[2]];
				for (c[3] = 0; c[3] <= 3; c[3]++)
				{
					sum -= A[3][c[3]];
					for (c[4] = 0; c[4] <= 4; c[4]++)
					{
						sum -= A[4][c[4]];
						for (c[5] = 0; c[5] <= 5; c[5]++)
						{
							sum -= A[5][c[5]];
							for (c[6] = 0; c[6] <= 6; c[6]++)
							{
								sum -= A[6][c[6]];
								for (c[7] = 0; c[7] <= 7; c[7]++)
								{
									sum -= A[7][c[7]];
									for (c[8] = 0; c[8] <= 8; c[8]++)
									{
										sum -= A[8][c[8]];
										if (sum == 0)
											ans++;
										sum += A[8][c[8]];
									}
									sum += A[7][c[7]];
								}
								sum += A[6][c[6]];
							}
							sum += A[5][c[5]];
						}
						sum += A[4][c[4]];
					}
					sum += A[3][c[3]];
				}
				sum += A[2][c[2]];
			}
			sum += A[1][c[1]];
		}
		sum += A[0][c[0]];
	}
	for (int i = 9; i > k; i--)
		ans /= i;
	cout << ans << "\n";
	return 0;
}