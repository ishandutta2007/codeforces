/*input
5
2
4
6
15
20

*/
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
using namespace std;
//using ull = __ull128_t;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
ll mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll power(ll a, ll b)
{
	if (abs(a) >= mod)
		a %= mod;
	if (abs(b) >= mod - 1)
		b %= (mod - 1);
	if (a < 0)
		a += mod;
	if (b < 0)
		b += mod - 1;
	ll r = 1;
	if (b % 2 == 1)
		r = a;
	b /= 2;
	while (b)
	{
		a = (a * a) % mod;
		if (b % 2 == 1)
			r = (r * a) % mod;
		b /= 2;
	}
	return r;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		if (n >= 3 && n % 2 == 1)
		{
			cout << 2 << "\n";
		}
		else
		{
			ll ans = -1;
			for (ll k = 2; ans == -1; k *= 2)
			{
				ll v = n - k * (k + 1) / 2;
				if (v < 0)
					break;
				if (v % k == 0)
				{
					ans = k;
					break;
				}
			}
			ll lo = 0;
			ll hi = 2e9;
			while (lo < hi)
			{
				ll x = (lo + hi + 1) / 2;
				if (x * (x + 1) / 2 > n)
					hi = x - 1;
				else
					lo = x;
			}
			ll vv = n;
			while (vv % 2 == 0)
				vv /= 2;
			{
				ll k = vv;
				ll v = n - k * (k + 1) / 2;
				if (v >= 0 && v % k == 0 && k >= 2)
				{
					ans = k;
				}
			}
			for (ll k = lo; ans == -1 && k >= lo - 100 && k >= 2; k--)
			{
				ll v = n - k * (k + 1) / 2;
				if (v % k == 0)
				{
					ans = k;
					break;
				}
			}
			cout << ans << "\n";
		}
	}
}