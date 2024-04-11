/*input
10000000000 20000000000
*/
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll ans(ll l, ll r, ll a, ll b, ll x)
{
	if (a > b)
		swap(a, b);
	if (x == 0)
	{
		if (l <= a && b <= r)
			return (a ^ b);
		return -1000;
	}
	if (b > r)
		return -1000;
	if (a + 2 * x - 1 < l)
		return -1000;
	ll a1 = ans(l, r, a + x, b, x / 2);
	if (a1 >= 0)
		return a1;
	ll a2 = ans(l, r, a, b + x, x / 2);
	if (a2 >= 0)
		return max(a1, a2);
	return max(ans(l, r, a + x, b + x, x / 2),
	           ans(l, r, a    , b    , x / 2));
}
int main()
{
	ll l, r;
	cin >> l >> r;
	cout << ans(l, r, 0, 0, 1ll << 59) << endl;
}