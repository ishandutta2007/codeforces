/*input
3
9
87163278 98127389652386 123123123 5153 711231212 123123 123123 123123 98798
1
8
2
1 1
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
	ll t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		ll suma = 0;
		ll xsum = 0;
		while (n--)
		{
			ll a;
			cin >> a;
			suma += a;
			xsum ^= a;
		}
		ll x = 0;
		ll y = 0;
		ll z = 0;
		if (suma % 2 == 1)
			x++;
		for (ll i = 1; i <= (1ll << 55); i *= 2)
		{
			ll s1 = suma + x + y + z;
			ll s2 = xsum ^ x ^ y ^ z;
			if ((s2 & i) > 0 && (s1 & (2 * i)) > 0)
			{
				continue;
			}
			else if ((s2 & i) == 0 && (s1 & (2 * i)) == 0)
			{
				continue;
			}
			else if ((s2 & i) > 0 && (s1 & (2 * i)) == 0)
			{
				y += 2 * i;
			}
			else if ((s2 & i) == 0 && (s1 & (2 * i)) > 0)
			{
				if (i == (1ll << 55))
				{
					x += 2 * i;
					y += 2 * i;
					z += 6 * i;
					break;
				}
				else
				{
					y += i;
					z += i;
				}
			}
		}
		ll s1 = suma + x + y + z;
		ll s2 = xsum ^ x ^ y ^ z;
		assert(s1 == s2 * 2);
		cout << 3 << "\n" << x << " " << y << " " << z << "\n";
	}
}