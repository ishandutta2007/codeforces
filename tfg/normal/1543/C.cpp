#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <iomanip>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 120;
const long double eps = 1e-10;

long double memo[ms][ms];
long double prob[3], v;
int step[ms][ms], curStep = 0;

long double brute(long double a, long double b) {
	long double ans;
	if(a <= v - eps) {
		ans = 1 + a;
	} else {
		ans = 1 + brute(a - v, b + v) * a;
	}
	return ans;
}

long double dp(long double a, long double b, long double c, int d0, int d1, int d2) {
	long double &ans = memo[d0][d1];
	if(step[d0][d1] == curStep) return ans;
	step[d0][d1] = curStep;
	ans = 1;
	if(a >= v + eps) {
		ans += dp(a - v, b + v / 2, c + v / 2, d0-2, d1+1, d2+1) * a;
	} else {
		ans += brute(b + a / 2, c + a / 2) * a;
	}
	if(b >= v + eps) {
		ans += dp(a + v / 2, b - v, c + v / 2, d0+1, d1-2, d2+1) * b;
	} else {
		ans += brute(a + b / 2, c + b / 2) * b;
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	std::cout << std::fixed << std::setprecision(15);
	while(t--) {
		curStep++;
		std::cin >> prob[0] >> prob[1] >> prob[2] >> v;
		std::cout << dp(prob[0], prob[1], prob[2], ms/2, ms/2, ms/2) << '\n';
	}
}