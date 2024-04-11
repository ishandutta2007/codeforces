#include <bits/stdc++.h>
using namespace std;

const int MX = 2e5;
const int M = (119 << 23) + 1;

int inv[MX + 1], fact[MX + 1];

int add(int a, int b) {
	return a + b < M ? a + b : a + b - M;
}

int sub(int a, int b) {
	return a - b < 0 ? a - b + M : a - b;
}

int mul(int a, int b) {
	return (long long)a * b % M;
}

int comb(int n, int k) {
	return mul(fact[n], mul(inv[n - k], inv[k]));
}

int modpow(int b, int e) {
	if (!e) return 1;
	if (e % 2) return mul(b, modpow(b, e - 1));
	int tmp = modpow(b, e / 2);
	return mul(tmp, tmp);
}

void init() {
	inv[1] = inv[0] = fact[0] = 1;
	for (int i = 2; i <= MX; ++i) {
		inv[i] = M - mul(M / i, inv[M % i]);
	}
	for (int i = 1; i <= MX; ++i) {
		inv[i] = mul(inv[i - 1], inv[i]);
		fact[i] = mul(fact[i - 1], i);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	init();
	int n;
	long long k;
	cin >> n >> k;

	if (k >= n) {
		cout << 0 << '\n';
		return 0;
	}
	if (!k) {
		cout << fact[n] << '\n';
		return 0;
	}
	
	int m = n - k, ans = 0;
	for (int i = m; i; --i) {
		int res = mul(comb(m, i), modpow(i, n));
		if (i % 2 == m % 2) {
			ans = add(ans, res);
		} else {
			ans = sub(ans, res);
		}
	}
	cout << mul(ans, mul(comb(n, m), 2)) << '\n';
}