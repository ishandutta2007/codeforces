#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <stack>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::stack<std::pair<int, int>> st;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[n-i-1];
	}
	int ans = 0;
	for(auto v : a) {
		int got = 0;
		while(!st.empty() && v > st.top().first) {
			got = std::max(st.top().second, got + 1);
			st.pop();
		}
		st.push(std::pair<int, int>(v, got));
		ans = std::max(ans, got);
	}
	std::cout << ans << '\n';
}