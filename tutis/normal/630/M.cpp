/*input
60

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll C(ll n, ll k)
{
	if (k > n || k < 0)
		return 0;
	ll s = 1;
	ll f = 1;
	for (int i = 0; i < k; i++)
		f *= i + 1;
	for (int i = 0; i < k; i++)
	{
		ll x = n - i;
		ll g = __gcd(x, f);
		f /= g;
		x /= g;
		s *= x;
	}
	s /= f;
	return s;
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll x;
	cin >> x;
	x %= 360;
	if (x < 0)
		x += 360;
	pair<ll, ll>mn = {400, 0};
	for (int t = 0; t < 5; t++)
	{
		ll y = x - 90 * t;
		y %= 360;
		if (y < 0)
			y += 360;
		ll delt = min(y, 360 - y);
		mn = min(mn, {delt, t});
	}
	cout << mn.second << "\n";
}