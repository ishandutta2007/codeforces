/*input
3
4
10
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll modulo = 998244353;
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
ll F[1000009];
int main()
{
	F[0] = 1;
	for (ll i = 1; i < 1000009; i++)
		F[i] = mod(F[i - 1] * i);
	ios_base::sync_with_stdio(false);
	ll n;
	while (cin >> n)
	{
		ll ans = mod(F[n] * n);
		for (ll k = 1; k < n; k++)
		{
			ans -= mod(F[n] * inv(F[k]));
			ans = mod(ans);
		}
		cout << ans << "\n";
	}
}