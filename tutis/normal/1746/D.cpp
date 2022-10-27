/*input
2
5 4
1 2 1 3
6 2 1 5 7
5 3
1 2 1 3
6 6 1 4 10
*/
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
mt19937 rng(0);
const ll mod = 1e9 + 7;
ll power(ll x, ll y)
{
	y %= mod - 1;
	x %= mod;
	if (x < 0)
		x += mod;
	if (y < 0)
		y += mod - 1;
	ll r = 1;
	while (y)
	{
		if (y % 2)
			r = (r * x) % mod;
		x = (x * x) % mod;
		y /= 2;
	}
	return r;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll t;
	cin >> t;
	while (t--)
	{
		ll n, k;
		cin >> n >> k;
		vector<ll> c[n + 1];
		for (ll i = 2; i <= n; i++)
		{
			ll p;
			cin >> p;
			c[p].push_back(i);
		}
		ll s[n + 1];
		for (ll i = 1; i <= n; i++)
			cin >> s[i];
		function<pair<ll, ll>(ll, ll)>dp = [&](ll i, ll k)->pair<ll, ll>
		{
			ll cnt = (ll)c[i].size();
			if (cnt == 0)
				return {k * s[i], (k + 1) * s[i]};
			ll a = k / cnt;
			ll v = k % cnt;
			vector<pair<ll, ll>>V;
			for (ll j : c[i])
				V.push_back(dp(j, a));
			pair<ll, ll>ret = {k * s[i], (k + 1) * s[i]};
			sort(V.begin(), V.end(), [&](pair<ll, ll>a, pair<ll, ll>b) {
				return a.first - a.second < b.first - b.second;
			});
			for (ll i = 0; i < V.size(); i++)
			{
				ret.first += V[i].first;
				ret.second += V[i].first;
			}
			for (ll i = 0; i < v; i++)
				ret.first += V[i].second - V[i].first;
			for (ll i = 0; i < v + 1; i++)
				ret.second += V[i].second - V[i].first;
			return ret;
		};
		cout << dp(1, k).first << "\n";
	}
	return 0;
}