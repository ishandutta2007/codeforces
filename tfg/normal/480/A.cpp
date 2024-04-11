#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <map>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n), b(n);
	std::map<int, std::vector<int>> wtf;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i] >> b[i];
		wtf[a[i]].push_back(b[i]);
	}
	for(auto it : wtf) {
		std::sort(it.second.begin(), it.second.end());
		if(ans <= it.second[0]) {
			ans = it.second.back();
		} else {
			ans = it.first;
		}
	}
	std::cout << ans << '\n';
}