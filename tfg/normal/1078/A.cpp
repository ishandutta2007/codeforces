#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <cmath>
#include <iomanip>

typedef long double ld;

//std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long a, b, c;
std::vector<std::pair<std::pair<ld, ld>, ld>> gen(long long x, long long y) {
	std::vector<std::pair<std::pair<ld, ld>, ld>> ans;
	// same x
	// a * x + b * y + c == 0
	// y = (-c - a * x) / b
	if(b != 0) {
		ld cur;
		cur = (-c - a * x) / (ld) b;
		ans.emplace_back(std::pair<ld, ld>(x, cur), fabsl(cur - y));
	}
	if(a != 0) {
		ld cur;
		cur = (-c - b * y) / (ld) a;
		ans.emplace_back(std::pair<ld, ld>(cur, y), fabsl(cur - x));
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::vector<std::pair<std::pair<ld, ld>, ld>> p1, p2;
	std::cin >> a >> b >> c;
	long long x1, y1, x2, y2;
	std::cin >> x1 >> y1 >> x2 >> y2;
	p1 = gen(x1, y1);
	p2 = gen(x2, y2);
	ld ans = std::max(x1-x2, x2-x1) + std::max(y1-y2, y2-y1);
	for(auto t1 : p1) {
		for(auto t2 : p2) {
			ld dx = t1.first.first - t2.first.first;
			ld dy = t1.first.second - t2.first.second;
			ans = std::min(ans, sqrtl(dx * dx + dy * dy) + t1.second + t2.second);
		}
	}
	std::cout << std::fixed << std::setprecision(15) << ans << '\n';
}