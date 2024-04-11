#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <set>
#include <algorithm>
#include <utility>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, d;
	std::cin >> n >> m >> d;
	std::vector<std::pair<int, int>> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i].first;
		a[i].second = i;
	}
	std::sort(a.begin(), a.end());
	int c = 0;
	std::set<std::pair<int, int>> hmm;
	std::vector<int> ans(n, -1);
	for(int i = 0; i < n; i++) {
		int id = a[i].second;
		int v = a[i].first;
		auto it = hmm.lower_bound(std::pair<int, int>(v - d, -1));
		if(it == hmm.begin()) {
			ans[id] = c++;
		} else {
			it--;
			ans[id] = ans[it->second];
			hmm.erase(it);
		}
		hmm.insert(a[i]);
	}
	std::cout << c << std::endl;
	for(int i = 0; i < n; i++) {
		std::cout << ans[i] + 1 << (i + 1 == n ? '\n' : ' ');
	}
}