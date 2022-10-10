#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::map<std::pair<int, int>, int> freq;
	int n;
	std::cin >> n;
	std::vector<int> a(n), b(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	int base = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> b[i];
		// x == - bi / ai
		int bi = b[i], ai = a[i];
		if(ai == 0 && bi != 0) continue;
		if(ai == 0 && bi == 0) {
			base++;
			continue;
		}
		int g = gcd(std::max(ai, -ai), std::max(bi, -bi));
		bi /= g;
		ai /= g;
		if(ai < 0) {
			bi = -bi;
			ai = -ai;
		}
		freq[std::pair<int, int>(ai, bi)]++;
	}
	int ans = base;
	for(auto e : freq) {
		ans = std::max(ans, base + e.second);
	}
	std::cout << ans << '\n';
}