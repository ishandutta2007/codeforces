#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	long long x1, y1, x2, y2;
	std::cin >> n >> x1 >> y1 >> x2 >> y2;
	std::vector<std::pair<long long, long long> > pts(n);
	for(int i = 0; i < n; i++) {
		long long x3, y3;
		std::cin >> x3 >> y3;
		long long dx, dy;
		dx = x3 - x1, dy = y3 - y1;
		pts[i].first = dx * dx + dy * dy;
		dx = x3 - x2, dy = y3 - y2;
		pts[i].second = dx * dx + dy * dy;
		//std::cout << "(" << pts[i].first << ", " << pts[i].second << ")\n";
	}
	std::sort(pts.begin(), pts.end());
	long long tot = 1e18;
	for(int i = 0; i <= n; i++) {
		long long ans1 = 0, ans2 = 0;
		for(int j = 0; j < n; j++) {
			if(j < i) {
				ans1 = std::max(ans1, pts[j].first);
			} else {
				ans2 = std::max(ans2, pts[j].second);
			}
		}
		tot = std::min(tot, ans1 + ans2);
	}
	std::cout << tot << '\n';
}