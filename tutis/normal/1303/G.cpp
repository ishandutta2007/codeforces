/*input
4
4 2
3 2
4 1
1 3 3 7
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int>adj[n + 1];
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	ll a[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	vector<int>V;
	int sz[n + 1];
	int mx[n + 1];
	function<void(int, int)>dfs = [&](int i, int p)
	{
		V.push_back(i);
		sz[i] = 1;
		mx[i] = 0;
		for (int j : adj[i])
		{
			if (j == p)
				continue;
			dfs(j, i);
			sz[i] += sz[j];
			mx[i] = max(mx[i], sz[j]);
		}
	};
	ll ret = 0;
	function<void(int)>ans = [&](int v)
	{
		V.clear();
		dfs(v, v);
		int n = V.size();
		pair<int, int>mn = {n + 1, v};
		for (int i : V)
		{
			mx[i] = max(mx[i], n - sz[i]);
			mn = min(mn, {mx[i], i});
		}
		v = mn.second;
		ret = max(ret, a[v]);
		vector<pair<ll, ll>>A;
		vector<pair<ll, ll>>B;
		function<void(int, int, ll, ll, ll)>dfs1 = [&](int i, int p, ll s, ll ss, ll k)
		{
			s += a[i];
			ss += a[i] * k;
			int kiek = 0;
			for (int j : adj[i])
			{
				if (j == p)
					continue;
				dfs1(j, i, s, ss, k + 1);
				kiek++;
			}
			if (kiek == 0)
			{
				A.push_back({s + a[v], ss + s + a[v]});
				ret = max(ret, ss + s + a[v]);
				ret = max(ret, (s + a[v]) * (k + 2) - (ss + s + a[v]));
				ret = max(ret, ss);
				ss = s * (k + 1) - ss;
				ret = max(ret, ss);
				B.push_back({ss, k});
			}
		};
		vector<vector<pair<ll, ll>>>AA;
		vector<vector<pair<ll, ll>>>BB;
		shuffle(adj[v].begin(), adj[v].end(), rng);
		for (int u : adj[v])
		{
			A.clear();
			B.clear();
			dfs1(u, v, 0, 0, 1);
			AA.push_back(A);
			BB.push_back(B);
		}
		for (int t = 0; t < 2; t++)
		{
			ll my = 0;
			ll mx = 0;
			for (int i = 0; i < (int)AA.size(); i++)
			{
				for (pair<ll, ll>a : AA[i])
				{
					if (a.first * my + a.second + mx > ret)
						for (int j = 0; j < i; j++)
						{
							for (pair<ll, ll>b : BB[j])
							{
								ret = max(ret, b.first + b.second * a.first + a.second);
							}
						}
				}
				for (pair<ll, ll>b : BB[i])
				{
					mx = max(mx, b.first);
					my = max(my, b.second);
				}
			}
			if (t == 0)
			{
				reverse(AA.begin(), AA.end());
				reverse(BB.begin(), BB.end());
			}
		}
		for (int u : adj[v])
		{
			adj[u].erase(find(adj[u].begin(), adj[u].end(), v));
			ans(u);
		}
	};
	ans(1);
	cout << ret << "\n";
	return 0;
}