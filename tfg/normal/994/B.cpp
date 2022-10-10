#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <queue>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::priority_queue<int, std::vector<int>, std::greater<int>> hp;
	long long sum = 0;
	std::vector<int> p(n), c(n), a(n);
	for(int i = 0; i < n; i++) {
		a[i] = i;
		std::cin >> p[i];
	}
	for(int i = 0; i < n; i++) {
		std::cin >> c[i];
	}
	std::sort(a.begin(), a.end(), [&](int v1, int v2) { return p[v1] < p[v2]; });
	std::vector<long long> ans(n);
	for(auto id : a) {
		while((int) hp.size() > k) {
			sum -= hp.top();
			hp.pop();
		}
		hp.push(c[id]);
		sum += c[id];
		ans[id] = sum;
	}
	for(int i = 0; i < n; i++) {
		std::cout << ans[i] << (i + 1 == n ? '\n' : ' ');
	}
}