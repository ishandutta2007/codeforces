/*input
8
0 0 1
0 0 2
0 0 3
0 0 4
0 0 5
0 0 6
0 0 7
0 0 8
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x[1000], y[1000], r[1000];
vector<ll>adj[1000];
ll root[1000];
map<tuple<ll, ll, ll>, ll>M;
ll dp(ll i, ll a, ll b)
{
	if (M.count(make_tuple(i, a, b)))
		return M[make_tuple(i, a, b)];
	ll ret = -1e18;
	{
		ll gal = 0;
		if (a == 0)
			gal += r[i] * r[i];
		else
			gal -= r[i] * r[i];
		for (ll j : adj[i])
		{
			gal += dp(j, a ^ 1, b);
		}
		ret = max(ret, gal);
	}
	{
		ll gal = 0;
		if (b == 0)
			gal += r[i] * r[i];
		else
			gal -= r[i] * r[i];
		for (ll j : adj[i])
		{
			gal += dp(j, a, b ^ 1);
		}
		ret = max(ret, gal);
	}
	return M[make_tuple(i, a, b)] = ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	for (ll i = 0; i < n; i++)
		cin >> x[i] >> y[i] >> r[i];
	for (ll i = 0; i < n; i++)
	{
		pair<ll, ll>mn = {1e18, 1000};
		for (ll j = 0; j < n; j++)
		{
			if (r[j] > r[i] &&
			        (x[i] - x[j]) *
			        (x[i] - x[j]) +
			        (y[i] - y[j]) *
			        (y[i] - y[j]) < r[j] * r[j])
				mn = min(mn, {r[j], j});
		}
		ll j = mn.second;
		if (j != 1000)
		{
			adj[j].push_back(i);
			root[i] = 1;
		}
	}
	ll ans = 0;
	for (ll i = 0; i < n; i++)
		if (root[i] == 0)
		{
			ans += dp(i, 0, 0);
		}
	cout << fixed << setprecision(15) << (ans * acosl(-1)) << "\n";
}