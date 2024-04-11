#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<int> h(n);
	for(int i = 0; i < n; i++) {
		std::cin >> h[i];
	}
	for(int i = 0; i+1 < n; i++) {
		if(h[i] >= h[i+1] - k) {
			int use = std::min(h[i], h[i] - (h[i+1]-k));
			m += use;
			h[i] -= use;
		}
		if(h[i] + m < h[i+1] - k) {
			std::cout << "NO\n";
			return;
		}
		if(h[i] < h[i+1] - k) {
			m -= h[i+1]-k-h[i];
		}
	}
	std::cout << "YES\n";
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}