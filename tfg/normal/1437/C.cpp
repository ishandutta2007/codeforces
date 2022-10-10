#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		std::sort(a.begin(), a.end());
		int ans = 0;
		for(int i = 0; i < n; i++) {
			a[i] -= i+1;
			if(a[i] < 0) {
				ans += -a[i];
				a[i] = 0;
			}
		}
		std::priority_queue<int> pq;
		for(int i = 0; i < n; i++) {
			int x = a[i];
			pq.push(x);
			if(pq.top() > x) {
				ans += pq.top() - x;
				pq.pop();
				pq.push(x);
			}
		}
		std::cout << ans << '\n';
	}
}