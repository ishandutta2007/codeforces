/*input
2
2 3
5
2 1 1
2 2 1
1 1 1
2 1 2
2 2 0
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll a[n + 1];
	ll suma = 0;
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i];
		suma += a[i];
	}
	ll q;
	cin >> q;
	map<pair<ll, ll>, ll>M;
	while (q--)
	{
		ll s, t, u;
		cin >> s >> t >> u;
		if (M.count({s, t}))
		{
			ll v = M[ {s, t}];
			a[v]++;
			if (a[v] > 0)
				suma++;
			M.erase({s, t});
		}
		if (u != 0)
		{
			M[ {s, t}] = u;
			if (a[u] > 0)
				suma--;
			a[u]--;
		}
		cout << suma << "\n";
	}
}