/*input
3
5 9 4
1 2
1 3
1 4
1 5
2 3
2 4
2 5
3 4
3 5
10 15 3
1 2
2 3
3 4
4 5
5 1
1 7
2 8
3 9
4 10
5 6
7 10
10 8
8 6
6 9
9 7
4 5 4
1 2
2 3
3 4
4 1
1 3

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
		int n, m, k;
		cin >> n >> m >> k;
		vector<int>adj[n + 1];
		while (m--)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int d[n + 1];
		for (int i = 1; i <= n; i++)
		{
			d[i] = (int)adj[i].size();
			sort(adj[i].begin(), adj[i].end());
		}
		queue<int>Q;
		for (int i = 1; i <= n; i++)
			if (d[i] < k)
			{
				Q.push(i);
			}
		vector<int>clique;
		while (!Q.empty())
		{
			int a = Q.front();
			Q.pop();
			d[a] = -1;
			vector<int>gal = {a};
			for (int b : adj[a])
			{
				if (d[b] != -1)
				{
					d[b]--;
					gal.push_back(b);
					if (d[b] == k - 1)
					{
						Q.push(b);
					}
				}
			}
			if (clique.empty())
				if (gal.size() == k)
				{
					bool ok = true;
					for (int i : gal)
					{
						for (int j : gal)
						{
							if (i <= j)
								continue;
							if (binary_search(adj[i].begin(), adj[i].end(), j) == false)
								ok = false;
							if (!ok)
								break;
						}
						if (!ok)
							break;
					}
					if (ok)
					{
						clique = gal;
					}
				}
		}
		vector<int>ans;
		for (int i = 1; i <= n; i++)
			if (d[i] > 0)
				ans.push_back(i);
		if (!ans.empty())
		{
			cout << 1 << " " << ans.size() << "\n";
			for (int i : ans)
				cout << i << " ";
			cout << "\n";
		}
		else
		{
			if (!clique.empty())
			{
				cout << 2 << "\n";
				for (int i : clique)
					cout << i << " ";
				cout << "\n";
			}
			else
				cout << "-1\n";
		}
	}
}