#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k, p, s;
	std::cin >> n >> k >> p >> s;
	const int ms = 500500;
	std::vector<int> freq(ms, 0);
	std::vector<int> cur(ms, 0);
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i < s; i++) {
		int x;
		std::cin >> x;
		freq[x]++;
	}
	int got = 0;
	for(int l = 0, r = 0; l + k <= n; l++) {
		while((r - l < k || got < s) && r < n) {
			if(freq[a[r]] > cur[a[r]]) {
				got++;
			}
			cur[a[r]]++;
			r++;
		}
		// test
		if(got == s && 1 + l / k + (n - r) / k >= p) {
			int left = std::min(p-1, l / k) * k;
			std::cout << l - left + r - l - k << '\n';
			for(int i = 0; i < l - left; i++) {
				std::cout << i + 1 << '\n';
			}
			for(int i = 0; i < ms; i++) cur[i] = 0;
			int rest = r - l - k;
			for(int i = l; i < r; i++) {
				if(freq[a[i]] > cur[a[i]]) {
					// nothing
					cur[a[i]]++;
				} else if(rest) {
					rest--;
					std::cout << i + 1 << '\n';
				}
			}
			return 0;
		}
		// remove
		cur[a[l]]--;
		if(freq[a[l]] > cur[a[l]]) {
			got--;
		}
	}
		
	std::cout << "-1\n";
}