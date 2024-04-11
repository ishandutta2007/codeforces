/*input
5
1 2
2 3
3 4
4 5
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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int N;
	cin >> N;
	vector<int>adj[N + 1];
	for (int i = 1; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int sz[N + 1];
	ll dist = 0;
	vector<int>ord;
	function<void(int, int)>dfs = [&](int i, int p)->void
	{
		ord.push_back(i);
		sz[i] = 1;
		for (int j : adj[i])
		{
			if (j == p)
				continue;
			dfs(j, i);
			sz[i] += sz[j];
		}
		dist += min(sz[i], N - sz[i]) * 2;
	};
	dfs(1, 1);
	int kur[N + 1];
	for (int i = 0; i < ord.size(); i++)
		kur[ord[i]] = i;
	cout << dist << "\n";
	for (int i = 1; i <= N; i++)
		cout << ord[(kur[i] + N / 2) % N] << " ";
	return 0;
}