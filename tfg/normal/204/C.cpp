#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long trans[2][26];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long ans = 0;
	int n;
	std::cin >> n;
	std::string s[2];
	std::cin >> s[0] >> s[1];
	long long q = 0;
	long long p = 0;
	for(int i = 1; i <= n; i++) {
		long long sub = n - i + 1;
		q += sub * sub;
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 2; j++) {
			int id = s[j][i] - 'A';
			ans += trans[j^1][id] * (n - i);
			p += ans / q;
			ans %= q;
			trans[j][id] += i + 1;
		}
	}
	std::cout << ans / q + p << '.';
	ans %= q;
	for(int i = 0; i < 10; i++) {
		ans *= 10;
		std::cout << ans / q;
		ans %= q;
	}
	std::cout << '\n';
}