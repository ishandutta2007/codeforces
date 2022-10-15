/*input
16 7 5
2 3 4 5 6 15 16
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
	ll n, m, k;
	cin >> n >> m >> k;
	ll p = 1;
	ll kiek = 0;
	ll ans = 0;
	while (m--)
	{
		ll x;
		cin >> x;
		if (x >= p + k)
		{
			if (kiek > 0)
			{
				ans++;
				p += kiek;
				kiek = 0;
			}
		}
		ll a = (x - p) / k - 3;
		if (a > 0)
			p += k * a;
		while (x >= p + k)
			p += k;
		kiek++;
	}
	if (kiek > 0)
		ans++;
	cout << ans << "\n";
}