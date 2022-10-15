/*input
4
6 5
1 2 -1
1 3 1
4 2 7
6 3 0
2 5 -1
2 3 1
2 5 0
5 6 1
6 1 1
4 5 1
5 3
1 2 -1
1 3 -1
1 4 1
4 5 -1
2 4 0
3 4 1
2 3 1
3 3
1 2 -1
1 3 -1
1 2 0
1 3 1
2 3 0
2 1
1 2 1
1 2 0

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
//using ull = __ull128_t;
using ull = unsigned long long;
using ll = long long;
using ld = double;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename T>
void sort_unique(T &x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
//const ll mod = 998244353;
const ll mod = 1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<pair<int, int>>adj[n + 1];
		vector<pair<int, int>>adj1[n + 1];
		for (int i = 1; i < n; i++)
		{
			int x, y, v;
			cin >> x >> y >> v;
			adj[x].push_back({y, v});
			adj[y].push_back({x, v});
			if (v >= 0)
			{
				int c = __builtin_popcount(v);
				c %= 2;
				adj1[x].push_back({y, c});
				adj1[y].push_back({x, c});
			}
		}
		bool ok = true;
		while (m--)
		{
			int a, b, p;
			cin >> a >> b >> p;
			adj1[a].push_back({b, p});
			adj1[b].push_back({a, p});
		}
		vector<bool>vis(n + 1, false);
		vector<int>par(n + 1, 0);
		for (int i = 1; i <= n; i++)
		{
			if (vis[i] == false)
			{
				stack<int>S;
				S.push(i);
				par[i] = 0;
				vis[i] = true;
				while (!S.empty())
				{
					int x = S.top();
					S.pop();
					for (pair<int, int>y : adj1[x])
					{
						if (vis[y.first])
						{
							ok &= (par[y.first] == (par[x] ^ y.second));
						}	
						else
						{
							vis[y.first] = true;
							par[y.first] = par[x] ^ y.second;
							S.push(y.first);
						}
					}
				}
			}
		}
		if (ok)
		{
			cout << "YES\n";
			for (int i = 1; i <= n; i++)
			{
				for (auto j : adj[i])
				{
					if (j.first < i)
					{
						if (j.second == -1)
							j.second = par[i] ^ par[j.first];
						cout << i << " " << j.first << " " << j.second << "\n";
					}
				}
			}
		}
		else
		{
			cout << "NO\n";
		}
	}
}