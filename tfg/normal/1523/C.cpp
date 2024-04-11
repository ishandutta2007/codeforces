#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		std::vector<int> st;
		for(int i = 0; i < n; i++) {
			int val;
			std::cin >> val;
			if(val == 1) {
				st.push_back(val);
			} else {
				while(!st.empty() && st.back() != val-1) {
					st.pop_back();
				}
				assert(!st.empty());
				st.back()++;
			}
			for(int j = 0; j < (int) st.size(); j++) {
				std::cout << st[j] << (j + 1 == (int) st.size() ? '\n' : '.');
			}
		}
	}
}