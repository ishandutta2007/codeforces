/*input
4
5 7
1 2
2 3
3 4
4 5
5 1
1 3
3 5
4 4
1 2
2 3
1 4
3 4
6 7
1 2
1 3
3 4
4 5
1 4
5 6
6 2
2 1
1 2

*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using oset = tree<T,  null_type,  less<T>,  rb_tree_tag,  tree_order_statistics_node_update>;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937 rng(0);
const ll mod = 1e9 + 7;
ll power(ll x, ll y)
{
	if (abs(x) >= mod)
		x %= mod;
	if (x < 0)
		x += mod;
	if (abs(y) >= mod - 1)
		y %= mod - 1;
	if (y < 0)
		y += mod - 1;
	ll r = 1;
	while (y)
	{
		if (y % 2 == 1)
			r = (r * x) % mod;
		y /= 2;
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
		int pa[n + 1];
		for (int i = 0; i <= n; i++)
			pa[i] = i;
		int pa1[n + 1];
		for (int i = 0; i <= n; i++)
			pa1[i] = i;
		function<int(int)>root = [&](int x)
		{
			if (x == pa[x])
				return x;
			return pa[x] = root(pa[x]);
		};
		function<int(int)>root1 = [&](int x)
		{
			if (x == pa1[x])
				return x;
			return pa1[x] = root1(pa1[x]);
		};
		string s(m, '0');
		vector<pair<int, int>>e0[n + 1];
		vector<pair<int, int>>e1[n + 1];
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			//cout << u << " " << v << endl;
			if (root(u) == root(v))
			{
				s[i] = '1';
				// e1[u].push_back({v, i});
				// e1[v].push_back({u, i});
				if (root1(u) == root1(v))
				{
					for (auto ii : e0[u])
					{
						function<void(int, int)>dfs = [&](int i, int p)
						{
							//cout << i << " " << p << endl;
							if (i == v)
							{
								s[ii.second] = '1';
							}
							for (auto j : e0[i])
							{
								if (j.first != p)
								{
									dfs(j.first, i);
								}
							}
						};
						dfs(ii.first, u);
					}
					s[i] = '0';
				}
				pa1[root1(u)] = root1(v);
			}
			else
			{
				e0[u].push_back({v, i});
				e0[v].push_back({u, i});
			}
			pa[root(u)] = root(v);
		}
		cout << s << "\n";
	}
	return 0;
}