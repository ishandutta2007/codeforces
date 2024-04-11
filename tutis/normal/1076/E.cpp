/*input
5
2 3
2 1
5 4
3 4
5
2 0 4
3 10 1
1 2 3
2 3 10
1 1 7
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<ll>adj[400000];
ll atimt[400000];
ll answ[400000];
ll n;
vector<pair<ll, ll>>Q[400000];
void dfs(ll i, ll p, ll carry, ll d)
{
	for (pair<ll, ll>j : Q[i])
	{
		ll x = j.second;
		ll D = j.first + d + 1;
		D = min(D, 303000ll);
		carry += x;
		atimt[D] += x;
	}
	carry -= atimt[d];
	answ[i] = carry;
	for (ll j : adj[i])
	{
		if (j == p)
			continue;
		dfs(j, i, carry, d + 1);
	}
	for (pair<ll, ll>j : Q[i])
	{
		ll x = j.second;
		ll D = j.first + d + 1;
		D = min(D, 303000ll);
		carry -= x;
		atimt[D] -= x;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (ll i = 1; i < n; i++)
	{
		ll x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	ll m;
	cin >> m;
	while (m--)
	{
		ll v, d, x;
		cin >> v >> d >> x;
		Q[v].push_back({d, x});
	}
	fill_n(atimt, 400000, 0);
	dfs(1, 1, 0, 0);
	for (ll i = 1; i <= n; i++)
		cout << answ[i] << " ";
	cout << "\n";
}