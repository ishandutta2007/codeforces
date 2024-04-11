/*input
4
1 2
1 3
1 4

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
vector<ll>adj[202020];
ll sz[202020];
ll F[202020];
ll k[202020];
ll dfs(ll i, ll p)
{
	sz[i] = 1;
	vector<ll>v;
	ll ans = 1;
	for (ll j : adj[i])
	{
		if (j == p)
			continue;
		k[i]++;
		v.push_back(dfs(j, i));
		ans *= v.back();
		ans %= mod;
		ans *= (k[j] + 1);
		ans %= mod;
		sz[i] += sz[j];
	}
	ans *= F[v.size()];
	ans %= mod;
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	F[0] = 1;
	for (ll i = 1; i <= n + 5; i++)
		F[i] = (i * F[i - 1]) % mod;
	for (ll i = 1; i < n; i++)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	ll ans = dfs(1, 1);
	ans *= n;
	ans %= mod;
	cout << ans << "\n";
	return 0;
}