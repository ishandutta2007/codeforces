#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1000000007;
int fact[200005], finv[200005];

using ll = long long;
// find a pair (c, d) s.t. ac + bd = gcd(a, b)
pair<ll, ll> extended_gcd(ll a, ll b) {
	if (b == 0) return{ 1, 0 };
	auto t = extended_gcd(b, a % b);
	return{ t.second, t.first - t.second * (a / b) };
}
// find x in [0,m) s.t. ax === gcd(a, m) (mod m)
ll modinverse(ll a) {
	return (extended_gcd(a, MOD).first % MOD + MOD) % MOD;
}


int main()
{
	fact[0] = 1;
	finv[0] = 1;
	for (int i = 1; i <= 200000; i++)
	{
		fact[i] = fact[i - 1] * 1ll * i % MOD;
		finv[i] = modinverse(fact[i]);
	}

	int f, w, h;
	scanf("%d%d%d", &f, &w, &h);

	if (w == 0)
	{
		printf("1\n");
		return 0;
	}
	if (f == 0)
	{
		printf("%d\n", w > h ? 1 : 0);
		return 0;
	}

	int res = 0;
	++h;

	for (int k = 1; k * h <= w && k - 1 <= f; k++)
	{
		res = (res + fact[k + w - h * k - 1] * 1ll * finv[w - h*k] % MOD * finv[k - 1] % MOD * fact[f+1] % MOD * finv[f-k+1] % MOD * finv[f + 1 - (f - k + 1)]) % MOD;
	}

	printf("%d\n", (int)(res * 1ll * finv[f+w] % MOD * fact[w] % MOD * fact[f] % MOD));
}