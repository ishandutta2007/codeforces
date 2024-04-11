#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>
#include <iomanip>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, T;
	std::cin >> n >> T;
	std::vector<std::pair<int, int>> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i].second;
	}
	for(int i = 0; i < n; i++) {
		std::cin >> a[i].first;
	}
	long long sumT = 0, sumX = 0;
	for(auto p : a) {
		sumT += (long long) p.first * p.second;
		sumX += p.second;
	}
	if(sumT == sumX * T) {
		std::cout << sumX << '\n';
		return 0;
	}
	if(sumT >= sumX * T) {
		//std::cout << "first case\n";
		std::sort(a.rbegin(), a.rend());
		for(auto p : a) {
			if((sumT - (long long) p.first * p.second) <= (sumX - p.second) * T) {
				long long cur = sumT - sumX * T;
				long long delta = -p.first + T;
				std::cout << std::fixed << std::setprecision(10) << sumX + (long double) cur / (delta) << '\n';
				return 0;
			}
			sumT -= (long long) p.first * p.second;
			sumX -= p.second;
		}
	} else {
		//std::cout << "second case\n";
		std::sort(a.begin(), a.end());
		for(auto p : a) {
			if((sumT - (long long) p.first * p.second) >= (sumX - p.second) * T) {
				long long cur = sumT - sumX * T;
				long long delta = -p.first + T;
				std::cout << std::fixed << std::setprecision(10) << sumX + (long double) cur / (delta) << '\n';
				return 0;
			}
			sumT -= (long long) p.first * p.second;
			sumX -= p.second;
		}

	}
	std::cout << 0 << '\n';
}