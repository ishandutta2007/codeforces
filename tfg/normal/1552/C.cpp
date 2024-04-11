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
		int n, k;
		std::cin >> n >> k;
		n *= 2;
		std::vector<std::pair<int, int>> pairs(k);
		std::vector<bool> got(n, false);
		std::vector<int> a;
		for(int i = 0; i < k; i++) {
			std::cin >> pairs[i].first >> pairs[i].second;
			pairs[i].first--, pairs[i].second--;
			got[pairs[i].first] = got[pairs[i].second] = true;
		}
		for(int i = 0; i < n; i++) {
			if(!got[i]) {
				a.push_back(i);
			}
		}
		assert((int) a.size() % 2 == 0);
		for(int i = 0; i * 2 < (int) a.size(); i++) {
			pairs.emplace_back(a[i], a[i + (int) a.size() / 2]);
		}
		for(auto &p : pairs) if(p.first > p.second) std::swap(p.first, p.second);
		n /= 2;
		assert((int) pairs.size() == n);
		int ans = 0;
		auto between = [](std::pair<int, int> range, int v) { return range.first <= v && v <= range.second; };
		for(int i = 0; i < n; i++) for(int j = i+1; j < n; j++) if(between(pairs[i], pairs[j].first) != between(pairs[i], pairs[j].second)) {
			ans++;
		}
		std::cout << ans << '\n';
	}
}