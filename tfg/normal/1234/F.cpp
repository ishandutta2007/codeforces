#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string str;
	std::cin >> str;
	const int ms = 1 << 20;
	std::vector<int> a(ms, 0);
	int n = (int) str.size();
	for(int i = 0; i < n; i++) {
		int msk = 0;
		for(int j = i; j < n && (msk & (1 << (str[j] - 'a'))) == 0; j++) {
			msk |= 1 << (str[j] - 'a');
			a[msk] = j - i + 1;
		}
	}
	// max of submasks
	for(int len = 1; len < ms; len += len) {
		for(int i = 0; i < ms; i += 2 * len) {
			for(int j = 0; j < len; j++) {
				a[i+j+len] = std::max(a[i+j+len], a[i+j]);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < ms; i++) {
		ans = std::max(ans, a[i] + a[i ^ (ms - 1)]);
	}
	std::cout << ans << '\n';
}