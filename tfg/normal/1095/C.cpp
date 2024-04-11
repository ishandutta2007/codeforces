#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::vector<int> freq;
	int got = 0;
	for(int i = 0; (1 << i) <= n; i++) {
		freq.push_back(0);
		if(n & (1 << i)) {
			freq[i]++;
			got++;
		}
	}
	if(got > k || k > n) {
		std::cout << "NO\n";
		return 0;
	}
	int x = (int) freq.size() - 1;
	while(got < k) {
		while(!freq[x]) {
			x--;
		}
		freq[x]--;
		freq[x-1] += 2;
		got++;
	}
	std::cout << "YES\n";
	bool gott = false;
	for(int i = 0; i < (int) freq.size(); i++) {
		while(freq[i]--) {
			if(gott) {
				std::cout << ' ';
			} else {
				gott = true;
			}
			std::cout << (1 << i);
		}
	}
	std::cout << '\n';
}