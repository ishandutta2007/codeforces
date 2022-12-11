#include <iostream>
#include <vector>
#include <algorithm>
#define int long long

using namespace std;

const int MAX_N = 1e6 + 7, M = 998244353;
int fact[MAX_N - 1], dp[MAX_N];

int fast_pow(int x, int p) {
	if (p == 0) return 1;
	if (p == 1) return x % M;
	if (p % 2 == 0) {
		int m = fast_pow(x, p / 2);
		return (m * m) % M;
	}
	int m = fast_pow(x, p - 1);
	return (m * x) % M;
}

int obr(int x) {
	return fast_pow(x, M - 2);
}

void init() {
	fact[0] = 1;
	for (int i = 1; i < MAX_N; i++) {
		fact[i] = (i * fact[i - 1]) % M;
	}
}

int c_n_k(int n, int k) {
	int val = fact[n];
	val = (val * obr(fact[k])) % M;
	val = (val * obr(fact[n - k])) % M;
	return val;
}

int extr(int a, int b) {
	a = (a - b) % M;
	while (a < 0) a += M;
	return a;
}

signed main() {
	init();
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		dp[i] = (c_n_k(n, i) * fact[n - i]) % M;
	}
	dp[n + 1] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = extr(dp[i], dp[i + 1]);
	}
	int summ = 0;
	for (int i = 1; i <= n; i++) {
		summ = (summ + i * dp[i]) % M;
	}
	int s2 = (fact[n] * n) % M;
	int ans = (extr(s2, summ) + 1) % M;
	cout << ans << endl;
	return 0;
}