/*input
2020 437122297

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int32_t main()
{
	ios_base::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;
	ll F[n + 1];
	F[0] = 1;
	for (ll i = 1; i <= n; i++)
	{
		F[i] = i * F[i - 1];
		F[i] %= m;
	}
	ll ans = 0;
	for (ll s = 1; s <= n; s++)
	{
		ll x = F[s];
		x *= n - s + 1;
		x %= m;
		x *= F[n - s];
		x %= m;
		x *= (n - s + 1);
		x %= m;
		ans += x;
		if (ans >= m)
			ans -= m;
	}
	cout << ans << "\n";
}