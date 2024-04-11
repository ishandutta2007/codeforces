/*input
5 4
2 1
2 3
4 3
4 5

*/
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const ll mod = 998244353;
const ll c = 26;
ll power(ll x, ll y)
{
	if (y == 0)
		return 1;
	if (y == 1)
		return x;
	if (y % 2 == 0)
	{
		x = power(x, y / 2);
		x = x * x;
		x %= mod;
		return x;
	}
	else
	{
		ll a = power(x, y - 1);
		x *= a;
		x %= mod;
		return x;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m;
	cin >> n >> m;
	// n = 36;
	// m = n - 1;
	vector<ll>adj[2][n + 1];
	for (int i = 0; i < m; i++)
	{
		ll u, v;
		// u = i + 1;
		// v = i + 2;
		// if (i % 2 == 0)
		// {
		// 	swap(u, v);
		// }
		cin >> u >> v;
		adj[0][u].push_back(v);
		adj[1][v].push_back(u);
	}
	ll dp[n + 1][c + 2];
	pair<ll, ll> dp1[n + 1][2];
	for (ll i = 0; i <= n; i++)
	{
		for (ll j = 0; j < c + 2; j++)
		{
			dp[i][j] = 1e18;
		}
		dp1[i][0] = {n + 100, 0};
		dp1[i][1] = {n + 100, 0};
	}
	dp[1][0] = 0;
	for (ll d = 0; d <= c; d++)
	{
		priority_queue<pair<ll, ll>>Q;
		for (ll i = 1; i <= n; i++)
			Q.push({ -dp[i][d], i});
		vector<bool>buv(n + 1, false);
		while (!Q.empty())
		{
			ll x = Q.top().second;
			Q.pop();
			if (buv[x])
				continue;
			buv[x] = true;
			for (ll y : adj[d % 2][x])
			{
				if (dp[y][d] > dp[x][d] + 1)
				{
					dp[y][d] = dp[x][d] + 1;
					Q.push({ -dp[y][d], y});
				}
			}
		}
		for (ll i = 1; i <= n; i++)
		{
			dp[i][d + 1] = dp[i][d] + (1ll << d);
		}
	}
	priority_queue<pair<pair<ll, ll>, pair<ll, ll>>>Q;
	for (ll i = 1; i <= n; i++)
	{
		if (dp[i][c] < 1e17)
		{
			dp1[i][0] = {c, dp[i][c] - ((1ll << c) - 1)};
			Q.push({{ -dp1[i][0].first, -dp1[i][0].second}, {i, 0}});
		}
		if (dp[i][(c - 1)] < 1e17)
		{
			dp1[i][1] = {c - 1, dp[i][(c - 1)] - ((1ll << (c - 1)) - 1)};
			Q.push({{ -dp1[i][1].first, -dp1[i][1].second}, {i, 1}});
		}
	}
	vector<vector<bool>>buv(2, vector<bool>(n + 1, false));
	while (!Q.empty())
	{
		ll i = Q.top().second.first;
		ll d2 = Q.top().second.second;
		Q.pop();
		if (buv[d2][i])
			continue;
		buv[d2][i] = true;
		for (ll j : adj[d2][i])
		{
			pair<ll, ll>x = dp1[i][d2];
			x.second++;
			if (dp1[j][d2] > x)
			{
				dp1[j][d2] = x;
				Q.push({{ -dp1[j][d2].first, -dp1[j][d2].second}, {j, d2}});
			}
		}
		pair<ll, ll>x = dp1[i][d2];
		x.first++;
		ll d1 = 1 - d2;
		if (dp1[i][d1] > x)
		{
			dp1[i][d1] = x;
			Q.push({{ -dp1[i][d1].first, -dp1[i][d1].second}, {i, d1}});
		}
	}

	ll ret = 1e18;
	for (ll i = 0; i <= c; i++)
		ret = min(ret, dp[n][i]);
	if (ret > 1e17)
	{
		if (dp1[n][0] < dp1[n][1])
		{
			ll x = dp1[n][0].first;
			ll y = dp1[n][0].second;
			ret = power(2, x) - 1 + y;
		}
		else
		{
			ll x = dp1[n][1].first;
			ll y = dp1[n][1].second;
			ret = power(2, x) - 1 + y;
		}
	}
	ret %= mod;
	if (ret < 0)
		ret += mod;
	cout << ret << "\n";
}