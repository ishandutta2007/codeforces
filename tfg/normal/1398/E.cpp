#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::multiset<int> st[4];
	int q;
	std::cin >> q;
	int f[2] = {0, 0};
	long long sum[2] = {0, 0};
	while(q--) {
		int tp, d;
		std::cin >> tp >> d;
		if(d < 0) {
			d = -d;
			sum[0] -= d;
			st[tp].erase(st[tp].find(d));
			f[tp]--;
			if(st[2].find(d) != st[2].end()) {
				sum[1] -= d;
				st[2].erase(st[2].find(d));
			} else {
				st[3].erase(st[3].find(d));
			}
		} else {
			sum[0] += d;
			st[tp].insert(d);
			f[tp]++;
			if(!st[2].empty() && d >= *st[2].begin()) {
				sum[1] += d;
				st[2].insert(d);
			} else {
				st[3].insert(d);
			}
		}
		while((int) st[2].size() > f[1]) {
			sum[1] -= *st[2].begin();
			st[3].insert(*st[2].begin());
			st[2].erase(st[2].begin());
		}
		while((int) st[2].size() < f[1]) {
			auto it = st[3].end();
			it--;
			sum[1] += *it;
			st[2].insert(*it);
			st[3].erase(it);
		}
		if(f[0] == 0 && f[1] == 0) {
			std::cout << "0\n";
		} else if(f[0] == 0) {
			std::cout << 2 * sum[0] - *st[1].begin() << '\n';
		} else if(f[1] == 0) {
			std::cout << sum[0] << '\n';
		} else if(*st[0].rbegin() >= *st[1].begin()) {
			std::cout << sum[0] + sum[1] << '\n';
		} else {
			std::cout << sum[0] + sum[1] - *st[1].begin() + *st[0].rbegin() << '\n';
		}
	}
}