#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cmath>
#include <iomanip>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const long double PI = acosl(-1);


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	double n, r;
	std::cin >> n >> r;
	auto test = [&](long double x) {
		long double angle = 2 * PI / n;
		long double x1 = 0, y1 = r + x;
		long double x2 = x1 * cosl(angle) - y1 * sinl(angle);
		long double y2 = y1 * cosl(angle) + sinl(angle) * x1;
		long double dx = x1-x2, dy = y1-y2;
		//std::cout << "for " << (double) x << " got (" << (double) (dx * dx + dy * dy) << ", " << (double) (x * x) << ")\n";
		return dx * dx + dy * dy <= 4 * x * x;
	};
	long double l = 0, rr = 1e18;
	for(int i = 0; i < 100; i++) {
		long double mid = (l + rr) / 2;
		if(test(mid)) {
			rr = mid;
		} else {
			l = mid;
		}
	}
	std::cout << std::setprecision(10) << std::fixed << (double) (l + rr) / 2;
}