#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <iomanip>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cout << std::fixed << std::setprecision(10);
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i].first >> a[i].second;
	}
	const int ms = 100100;
	std::vector<double> prob(ms, 0);
	for(int i = 0; i < ms; i++) {
		std::vector<double> p(n+1, 0);
		p[0] = 1;
		for(int j = 0; j < n; j++) {
			double greater = (double) std::max(0, a[j].second - std::max(i, a[j].first) + 1) / (a[j].second - a[j].first + 1);
			double lesser = 1 - greater;
			std::vector<double> wtf(n+1, 0);
			for(int k = 0; k+1 <= n; k++) {
				wtf[k] += p[k] * lesser;
				wtf[k+1] += p[k] * greater;
			}
			wtf.swap(p);
		}
		for(int k = 2; k <= n; k++) {
			prob[i] += p[k];
		}
	}
	double ans = 0;
	for(int i = 0; i+1 < ms; i++) {
		prob[i] -= prob[i+1];
		ans += prob[i] * i;
	}
	std::cout << ans << '\n';
}