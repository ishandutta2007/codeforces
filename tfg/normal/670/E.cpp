#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <set>
#include <stack>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, p;
	std::cin >> n >> m >> p;
	p--;
	std::stack<int> st;
	std::string str, ops;
	std::cin >> str >> ops;
	std::set<int> curPos;
	std::vector<int> paired(n, -1);
	for(int i = 0; i < n; i++) {
		if(str[i] == '(') {
			st.push(i);
		} else {
			assert(!st.empty());
			paired[st.top()] = i;
			paired[i] = st.top();
			st.pop();
		}
		curPos.insert(i);
	}
	for(auto op : ops) {
		if(op == 'D') {
			int l = p;
			int r = paired[l];
			if(l > r) std::swap(l, r);
			curPos.erase(curPos.lower_bound(l), curPos.upper_bound(r));
			auto it = curPos.lower_bound(l);
			if(it == curPos.end()) it--;
			p = *it;
		} else {
			auto it = curPos.lower_bound(p);
			assert(it != curPos.end() && *it == p);
			if(op == 'L') {
				assert(it != curPos.begin());
				it--;
				p = *it;
			} else {
				it++;
				assert(it != curPos.end());
				p = *it;
			}
		}
	}
	std::string ans;
	for(auto hmm : curPos) {
		ans += str[hmm];
	}
	std::cout << ans << std::endl;
}