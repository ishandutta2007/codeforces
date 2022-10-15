/*input
3
4 8 5

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<ll>fact(ll n)
{
	vector<ll>r;
	for (ll g = 2; g * g <= n; g++)
	{
		while (n % g == 0)
		{
			n /= g;
			r.push_back(g);
		}
	}
	if (n > 1)
		r.push_back(n);
	return r;
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll a[n];
	ll b[n];
	ll sum = 0;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	ll ans = 2e18;
	for (ll g : fact(sum))
	{
		ll gal = 0;
		for (ll i = 0; i < n; i++)
			b[i] = a[i] % g;
		ll l = 0;
		ll ss = 0;
		for (ll r = 0; r < n; r++)
		{
			ss += b[r];
			if (ss >= g)
			{
				ll k = (g + 1) / 2;
				ll id = l;
				for (ll i = l; i <= r; i++)
				{
					k -= b[i];
					if (k <= 0)
					{
						id = i;
						break;
					}
				}
				ll w = ss - g;
				b[r] -= w;
				for (ll i = l; i <= r; i++)
				{
					gal += abs(i - id) * b[i];
				}
				l = r;
				ss = b[r] = w;
			}
		}
		ans = min(ans, gal);
	}
	if (ans > 1e18)
		ans = -1;
	cout << ans << "\n";
}