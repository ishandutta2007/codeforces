#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::priority_queue<long long> hp, a;
	long long ans = 0;
	for(int i = 0; i <= k; i++) {
		hp.push(0);
	}
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		a.push(x);
	}
	while(!a.empty()) {
		long long val = hp.top();
		ans += val;
		hp.pop();
		val += a.top();
		a.pop();
		hp.push(val);
	}
	std::cout << ans << '\n';
}