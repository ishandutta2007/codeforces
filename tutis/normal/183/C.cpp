/*input
5 2
1 4
2 5

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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int>adj[n + 1];
	vector<int>atg[n + 1];
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		atg[b].push_back(a);
	}
	vector<bool>vis(n + 1, false);
	vector<int>dd(n + 1, 0);
	function<int(int, int)>dfs = [&](int a, int d)
	{
		vis[a] = true;
		dd[a] = d;
		for (int b : adj[a])
		{
			if (!vis[b])
			{
				int x = dfs(b, d + 1);
				if (x != 0)
					return x;
			}
			else
			{
				if (dd[b] != d + 1)
					return abs(dd[b] - (d + 1));
			}
		}
		for (int b : atg[a])
		{
			if (!vis[b])
			{
				int x = dfs(b, d - 1);
				if (x != 0)
					return x;
			}
			else
			{
				if (dd[b] != d - 1)
					return abs(dd[b] - (d - 1));
			}
		}
		return 0;
	};
	int x = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			x = dfs(i, 1);
			if (x != 0)
				break;
		}
	}
	if (x == 0)
		x = n;
	for (int a = n; a >= 1; a--)
	{
		if ((x % a) == 0)
		{
			int c[n + 1];
			fill_n(c, n + 1, 0);
			bool ok = true;
			for (int i = 1; i <= n; i++)
			{
				if (c[i] == 0)
				{
					c[i] = 1;
					queue<int>Q;
					Q.push(i);
					while (!Q.empty())
					{
						int aa = Q.front();
						Q.pop();
						for (int b : adj[aa])
						{
							int cc = c[aa] + 1;
							if (cc == a + 1)
								cc = 1;
							if (c[b] == 0)
							{
								c[b] = cc;
								Q.push(b);
							}
							else if (c[b] != cc)
								ok = false;
						}
						for (int b : atg[aa])
						{
							int cc = c[aa] - 1;
							if (cc == 0)
								cc = a;
							if (c[b] == 0)
							{
								c[b] = cc;
								Q.push(b);
							}
							else if (c[b] != cc)
								ok = false;
						}
					}
				}
			}
			if (ok)
			{
				cout << a << "\n";
				return 0;
			}
		}
	}
	return 0;
}