#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::vector<int> st;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int v = a[i];
		while(!st.empty() && st.back() <= v) {
			ans = std::max(ans, v ^ st.back());
			st.pop_back();
		}
		if(!st.empty()) {
			ans = std::max(ans, v ^ st.back());
		}
		st.push_back(v);
	}
	std::cout << ans << '\n';
}