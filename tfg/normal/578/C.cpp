#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <iomanip>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;

int n;
int a[ms];

long double eval(long double x) {
	long double mx = 0, mn = 0, sum = 0;
	for(int i = 0; i < n; i++) {
		sum += a[i] - x;
		mx = std::max(mx, sum);
		mn = std::min(mn, sum);
	}
	return mx - mn;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	long double l = -ms, r = ms;
	for(int rep = 0; rep < 200; rep++) {
		long double t = (r - l) / 3;
		long double x1 = l + t, x2 = l + 2 * t;
		if(eval(x1) >= eval(x2)) {
			l = x1;
		} else {
			r = x2;
		}
	}
	std::cout << std::fixed << std::setprecision(15) << (double) eval((l + r) / 2) << '\n';
}