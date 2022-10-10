#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <stack>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string str;
	std::cin >> str;
	std::stack<char> st;
	for(auto ch : str) {
		if(!st.empty() && st.top() == ch) {
			st.pop();
		} else {
			st.push(ch);
		}
	}
	std::cout << (st.empty() ? "Yes\n" : "No\n");
}