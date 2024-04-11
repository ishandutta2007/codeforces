#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	const int ms = 100100;
	const int MOD = 1e9 + 7;
	std::vector<int> f(ms, 1), a(ms, 0);
	int n;
	std::cin >> n;
	while(n--) {
		int x;
		std::cin >> x;
		f[x] = (f[x] + f[x]) % MOD;
	}
	for(int i = ms-1; i > 0; i--) {
		long long val = 1;
		for(int j = i; j < ms; j += i) {
			val = val * f[j] % MOD;
		}
		a[i] = (int) (val - 1);
		for(int j = i + i; j < ms; j += i) {
			a[i] = (a[i] - a[j] + MOD) % MOD;
		}
	}
	std::cout << a[1] << '\n';
}