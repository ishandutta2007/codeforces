#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> pos(n);
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		x--;
		pos[x].push_back(i);
	}
	std::vector<int> l(n), r(n);
	std::set<int> st;
	st.insert(-1);
	st.insert(n);
	for(int i = 0; i < n; i++) {
		if(pos[i].empty()) {
			l[i] = -1, r[i] = -1;
			continue;
		}
		auto itr = st.lower_bound(pos[i][0]);
		auto itl = itr;
		itl--;
		if(pos[i].back() >= *itr) {
			l[i] = -1, r[i] = -1;
		} else if((int) pos[i].size() == 1) {
			l[i] = 1, r[i] = (*itr - *itl) - 1;
		} else {
			l[i] = (*itr - *itl) - 1, r[i] = (*itr - *itl) - 1;
		}
		for(auto x : pos[i]) {
			st.insert(x);
		}
	}
	// for size SZ to be true
	// every r[i>=SZ] < SZ
	// every l[i<SZ] <= SZ <= r[i<SZ]
	auto mx = r;
	for(int i = n-2; i >= 0; i--) {
		mx[i] = std::max(mx[i], mx[i+1]);
	}
	for(int i = 0; i < n; i++) {
		//std::cout << "[" << l[i] << ", " << r[i] << "]\n";
	}
	mx.push_back(-1);
	int range[2] = {0, n};
	std::string str(n, '0');
	for(int i = 1; i <= n; i++) {
		range[0] = std::max(range[0], l[i-1]);
		range[1] = std::min(range[1], r[i-1]);
		int id = n-i+1;
		if(range[0] <= id && id <= range[1]) {
			str[id-1] = '1';
		}
	}
	std::cout << str << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}