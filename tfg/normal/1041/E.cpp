#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <utility>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> freq(n + 1, 0);
	for(int i = 1; i < n; i++) {
		int x, y;
		std::cin >> x >> y;
		if(y != n || x == n) {
			std::cout << "NO\n";
			return 0;
		}
		freq[x]++;
	}
	std::vector<int> buffer;
	std::vector<std::pair<int, int>> ans;
	for(int i = 1; i < n; i++) {
		if(freq[i] == 0) {
			buffer.push_back(i);
		} else if(freq[i] - 1 > (int) buffer.size()) {
			std::cout << "NO\n";
			return 0;
		} else {
			int on = i;
			while(freq[i] > 1) {
				ans.emplace_back(on, buffer.back());
				freq[i]--;
				on = buffer.back();
				buffer.pop_back();
			}
			ans.emplace_back(on, n);
		}
	}
	std::cout << "YES\n";
	for(auto e : ans) {
		std::cout << e.first << ' ' << e.second << '\n';
	}
}