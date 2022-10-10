#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int special(std::vector< std::pair<int, int> > v) {
	std::sort(v.begin(), v.end());
	int ans = 3;
	if(v[0].first == v[1].first && (v[0].second >= v[2].second || v[1].second <= v[2].second)) {
		ans = 2;
	}
	if(v[1].first == v[2].first && (v[0].second <= v[1].second || v[0].second >= v[2].second)) {
		ans = 2;
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int x1, y1, x2, y2, x3, y3;
	std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	int ans = 3;
	if((x1 == x2) && (x2 == x3)) {
		ans = 1;
	}
	if((y1 == y2) && (y2 == y3)) {
		ans = 1;
	}
	std::vector< std::pair<int, int> > v;
	v.emplace_back(x1, y1);
	v.emplace_back(x2, y2);
	v.emplace_back(x3, y3);
	ans = std::min(ans, special(v));
	for(auto &p : v) std::swap(p.first, p.second);
	ans = std::min(ans, special(v));
	std::cout << ans << '\n';
}