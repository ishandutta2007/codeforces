#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 101;

int freq[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		int s;
		std::cin >> s;
		while(s--) {
			int v;
			std::cin >> v;
			freq[v]++;
		}
	}
	std::vector<int> ans;
	for(int i = 0; i < ms; i++) {
		if(freq[i] == n) {
			ans.push_back(i);
		}
	}
	for(int i = 0; i < (int) ans.size(); i++) {
		std::cout << ans[i] << (i + 1 == (int) ans.size() ? '\n' : ' ');
	}
}