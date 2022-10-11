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
	std::vector<long long> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	long long ans = 0;
	for(int rep = 0; rep < 2; rep++) {
		std::stack<int> st;
		std::vector<int> left(n, -1), right(n, n);
		for(int i = 0; i < n; i++) {
			while(!st.empty() && a[i] >= a[st.top()]) {
				right[st.top()] = i;
				st.pop();
			}
			if(!st.empty()) {
				left[i] = st.top();
			}
			st.push(i);
		}
		for(int i = 0; i < n; i++) {
			ans += a[i] * (i - left[i]) * (right[i] - i);
		}
		for(auto &x : a) x = -x;
	}
	std::cout << ans << '\n';
}