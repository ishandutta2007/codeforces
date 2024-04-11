#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <set>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<std::pair<int, int>>> a(n);
	for(int i = 1; i <= m; i++) {
		int x, y;
		std::cin >> x >> y;
		x = n - x;
		y--;
		if(x > y) std::swap(x, y);
		a[x].emplace_back(y, i);
	}
	std::multiset<std::pair<int, int>> wtf;
	std::vector<int> ans;
	for(int i = 0; i < n; i++) {
		for(auto x : a[i]) wtf.insert(x);
		while(!wtf.empty() && wtf.begin()->first < i) wtf.erase(wtf.begin());
		if(!wtf.empty()) {
			ans.push_back(wtf.begin()->second);
			wtf.erase(wtf.begin());
		}
	}
	std::cout << ans.size() << '\n';
	std::sort(ans.begin(), ans.end());
	for(int i = 0; i < (int) ans.size(); i++) {
		std::cout << ans[i] << (i + 1 == (int) ans.size() ? '\n' : ' ');
	}
}