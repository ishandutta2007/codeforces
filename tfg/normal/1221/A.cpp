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
		std::vector<int> freq(30, 0);
		int n;
		std::cin >> n;
		while(n--) {
			int x;
			std::cin >> x;
			int l = 0;
			while(x % 2 == 0) {
				x /= 2;
				l++;
			}
			freq[l]++;
		}
		for(int i = 0; i < 11; i++) {
			freq[i+1] += freq[i] / 2;
			freq[i] %= 2;
		}
		if(freq[11]) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
}