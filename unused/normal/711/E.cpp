#include <stdio.h>
#include <climits>
#include <algorithm>
using namespace std;

const int MOD = 1e6 + 3;
using ll = long long;

// calculate a*b % m
// |m| < 2^62, x86 available
// O(logb)
ll large_mod_mul(ll a, ll b, ll m)
{
	a %= m; b %= m; ll r = 0, v = a;
	while (b) {
		if (b & 1) r = (r + v) % m;
		b >>= 1;
		v = (v << 1) % m;
	}
	return r;
}
// calculate n^k % m
ll modpow(ll n, ll k, ll m) {
	ll ret = 1;
	n %= m;
	while (k) {
		if (k & 1) ret = large_mod_mul(ret, n, m);
		n = large_mod_mul(n, n, m);
		k /= 2;
	}
	return ret;
}

// find a pair (c, d) s.t. ac + bd = gcd(a, b)
pair<ll, ll> extended_gcd(ll a, ll b) {
	if (b == 0) return{ 1, 0 };
	auto t = extended_gcd(b, a % b);
	return{ t.second, t.first - t.second * (a / b) };
}

// find x in [0,m) s.t. ax === gcd(a, m) (mod m)
ll modinverse(ll a, ll m) {
	return (extended_gcd(a, m).first % m + m) % m;
}

int main()
{
	ll n, k;
	scanf("%lld%lld", &n, &k);

	if (n <= 62 && (1ll << n) < k)
	{
		printf("1 1");
		return 0;
	}

	ll ksum = 0;

	for (ll z = k - 1; z >= 2; z >>= 1)
	{
		ksum += z >> 1;
	}

	ll bunmo = modpow(modpow(2, n, MOD), k - 1, MOD)
		* modinverse(modpow(2, ksum, MOD), MOD) % MOD;

	ll bunza = modinverse(modpow(2, ksum, MOD), MOD),
		start = (modpow(2, n, MOD) + (MOD - 1)) % MOD;

	for (ll i = 0; i < k - 1 && bunza; i++, start = (start + MOD - 1) % MOD)
	{
		bunza = bunza * start % MOD;
	}

	printf("%lld %lld", ((bunmo - bunza) % MOD + MOD) % MOD, bunmo);
}