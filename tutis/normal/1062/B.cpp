/*input
10
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll ans = 0;
	while (true)
	{
		ll x = sqrtl(n);
		while (x * x < n)
			x++;
		while (x * x > n)
			x--;
		if (x * x == n && x < n)
		{
			n = x;
			ans++;
			continue;
		}
		x = 1;
		ll mxl = 0;
		for (ll i = 2; i <= n; i++)
		{
			ll a = 0;
			if (n % i == 0)
			{
				while (n % i == 0)
				{
					n /= i;
					a++;
				}
				x *= i;
				mxl = max(mxl, a);
			}
		}
		if (mxl >= 2)
		{
			ans++;
			while (mxl != (mxl & (-mxl)))
				mxl++;
			while (mxl != 1)
			{
				mxl /= 2;
				ans++;
			}
		}
		n = x;
		break;
	}
	cout << n << " " << ans << "\n";

}