#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <stack>

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
			std::cin >> a[n-i-1];
		}
		std::stack<int> st;
		for(auto x : a) {
			if(st.empty()) {
				st.push(x);
			} else if(st.top() > x) {
				int val = st.top();
				while(!st.empty() && st.top() > x) {
					val = st.top();
					st.pop();
				}
				st.push(val);
			} else {
				st.push(x);
			}
		}
		std::cout << ((int) st.size() == 1 ? "YES\n" : "NO\n");
	}
}