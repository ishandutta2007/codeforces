/*input
2
3 3
3 1 2
3 2 1
7 2
2 1 7 3 4 5 6
3 1
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	ll t;
	cin >> t;
	while (t--)
	{
		ll n, m;
		cin >> n >> m;
		ll a[n];
		for (ll i = 0; i < n; i++)
			cin >> a[i];
		ll b[m];
		for (ll i = 0; i < m; i++)
			cin >> b[i];
		ll id = 0;
		set<ll>top;
		ll ans = 0;
		ll isime = 0;
		for (ll x : b)
		{
			if (top.count(x))
			{
				top.erase(x);
				ans++;
				isime++;
				continue;
			}
			while (top.count(x) == 0)
			{
				top.insert(a[id]);
				id++;
			}
			ll k = id - isime - 1;
			ans += 2 * k + 1;
			top.erase(x);
			isime++;
		}
		cout << ans << "\n";
	}
}