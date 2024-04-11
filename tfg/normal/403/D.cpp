#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;
const int ms = 2020;
const int mn = ms / 2;
const int mk = 65;

inline void add(int &a, int &b) {
	a = (a + b >= MOD ? a + b - MOD : a + b);
}

long long fat[ms];
int table[mk][mn];
int comb[ms][ms];

void pre() {
	fat[0] = 1;
	for(int i = 1; i < ms; i++) { fat[i] = (long long) fat[i-1] * i % MOD; }
	table[0][0] = 1;
	for(int v = 1; v < mn; v++) {
		for(int k = mk - 1; k > 0; k--) {
			for(int i = 0; i + v < mn; i++) {
				add(table[k][i+v], table[k-1][i]);
			}
		}
	}
	for(int i = 0; i < ms; i++) {
		comb[i][0] = 1;
		for(int j = 1; j <= i; j++) {
			comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
		}
	}
}

long long sum(int n, int k) {
	return (long long) comb[n+k-1][k-1];
}

int solve(int n, int k) {
	long long ans = 0;
	for(int i = k * (k + 1) / 2; i <= n; i++) {
		if(!table[k][i]) continue;
		long long cur = table[k][i];
		cur = cur * sum(n - i, k + 1) % MOD;
		ans = (ans + cur) % MOD;
	}
	ans = ans * fat[k] % MOD;
	return (int) ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	pre();
	int t;
	std::cin >> t;
	while(t--) {
		int n, k;
		std::cin >> n >> k;
		std::cout << solve(n, k) << std::endl;
	}
}