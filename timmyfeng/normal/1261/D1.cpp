#include <bits/stdc++.h> 
using namespace std;

const int MX = 2000 + 1;
const int M = (119 << 23) + 1;

int h[MX], fact[MX], fact_inv[MX];

int add(int a, int b) {
	return (a += b) < M ? a : a - M;
}

int mul(int a, int b) {
	return 1LL * a * b % M;
}

int mod_pow(int b, int e) {
	int res = 1;
	while (e) {
		if (e % 2) {
			res = mul(res, b);
		}
		b = mul(b, b);
		e /= 2;
	}
	return res;
}

int cnk(int n, int k) {
	return mul(fact[n], mul(fact_inv[k], fact_inv[n - k]));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	fact[0] = 1;
	fact_inv[1] = 1;
	fact_inv[0] = 1;
	for (int i = 2; i < MX; ++i) {
		fact_inv[i] = M - mul(M / i, fact_inv[M % i]);
	}

	for (int i = 1; i < MX; ++i) {
		fact[i] = mul(i, fact[i - 1]);
		fact_inv[i] = mul(fact_inv[i], fact_inv[i - 1]);
	}

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}

	if (k == 1) {
		cout << 0 << "\n";
		return 0;
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		cnt += (h[i] != h[(i + 1) % n]);
	}

	int ans = 0;
	for (int i = 0; i < cnt; ++i) {
		for (int j = i + 1; j + i <= cnt; ++j) {
			ans = add(ans, mul(cnk(cnt, i), mul(cnk(cnt - i, j), mod_pow(k - 2, cnt - i - j))));
		}
	}
	ans = mul(ans, mod_pow(k, n - cnt));
	cout << ans << "\n";
}