/*input
8
2 4 1 3 4 2 1 2

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 gen(123);
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll h[n + 1];
	for (ll i = 1; i <= n; i++)
		h[i] = gen();
	ll hh[n + 1];
	hh[0] = 0;
	for (ll i = 1; i <= n; i++)
		hh[i] = hh[i - 1] ^ h[i];
	ll a[n + 1];
	ll ans = 0;
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] == 1)
			ans++;
	}
	for (ll t = 0; t < 2; t++)
	{
		reverse(a + 1, a + n + 1);
		ll hp[n + 1];
		hp[0] = 0;
		for (ll i = 1; i <= n; i++)
			hp[i] = hp[i - 1] ^ h[a[i]];
		ll i = -1;
		ll len = -1;
		for (ll r = 1; r <= n; r++)
		{
			if (a[r] == 1)
			{
				len = -1;
				i = r;
			}
			else if (i != -1)
			{
				len = max(len, a[r]);
				ll l = r - len + 1;
				if (l >= 1)
				{
					if ((hp[r]^hp[l - 1]^hh[len]) == 0)
						ans++;
				}
			}
		}
	}
	cout << ans << "\n";

}