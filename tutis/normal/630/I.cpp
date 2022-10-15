/*input
4
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
	ull n;
	cin >> n;
	ll ret = 0;
	for (int a = 0; a <= n - 2; a++)
	{
		ll x = 4;
		int k = n - 2;
		if (a != 0)
		{
			x *= 3;
			k--;
		}
		if (a != n - 2)
		{
			x *= 3;
			k--;
		}
		x *= ll(round(pow(4, k)));
		ret += x;
	}
	cout << ret << "\n";
}