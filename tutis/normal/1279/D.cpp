/*input
5
2 1 2
2 3 1
3 2 4 3
2 1 4
3 4 3 2

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 998244353;
ll power(ll a, ll b)
{
	a %= mod;
	ll r = 1;
	while (b != 0)
	{
		if (b % 2 == 1)
			r = (r * a) % mod;
		a = (a * a) % mod;
		b /= 2;
	}
	return r;
}
ll inv(ll x)
{
	return power(x, mod - 2);
}
ll P[1001000];
ll kiek[1001000];
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	for (ll i = 0; i < n; i++)
	{
		ll k;
		cin >> k;
		ll p = inv(n * k);
		while (k--)
		{
			ll x;
			cin >> x;
			kiek[x]++;
			P[x] += p;
			if (P[x] >= mod)
				P[x] -= mod;
		}
	}
	ll ans = 0;
	ll in = inv(n);
	for (ll x = 0; x <= 1000000; x++)
	{
		if (P[x] == 0)
			continue;
		ans += ((P[x] * kiek[x]) % mod) * in;
		ans %= mod;
	}
	cout << ans << "\n";
}