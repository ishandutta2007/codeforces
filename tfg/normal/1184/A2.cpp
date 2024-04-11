#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::string str;
	std::cin >> n >> str;
	std::vector<int> count(n + 1, 0);
	for(int i = 1; i <= n; i++) {
		count[gcd(i, n)]++;
	}
	int ans = 0;
	for(int d = 1; d <= n; d++) {
		if(n % d != 0) continue;
		std::vector<bool> v(d, false);
		for(int i = 0; i < n; i++) {
			if(str[i] == '1') {
				v[i % d] = !v[i % d];
			}
		}
		bool cur = true;
		for(auto val : v) {
			cur = cur && !val;
		}
		if(cur) {
			ans += count[d];
		}
	}
	std::cout << ans << '\n';
}