#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long solve(const std::vector<int> &a) {
	long long sum = 0, cur = 0;
	for(auto x : a) {
		cur = std::max(0LL, cur + x);
		sum = std::max(sum, cur);
	}
	return sum;
}

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	if(n % 2) {
		a.push_back(0);
		n++;
	}
	long long sum = 0;
	std::vector<int> wtf[2];
	for(int i = 0; i < n; i += 2) {
		wtf[0].push_back(a[i+1]-a[i]);
		sum += a[i];
	}
	for(int i = 2; i < n; i += 2) {
		wtf[1].push_back(a[i-1] - a[i]);
	}
	std::cout << sum + std::max(solve(wtf[0]), solve(wtf[1])) << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}