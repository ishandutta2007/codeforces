/*input
5
1 2
1 3
1 4
3 5

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1000000007;
ll dp[3001][3001];
ll d[3001][3001];
ll x[3001][3001];
vector<ll>adj[3001];
vector<pair<ll, ll>>A[3030];
ll n;
ll sz[3001][3001];
void dfs(ll i, ll p, ll id)
{
	sz[id][i] = 1;
	if (id < i)
		A[d[id][i]].push_back({id, i});
	for (ll j : adj[i])
	{
		if (j == p)
			continue;
		x[id][j] = i;
		d[id][j] = d[id][i] + 1;
		dfs(j, i, id);
		sz[id][i] += sz[id][j];
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (ll i = 1; i < n; i++)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (ll i = 1; i <= n; i++)
	{
		dfs(i, i, i);
	}
	for (ll d = 1; d <= n; d++)
	{
		for (auto uv : A[d])
		{
			ll u = uv.first;
			ll v = uv.second;
			ll val = max(dp[u][x[u][v]], dp[v][x[v][u]]);
			val += sz[u][v] * sz[v][u];
			dp[u][v] = dp[v][u] = val;
		}
	}
	ll ans = 0;
	for (ll i = 1; i <= n; i++)
		for (ll j = i + 1; j <= n; j++)
			ans = max(ans, dp[i][j]);
	cout << ans << "\n";
}