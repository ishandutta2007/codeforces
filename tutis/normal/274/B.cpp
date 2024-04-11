/*input
3
1 2
1 3
1 -1 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n;
	cin >> n;
	ll ans = 0;
	vector<ll>adj[n + 1];
	ll v[n + 1];
	for (ll i = 1; i < n; i++)
	{
		ll a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (ll i = 1; i <= n; i++)
		cin >> v[i];
	function<pair<ll, ll>(ll, ll)>dfs = [&](ll i, ll p)->pair<ll, ll>
	{
		pair<ll, ll>x = {0, 0};
		for (ll j : adj[i])
		{
			if (j == p)
				continue;
			pair<ll, ll> y = dfs(j, i);
			x.first = max(x.first, y.first);
			x.second = max(x.second, y.second);
		}
		v[i] -= x.first;
		v[i] += x.second;
		if (v[i] > 0)
		{
			x.first += abs(v[i]);
		}
		else
		{
			x.second += abs(v[i]);
		}
		return x;
	};
	pair<ll, ll>a = dfs(1, 0);
	cout << a.first + a.second << "\n";
}