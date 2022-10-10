#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::string> strs(n);
	for(auto &s : strs) {
		std::cin >> s;
	}
	std::vector<int> a(m);
	for(auto &v : a) {
		std::cin >> v;
	}
	int ans = 0;
	for(int i = 0; i < m; i++) {
		int freq[5] = {0, 0, 0, 0, 0};
		for(int j = 0; j < n; j++) {
			freq[strs[j][i] - 'A']++;
		}
		int mx = 0;
		for(int j = 0; j < 5; j++) {
			mx = std::max(mx, freq[j]);
		}
		ans += mx * a[i];
	}
	std::cout << ans << '\n';
}