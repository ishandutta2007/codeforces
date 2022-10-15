/*input
2
3
1 2 3
3 2 4
2 4 3
4 5 6
5 6 5
2
1 2 1
1 3 2
1 4 3

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
	ll test;
	cin >> test;
	while (test--)
	{
		ll k;
		cin >> k;
		ll n = 2 * k;
		vector<pair<ll, ll>>adj[n + 1];
		ll kiek[n + 1];
		ll sz[n + 1];
		for (ll i = 1; i < 2 * k; i++)
		{
			ll a, b, t;
			cin >> a >> b >> t;
			adj[a].push_back({b, t});
			adj[b].push_back({a, t});
		}
		ll B = 0;
		ll G = 0;
		function<void(ll, ll)>dfs = [&](ll i, ll p)
		{
			sz[i] = 1;
			kiek[i] = 1;
			vector<pair<ll, ll>>A;
			for (pair<ll, ll>j : adj[i])
			{
				if (j.first != p)
				{
					dfs(j.first, i);
					sz[i] += sz[j.first];
					kiek[i] += kiek[j.first];
					G += kiek[j.first] * j.second;
					ll x = min({k, sz[j.first], n - sz[j.first]});
					B += x * j.second;
				}
			}
			while (kiek[i] >= 2)
				kiek[i] -= 2;
		};
		dfs(1, 1);
		cout << G << " " << B << "\n";
	}
}