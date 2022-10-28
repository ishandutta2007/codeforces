#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
const int MOD = 1e9 + 7;

int fact_inv[N];
int fact[N];

int add(int a, int b) {
	return (a += b) < MOD ? a : a - MOD;
}

int mul(int a, int b) {
	return 1LL * a * b % MOD;
}

int mod_pow(int a, int b) {
	int res = 1;
	while (b) {
		if (b % 2) {
			res = mul(res, a);
		}
		a = mul(a, a);
		b /= 2;
	}
	return res;
}

void init_fact() {
	fact_inv[1] = 1;
	for (int i = 2; i < N; ++i) {
		fact_inv[i] = MOD - mul(MOD / i, fact_inv[MOD % i]);
	}

	fact[0] = 1;
	fact_inv[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = mul(fact[i - 1], i);
		fact_inv[i] = mul(fact_inv[i - 1], fact_inv[i]);
	}
}

int cnk(int n, int k) {
	if (k < 0 || k > n)
		return 0;
	return mul(fact[n], mul(fact_inv[k], fact_inv[n - k]));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	init_fact();

	int n, m, a, b;
	cin >> n >> m >> a >> b;

	int ans = 0;
	for (int i = 2; i <= n; ++i) {
		int cnt = (i == n) ? 1 : mul(i, mod_pow(n, n - i - 1));
		ans = add(ans, mul(mul(cnt, mul(fact[n - 2], fact_inv[n - i])), mul(cnk(m - 1, i - 2), mod_pow(m, n - i))));
	}
	cout << ans << "\n";
}