#include <bits/stdc++.h>
using namespace std;

const int MX = 5e5 + 1;
const int M = (119 << 23) + 1;

int fact[MX], fact_inv[MX];

int add(int a, int b) {
	a += b;
	return a < M ? a : a - M;
}

int mul(int a, int b) {
	return (long long)a * b % M;
}

int cnk(int n, int k) {
	if (k > n)
		return 0;
	return mul(fact[n], mul(fact_inv[n - k], fact_inv[k]));
}

void init() {
	fact[0] = fact_inv[0] = fact_inv[1] = 1;
	for (int i = 2; i < MX; ++i) {
		fact_inv[i] = M - mul(M / i, fact_inv[M % i]);
	}
	for (int i = 1; i < MX; ++i) {
		fact_inv[i] = mul(fact_inv[i - 1], fact_inv[i]);
		fact[i] = mul(fact[i - 1], i);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	init();

	int n, k;
	cin >> n >> k;	

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans = add(ans, cnk(n / i - 1, k - 1));
	}
	cout << ans << '\n';
}