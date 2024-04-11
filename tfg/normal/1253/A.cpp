#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		std::vector<int> a(n), b(n);
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		for(int i = 0; i < n; i++) {
			std::cin >> b[i];
		}
		int on = 0;
		while(on < n && a[on] == b[on]) {
			on++;
		}
		if(on == n) {
			std::cout << "YES\n";
			continue;
		}
		int d = b[on] - a[on];
		if(d < 0) {
			std::cout << "NO\n";
			continue;
		}
		while(on < n && a[on] + d == b[on]) {
			on++;
		}
		while(on < n && a[on] == b[on]) {
			on++;
		}
		if(on == n) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
}