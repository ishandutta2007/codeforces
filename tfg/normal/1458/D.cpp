#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>
#include <set>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		std::string str;
		std::cin >> str;
		int n = (int) str.size();
		int sum = n;
		std::vector<std::pair<int, int>> wtf(2*n+2);
		for(auto ch : str) {
			if(ch == '0') {
				wtf[sum++].first++;
			} else {
				wtf[sum--].second++;
			}
		}
		sum = n;
		for(int i = 0; i < n; i++) {
			if(wtf[sum].first && (wtf[sum+1].second || !wtf[sum].second)) {
				wtf[sum++].first--;
				std::cout << '0';
			} else {
				wtf[sum--].second--;
				std::cout << '1';
			}
		}
		std::cout << '\n';
	}
}