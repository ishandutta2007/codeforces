/*input
7
4 2
5 7
3 4
6 3
1 3
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
	int kas[N + 1];
	for (int i = 1; i <= N; i++)
		kas[i] = i;
	int dist = 0;
	function<bool(int, int)>dfs = [&](int i, int p)->bool
	{
		int v = -1;
		vector<int>ch;
		for (int j : adj[i])
		{
			if (j == p)
				continue;
			if (!dfs(j, i))
			{
				ch.push_back(j);
			}
		}
		while (ch.size() >= 2)
		{
			int a = ch.back();
			ch.pop_back();
			int b = ch.back();
			ch.pop_back();
			swap(kas[a], kas[b]);
			dist += 4;
			if (kas[i] == i)
				swap(kas[i], kas[a]);
		}
		if (ch.size() == 1)
		{
			dist += 2;
			swap(kas[ch[0]], kas[i]);
		}
		return kas[i] != i;
	};
	if (!dfs(1, 1))
	{
		dist += 2;
		swap(kas[1], kas[adj[1][0]]);
	}
	cout << dist << "\n";
	for (int i = 1; i <= N; i++)
		cout << kas[i] << " ";
	return 0;
}