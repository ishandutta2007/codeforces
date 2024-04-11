#include <iostream>
#include <cstdio>
#include <vector>

#define add(x, y) (x + y >= MOD ? x + y - MOD : x + y)

typedef long long ll;

ll MOD;

ll fmul(ll a, ll b, ll m)
{
	return (a * b - (ll)(((long double)a * b + 0.5) / m) * m);
}

ll fexp(ll x, ll e) {
	ll ans = 1;
	for(; e > 0; e /= 2) {
		if(e & 1) {
			ans = fmul(x, ans, MOD);
		}
		x = fmul(x, x, MOD);
	}
	return ans;
}

std::vector<ll> FWHT(std::vector<ll> a, bool inv = false) {
	for(int i = 1; i < a.size(); i *= 2) {
		for(int j = 0; j < a.size(); j += 2 * i) {
			for(int k = 0; k < i; k++) {
				ll u = a[j + k];
				ll v = a[j + k + i];
				a[k + j] = (u + v) % MOD;
				a[k + j + i] = (u - v + MOD) % MOD;
			}
		}
	}
	if(inv) {
		for(int i = 0; i < a.size(); i++) {
			a[i] /= a.size();
		}
	}
	return a;
}

int main() {
	ll m, t;
	std::cin >> m >> t >> MOD;
	int n = 1 << m;
	MOD *= n;
	std::vector<ll> a(n, 0);
	std::vector<ll> b(n, 0);
	std::vector<ll> bb(m + 1, 0);
	std::vector<int> bits(n);
	for(int i = 0; i < n; i++) {
		scanf("%lli", &a[i]);
		a[i] %= MOD;
	}
	for(int i = 0; i <= m; i++) {
		std::cin >> bb[i];
		bb[i] %= MOD;
	}
	for(int i = 0; i < n; i++) {
		bits[i] = bits[i / 2] + (i & 1);
		b[i] = bb[bits[i]];
	}
	b = FWHT(b);
	for(int i = 0; i < n; i++) {
		b[i] = fexp(b[i], t);
	}
	a = FWHT(a);
	for(int i = 0; i < n; i++) {
		a[i] = fmul(a[i], b[i], MOD);
	}
	a = FWHT(a, true);
	for(int i = 0; i < n; i++) {
		printf("%lli\n", a[i]);
	}
}