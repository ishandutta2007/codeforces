/*input
5 15 1 5

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll modulo = 1000000007;
ll mod(ll x, ll m = modulo)
{
	x %= m;
	x += m;
	x %= m;
	return x;
}
ll power(ll x, ll a)
{
	x = mod(x);
	if (a < 0)
		a = mod(a, modulo - 1);
	ll ret = 1;
	ll k = 1;
	while (a)
	{
		if ((k & a) > 0)
		{
			a ^= k;
			ret = mod(ret * x);
		}
		k <<= 1;
		x = mod(x * x);
	}
	return ret;
}
ll inv(ll x)
{
	return power(x, -1);
}
ll interpolate(vector<ll> &x, vector<ll> &y, ll X)
{
	for (ll i = 0; i < x.size(); i++)
		if (x[i] == X)
			return y[i];
	ll ret = 0;
	for (ll i = 0; i < x.size(); i++)
	{
		ll a = y[i];
		ll b = 1;
		for (ll j = 0; j < x.size(); j++)
		{
			if (j == i)
				continue;
			a = mod(a * mod(X - x[j]));
			b = mod(b * mod(x[i] - x[j]));
		}
		ret = mod(ret + a * inv(b));
	}
	return ret;
}
ll FF[1100001];
ll F(ll x)
{
	if (x < 0)
		return 0;
	return FF[x];
}
ll C(ll n, ll k)
{
	return mod(F(n) * inv(F(n - k) * F(k)));
}
int main()
{
	FF[0] = 1;
	for (ll i = 1; i < 1100001; i++)
		FF[i] = mod(FF[i - 1] * i);
	ll n, m;
	cin >> n >> m;
	ll ans = 0;
	for (ll k = 0; k < m && k + 2 <= n; k++)
	{
		ll x = 1;
		x *= C(m - 1, k);
		x %= modulo;
		x *= (k + 2);
		x %= modulo;
		x *= power(n * m, n - k - 3);
		x %= modulo;
		x *= mod(FF[k] * C(n - 2, k));
		x %= modulo;
		ans += x;
		ans %= modulo;
	}
	ans *= m;
	ans %= modulo;
	cout << ans << "\n";
}