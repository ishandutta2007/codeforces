/*input
2
3 2
3 2
2 1
4 2
1 4
2 3

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
		int n, m;
		cin >> n >> m;
		vector<int>adj[n + 1];
		while (m--)
		{
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		vector<bool>d(n + 1, true);
		vector<bool>ok(n + 1, false);
		queue<int>Q;
		Q.push(1);
		ok[1] = true;
		vector<int>ans;
		while (!Q.empty())
		{
			int a = Q.front();
			Q.pop();
			if (d[a])
			{
				ans.push_back(a);
				for (int b : adj[a])
				{
					d[b] = false;
				}
			}
			for (int b : adj[a])
			{
				if (!ok[b])
				{
					ok[b] = true;
					Q.push(b);
				}
			}
		}
		bool ger = true;
		for (int i = 1; i <= n; i++)
			if (!ok[i])
				ger = false;
		if (ger)
		{
			cout << "YES\n" << ans.size() << "\n";
			for (int i : ans)
				cout << i << " ";
			cout << "\n";
		}
		else
			cout << "NO\n";
	}
}