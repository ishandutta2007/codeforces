#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::set<int> both;
	std::vector<int> ans;
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		int x;
		std::cin >> x;
		if(x < 0) {
			if(!both.count(-x) || both.count(x)) {
				std::cout << "-1\n";
				return 0;
			}
			both.insert(x);
			sum--;
		} else {
			if(both.count(x)) {
				std::cout << "-1\n";
				return 0;
			}
			both.insert(x);
			sum++;
		}
		if(sum == 0) {
			ans.push_back(both.size());
			both.clear();
		}
	}
	if(both.empty()) {
		std::cout << ans.size() << '\n';
		for(int i = 0; i < (int) ans.size(); i++) {
			std::cout << ans[i] << (i + 1 == (int) ans.size() ? '\n' : ' ');
		}
	} else {
		std::cout << "-1\n";
	}
}