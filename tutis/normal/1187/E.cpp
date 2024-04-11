/*input
9
1 2
2 3
2 5
2 6
1 4
4 9
9 7
9 8

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll ans = 0;
ll sz[202020];
vector<ll>adj[202020];
ll suma = 0;
void dfs(ll i, ll p)
{
	sz[i] = 1;
	for (ll j : adj[i])
	{
		if (j == p)
			continue;
		dfs(j, i);
		sz[i] += sz[j];
	}
	suma += sz[i];
}
ll n;
void dfs1(ll i, ll p)
{
	ans = max(ans, suma);
	for (ll j : adj[i])
	{
		if (j == p)
			continue;
		suma -= sz[j];
		suma += (n - sz[j]);
		dfs1(j, i);
		suma += sz[j];
		suma -= (n - sz[j]);
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
	dfs(1, 1);
	dfs1(1, 1);
	cout << ans << "\n";
}