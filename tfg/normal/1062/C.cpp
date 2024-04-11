#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;
const int MOD = 1e9 + 7;

int pot[ms];
int sum[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, q;
	std::cin >> n >> q;
	std::string str;
	std::cin >> str;
	for(int i = 0; i < n; i++) {
		sum[i+1] = sum[i] + str[i] - '0';
	}
	pot[0] = 1;
	for(int i = 1; i < ms; i++) {
		pot[i] = pot[i-1] * 2 % MOD;
	}
	while(q--) {
		int l, r;
		std::cin >> l >> r;
		int f1 = sum[r] - sum[l-1];
		int f0 = (r - l + 1) - f1;
		std::cout << (long long) (pot[f1] - 1) * pot[f0] % MOD << '\n';
	}
}