#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::vector<std::vector<int>> test(int n, int extra, int k) {
	std::vector<std::vector<int>> ans;
	std::vector<int> vals(n, 1);
	for(int i = 0; i < n; i++) vals[i] += extra / n * 2 + (i < extra % n) * 2;
	if(vals[0] * k > (n + 2 * extra)) return ans;
	//for(int i = 0; i < n; i++) std::cout << vals[i] << (i + 1 == n ? '\n' : ' ');
	std::priority_queue<std::pair<int, int>> hp;
	for(int i = 0; i < n; i++) hp.push({vals[i], i});
	//std::cout << "testing (" << n << ", " << extra << ", " << k << ")" << std::endl;
	while(!hp.empty()) {
		std::vector<int> got;
		if((int) hp.size() < k) {
			ans.clear();
			return ans;
		}
		for(int i = 0; i < k; i++) {
			got.push_back(hp.top().second);
			hp.pop();
		}
		ans.push_back(got);
		for(auto x : got) {
			vals[x]--;
			if(vals[x] > 0) {
				hp.push({vals[x], x});
			}
		}
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	for(int extra = 0; (n + 2 * extra) / k <= 500; extra++) {
		if((n + 2 * extra) % k == 0) {
			auto ans = test(n, extra, k);
			if(!ans.empty()) {
				int tot = 0;
				for(auto arr : ans) {
					std::cout << "?";
					for(auto x : arr) {
						std::cout << ' ' << x+1;
					}
					std::cout << std::endl;
					int kek;
					std::cin >> kek;
					tot ^= kek;
				}
				std::cout << "! " << tot << std::endl;
				return 0;
			}
		}
	}
	std::cout << "-1" << std::endl;
}