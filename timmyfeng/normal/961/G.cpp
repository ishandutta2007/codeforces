#include <bits/stdc++.h> 
using namespace std;

const int M = 1e9 + 7;
const int MX = 2e5 + 1;

int fact[MX], fact_inv[MX];

int add(int a, int b) {
	a += b;
	return a < M ? a : a - M;
}

int sub(int a, int b) {
	a -= b;
	return a < 0 ? a + M : a;
}

int mul(int a, int b) {
	return (long long)a * b % M;
}

int mod_pow(int b, int e) {
	if (!e)
		return 1;
	if (e % 2)
		return mul(b, mod_pow(b, e - 1));
	int tmp = mod_pow(b, e / 2);
	return mul(tmp, tmp);
}

int cnk(int n, int k) {
	return mul(fact[n], mul(fact_inv[n - k], fact_inv[k]));
}

int stirling(int n, int k) {
	int sum = 0;
	for (int i = 0; i <= k; ++i) {
		int res = mul(cnk(k, i), mod_pow(k - i, n));
		if (i % 2) {
			sum = sub(sum, res);
		} else {
			sum = add(sum, res);
		}
	}
	return mul(sum, fact_inv[k]);
}

void init() {
	fact[0] = 1;
	fact_inv[0] = 1;
	fact_inv[1] = 1;
	for (int i = 2; i < MX; ++i) {
		fact_inv[i] = M - mul(M / i, fact_inv[M % i]);
	}
	for (int i = 1; i < MX; ++i) {
		fact[i] = mul(fact[i - 1], i);
		fact_inv[i] = mul(fact_inv[i - 1], fact_inv[i]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	init();

	int n, k;
	cin >> n >> k;

	int sum = 0;
	for (int i = 0; i < n; ++i) {
		int w;
		cin >> w;
		sum = add(sum, w);
	}

	cout << mul(sum, stirling(n, k) + mul(n - 1, stirling(n - 1, k))) << '\n';
}