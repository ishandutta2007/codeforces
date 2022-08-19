#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef long long ll;
const ll MOD = (ll)1e9 + 7;
ll add(ll x, ll y)
{
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll mult(ll x, ll y)
{
	return (x * y) % MOD;
}
ll bin_pow(ll x, ll p)
{
	if (p == 0) return 1;
	if (p == 2 || (p & 1)) return mult(x, bin_pow(x, p - 1));
	return bin_pow(bin_pow(x, p / 2), 2);
}
ll rev(ll x)
{
	return bin_pow(x, MOD - 2);
}

int main()
{
	ll n, a, b, x;
	cin >> a >> b >> n >> x;
	if (a == 1)
		b = mult(b, n % MOD);
	else
		b = mult(mult(b, bin_pow(a, n) - 1), rev(a - 1));
	x = mult(x, bin_pow(a, n));
	printf("%lld\n", add(x, b));

	return 0;
}