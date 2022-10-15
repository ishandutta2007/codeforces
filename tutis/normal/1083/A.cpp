/*input
5
6 3 2 5 0
1 2 10
2 3 3
2 4 1
1 5 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll w[300000 + 1];
vector<pair<ll, ll>>adj[300000 + 1];
ll ans = 0;
ll MX[300000 + 1];
void dfs(ll i, ll p)
{
	MX[i] = w[i];
	for (pair<ll, ll> j : adj[i])
	{
		if (j.first == p)
			continue;
		dfs(j.first, i);
		if (MX[j.first] - j.second >= 0)
			MX[i] = max(MX[i], w[i] + MX[j.first] - j.second);
	}
	ans = max(ans, MX[i]);
}
ll GAL[300000 + 1];
ll dfs1(ll i, ll p)
{
	GAL[i] = w[i];
	vector<pair<ll, ll>>M = {{w[i], -1}};
	for (pair<ll, ll> j : adj[i])
	{
		if (j.first == p)
			continue;
		dfs1(j.first, i);
		if (MX[j.first] - j.second >= 0)
			M.push_back({MX[j.first] - j.second + w[i], j.first});
	}
	sort(M.begin(), M.end(), greater<pair<ll, ll>>());
	while (M.size() > 3)
		M.pop_back();
	for (pair<ll, ll> j : adj[i])
	{
		if (j.first == p)
			continue;
		for (pair<ll, ll> k : M)
		{
			if (k.second == j.first)
				continue;
			if (k.first - j.second >= 0)
				GAL[j.first] = max(GAL[j.first], k.first - j.second + w[j.first]);
		}
	}
}
void dfs2(ll i, ll p)
{
	ans = max(ans, GAL[i]);
	for (pair<ll, ll> j : adj[i])
	{
		if (j.first == p)
			continue;
		if (GAL[i] - j.second >= 0)
			GAL[j.first] = max(GAL[j.first], GAL[i] - j.second + w[j.first]);
		dfs2(j.first, i);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	for (ll i = 1; i <= n; i++)
		cin >> w[i];
	for (ll i = 1; i < n; i++)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	dfs(1, 1);
	dfs1(1, 1);
	dfs2(1, 1);
	cout << ans << '\n';
}