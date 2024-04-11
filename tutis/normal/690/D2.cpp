/*input
5 1
2 2
3 2
11 5
37 63
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll modulo = 1000003;

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
	return (F[n] * inv(F[k] * F[n - k])) % modulo;
}
int main()
{
	F[0] = 1;
	for (int i = 1; i < 1000000; i++)
		F[i] = (F[i - 1] * i) % modulo;
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll n, c;
	while (cin >> n >> c)
	{
		ll ans = 0;
		for (int i = 1; i <= n; i++)
		{
			ans += C(c + i - 1, i);
			ans %= modulo;
		}
		cout << ans << "\n";
	}
}