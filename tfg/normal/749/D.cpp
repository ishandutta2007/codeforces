#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <set>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> person(n);
	std::vector<int> a(n), b(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i] >> b[i];
		a[i]--;
		person[a[i]].push_back(b[i]);
	}
	std::vector<int> order;
	for(int i = n-1; i >= 0; i--) {
		if(b[i] == person[a[i]].back()) {
			order.push_back(a[i]);
		}
	}
	int q;
	std::cin >> q;
	while(q--) {
		int k;
		std::cin >> k;
		std::set<int> got;
		while(k--) {
			int x;
			std::cin >> x;
			got.insert(x-1);
		}
		std::vector<int> wtf;
		for(int i = 0; i < (int) order.size() && (int) wtf.size() < 2; i++) {
			if(!got.count(order[i])) {
				wtf.push_back(order[i]);
			}
		}
		if(wtf.size() == 0) {
			std::cout << "0 0\n";
		} else if(wtf.size() == 1) {
			std::cout << wtf[0] + 1 << ' ' << person[wtf[0]][0] << '\n';
		} else {
			std::cout << wtf[0] + 1 << ' ';
			std::cout << *std::lower_bound(person[wtf[0]].begin(), person[wtf[0]].end(), person[wtf[1]].back()) << '\n';
		}
	}
}