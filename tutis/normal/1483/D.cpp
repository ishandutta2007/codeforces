/*input
4 2
1 2 10
3 4 10
6
1 2 11
1 3 11
1 4 11
2 3 11
2 4 11
3 4 9

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
mt19937_64 rng(456456);
template<typename T>
void sort_unique(T x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
const ll mod = 1000000007;
int D[601][601];
int d[601][601];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<pair<int, pair<int, int>>>E;
	for (int i = 1; i <= 600; i++)
	{
		for (int j = 1; j <= 600; j++)
			d[i][j] = (int)1e9 + 2;
		d[i][i] = 0;
	}
	while (m--)
	{
		int u, v, w;
		cin >> u >> v >> w;
		d[u][v] = d[v][u] = min(w, d[u][v]);
		E.push_back({w, {u, v}});
	}
	int q;
	cin >> q;
	while (q--)
	{
		int u, v, l;
		cin >> u >> v >> l;
		D[u][v] = D[v][u] = l;
	}

	for (int k = 1; k <= 600; k++)
		for (int i = 1; i <= 600; i++)
			for (int j = 1; j <= 600; j++)
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];
	for (int k = 1; k <= 600; k++)
		for (int i = 1; i <= 600; i++)
			for (int j = 1; j <= 600; j++)
			{
				if (D[k][j] < D[i][j] - d[i][k])
				{
					D[k][j] = D[j][k] = D[i][j] - d[i][k];
				}
			}
	for (int k = 1; k <= 600; k++)
		for (int i = 1; i <= 600; i++)
			for (int j = 1; j <= 600; j++)
			{
				if (D[k][j] < D[i][j] - d[i][k])
				{
					D[k][j] = D[j][k] = D[i][j] - d[i][k];
				}
			}
	int ans = 0;
	for (auto i : E)
	{
		if (i.first <= D[i.second.first][i.second.second])
			ans++;
	}
	cout << ans << "\n";
}