/*input
6 4 10
1
2
1
4
4
3 4 5
4 7 2
5 4 1
6 9 3
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 1e5 + 100;
const ll MAXK = 1000 + 20;
ll tim[MAXN];
ll val[MAXN];
ll p[MAXN];
vector<ll>child[MAXN];
map<ll, ll>*dp[MAXN];
map<ll, ll>* merge(map<ll, ll> &a, map<ll, ll> &b)
{
	if (b.size() > a.size())
		swap(a, b);
	for (auto it : b)
	{
		if (a.count(it.first))
			a[it.first] += it.second;
		else
			a[it.first] = it.second;
	}
	return &a;
}
void dfs(ll i)
{
	dp[i] = new map<ll, ll>();
	for (ll j : child[i])
	{
		dfs(j);
		dp[i] = merge(*dp[i], *dp[j]);
	}
	ll suma = 0;
	map<ll, ll>&M = *dp[i];
	vector<pair<ll, ll>>s;
	auto it = M.upper_bound(tim[i]);
	while (it != M.end())
	{
		s.push_back({it->first, it->second});
		suma += it->second;
		if (suma >= val[i])
			break;
		it++;
	}
	if (suma <= val[i])
	{
		for (auto i : s)
			M.erase(i.first);
	}
	else if (suma > val[i])
	{
		for (ll t = 0; t + 1 < s.size(); t++)
		{
			M.erase(s[t].first);
		}
		M[s.back().first] = suma - val[i];
	}
	if (M.count(tim[i]) == 0)
		M[tim[i]] = 0;
	M[tim[i]] += val[i];
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, m, k;
	cin >> n >> m >> k;
	p[1] = 1;
	for (ll i = 2; i <= n; i++)
	{
		cin >> p[i];
		child[p[i]].push_back(i);
	}
	while (m--)
	{
		ll v, d, w;
		cin >> v >> d >> w;
		tim[v] = d;
		val[v] = w;
	}
	map<ll, ll>x;
	for (ll i = 1; i <= n; i++)
		x[tim[i]] = 0;
	x[k] = 0;
	ll timer = 0;
	for (auto&i : x)
	{
		i.second = timer++;
	}
	for (ll i = 1; i <= n; i++)
		tim[i] = x[tim[i]];
	dfs(1);
	ll suma = 0;
	for (auto it : (*dp[1]))
		suma += it.second;
	cout << suma << "\n";
}