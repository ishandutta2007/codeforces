#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string a;
	std::cin >> a;
	int n = (int) a.size();
	std::vector<int> to(n, n);
	for(int k = 1; k < n; k++) {
		bool run = false;
		for(int i = k; i + k < n; i++) {
			if(a[i-k] == a[i] && a[i] == a[i+k]) {
				to[i-k] = std::min(to[i-k], i + k);
			}
		}
		for(int i = n-2; i >= 0; i--) {
			to[i] = std::min(to[i], to[i+1]);
			if(to[i] - i > k) {
				run = true;
			}
		}
		if(!run) {
			break;
		}
	}
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		ans += n - to[i];
	}
	std::cout << ans << '\n';
}