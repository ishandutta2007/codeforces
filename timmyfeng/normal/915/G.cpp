#include <bits/stdc++.h> 
using namespace std;

const int MX = 2e6 + 1;
const int M = 1e9 + 7;

int mu[MX], pow_n[MX], pre_sum[MX];
bool sieve[MX];

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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	mu[1] = 1;
	vector<int> primes;
	for (int i = 2; i < MX; ++i) {
		if (!sieve[i]) {
			mu[i] = -1;
			primes.push_back(i);
		}
		for (auto j : primes) {
			if (i * j >= MX)
				break;
			sieve[i * j] = true;
			if (i % j) {
				mu[i * j] = -mu[i];
			} else {
				mu[i * j] = 0;
				break;
			}
		}
	}

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= k; ++i) {
		pow_n[i] = mod_pow(i, n);
	}

	for (int i = 1; i <= k; ++i) {
		int res = 0;
		for (int j = 1; i * j <= k; ++j) {
			pre_sum[i * j] = sub(pre_sum[i * j], res);
			res = mul(pow_n[j], mu[i] + M);
			pre_sum[i * j] = add(pre_sum[i * j], res);
		}
	}

	int ans = 0;
	int cur = 0;
	for (int i = 1; i <= k; ++i) {
		cur = add(cur, pre_sum[i]);
		ans = add(ans, cur ^ i);
	}
	cout << ans << '\n';
}