/*input
4
1 1 1 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll modulo = 998244353;
ll mod(ll x)
{
	x %= modulo;
	x += modulo;
	x %= modulo;
	return x;
}
ll power(ll x, ll a)
{
	x = mod(x);
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
	return power(x, modulo - 2);
}
ll F[5000];
ll iF[5000];
ll C(ll n, ll k)
{
	if (n < 0 || k < 0 || n - k < 0)
		return 0;
	return mod(F[n] * mod(iF[k] * iF[n - k]));
}
int main()
{
	F[0] = iF[0] = 1;
	for (ll i = 1; i < 5000; i++)
	{
		F[i] = mod(F[i - 1] * i);
		iF[i] = inv(F[i]);
	}
	ll n;
	cin >> n;
	ll a[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	ll ans[n + 2];
	fill_n(ans, n + 2, 0);
	ans[n + 1] = 1;
	ll ret = 0;
	for (int i = n; i >= 1; i--)
	{
		if (a[i] <= 0)
			continue;
		ll k = a[i] + 1;
		for (int j = i + 1; j <= n + 1; j++)
		{
			ans[i] += ans[j] * C(j - i - 1, k - 1);
			ans[i] %= modulo;
		}
		ret += ans[i];
		ret %= modulo;
	}
	cout << ret << "\n";

}