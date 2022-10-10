#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> freq(n, 0);
	int s = 0;
	while(m--) {
		int x;
		std::cin >> x;
		x--;
		freq[x]++;
		if(freq[x] == 1) {
			s++;
		}
		if(s == n) {
			std::cout << '1';
			s = 0;
			for(int i = 0; i < n; i++) {
				freq[i]--;
				if(freq[i]) {
					s++;
				}
			}
		} else {
			std::cout << '0';
		}
	}
	std::cout << '\n';
}