#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll MOD = (ll)1e9 + 7;
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
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ll q = 2;
	int k;
	scanf("%d", &k);
	bool odd = true;
	while(k--)
	{
		ll x;
		scanf("%lld", &x);
		odd &= (x & 1);
		q = bin_pow(q, x);
	}
	q = mult(q, rev(2));
	ll p = q;
	if (odd)
		p = (p + MOD - 1) % MOD;
	else
		p = (p + 1) % MOD;
	p = mult(p, rev(3));
	printf("%lld/%lld\n", p, q);

	return 0;
}