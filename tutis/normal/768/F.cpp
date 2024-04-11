/*input
1 2 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
ll F[1000000];
ll C(ll n, ll k)
{
	if (n < 0 || k < 0 || n - k < 0)
		return 0;
	return mod(F[n] * inv(F[k] * F[n - k]));
}
ll CC(ll a, ll b)
{
	if (a < 0 || b < 0)
		return 0;
	if (b == 0)
		return a == 0;
	return C(a + b - 1, b - 1);
}
int main()
{
	F[0] = 1;
	for (int i = 1; i < 1000000; i++)
		F[i] = (i * F[i - 1]) % modulo;
	ll f, w, h;
	cin >> f >> w >> h;
	h++;
	ll viso = 0;
	ll gero = 0;
	for (ll a = 1; a <= 3e5; a++)
	{
		ll c = a / 2;
		for (ll k : {c, a - c})
		{
			ll kw = k;
			ll kf = a - k;
			f -= kf;
			w -= kw;
			{
				viso += mod(CC(f, kf) * CC(w, kw));
				viso = mod(viso);
			}
			f += kf;
			w += kw;


			w -= h * kw;
			f -= kf;
			{
				gero += mod(CC(f, kf) * CC(w, kw));
				gero = mod(gero);
			}
			f += kf;
			w += h * kw;
		}
	}
	//cout << gero << " / " << viso << endl;
	cout << mod(inv(viso)*gero) << endl;
}