#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	int mx = 0;
	std::vector<int> a(n), b(n);
	std::set<int> st;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		if(a[i] != mx) {
			b[i] = mx;
			st.insert(mx);
			mx = a[i];
		} else {
			b[i] = -1;
		}
	}
	st.insert(mx);
	for(int i = 0, j = 0; i < n; i++) {
		while(st.count(j)) j++;
		if(b[i] == -1) {
			b[i] = j;
			st.insert(j);
		} else if(j < a[i]) {
			std::cout << "-1\n";
			return 0;
		}
	}
	for(int i = 0; i < n; i++) {
		std::cout << b[i] << (i + 1 == n ? '\n' : ' ');
	}
}