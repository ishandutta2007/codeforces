/*input
4
3 1
2 3
3 2
2 1
1 2
5 3
2 3
3 1
1 2
5 4
4 5
5 1
2 2
3 3

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
ll power(ll x, ll p)
{
	x %= mod;
	if (x < 0)
		x += mod;
	ll r = 1;
	while (p)
	{
		if (p % 2 == 1)
			r = (r * x) % mod;
		p /= 2;
		x = (x * x) % mod;
	}
	return r;
}
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
		int ans = 0;
		multiset<int>adj[n + 1];
		while (m--)
		{
			int x, y;
			cin >> x >> y;
			if (x != y)
			{
				adj[x].insert(y);
				adj[y].insert(x);
			}
		}
		queue<int>Q;
		for (int i = 1; i <= n; i++)
		{
			if ((int)adj[i].size() == 1)
				Q.push(i);
			while (!Q.empty())
			{
				int i = Q.front();
				Q.pop();
				ans++;
				assert(adj[i].size() == 1);
				int j = *adj[i].begin();
				adj[i].erase(j);
				adj[j].erase(i);
				if ((int)adj[j].size() == 1)
					Q.push(j);
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if ((int)adj[i].size() > 1)
			{
				assert(adj[i].size() == 2);
				queue<int>Q;
				Q.push(i);
				ans++;
				while (!Q.empty())
				{
					int i = Q.front();
					Q.pop();
					for (int j : adj[i])
					{
						adj[j].erase(adj[j].find(i));
						ans++;
						Q.push(j);
					}
					adj[i].clear();
				}
			}
		}
		cout << ans << "\n";
	}

}