#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		std::string ans, str;
		std::cin >> str;
		int id = n-1;
		while(id >= 0 && str[id] != '0') {
			id--;
		}
		int other = 0;
		while(other < n && str[other] != '1') {
			other++;
		}
		if(id < other) {
			ans = str;
		} else {
			for(int i = 0; i < n; i++) {
				if(i < other || i >= id) {
					ans += str[i];
				}
			}
		}
		std::cout << ans << '\n';
	}
}