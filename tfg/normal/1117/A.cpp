#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	int mx = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		mx = std::max(mx, a[i]);
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] == mx) {
			int j = i;
			while(j < n && a[i] == a[j]) j++;
			ans = std::max(ans, j - i);
			i = j - 1;
		}
	}
	std::cout << ans << '\n';
}