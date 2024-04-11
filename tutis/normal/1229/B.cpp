/*input
7
0 2 3 0 0 0 0
1 2
1 3
2 4
2 5
3 6
3 7

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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll mod = 1000000007;
ll x[101010];
ll G(ll a, ll b)
{
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	return __gcd(a, b);
}
vector<int>adj[101010];
ll ans = 0;
deque<pair<ll, ll>>v[101010];
void dfs(int i, int p)
{
	if (i == p)
	{
		v[i] = {{x[i], 1}};
	}
	else
	{
		v[i] = v[p];
		v[i].push_back({x[i], 1});
		for (int t = 0; t < (int)v[i].size(); t++)
		{
			v[i][t].first = G(v[i][t].first, x[i]);
		}
		bool ok = true;
		while (ok)
		{
			ok = false;
			for (int t = 1; t < v[i].size(); t++)
			{
				if (v[i][t].first == v[i][t - 1].first)
				{
					v[i][t - 1].second += v[i][t].second;
					v[i].erase(v[i].begin() + t);
					ok = true;
				}
			}
		}
	}
	for (int t = 0; t < v[i].size(); t++)
	{
		ll x = v[i][t].first;
		ll y = v[i][t].second;
		x %= mod;
		y %= mod;
		ans += x * y;
		ans %= mod;
	}
	for (int j : adj[i])
	{
		if (j != p)
		{
			dfs(j, i);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> x[i];
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 1);
	cout << ans << "\n";
}