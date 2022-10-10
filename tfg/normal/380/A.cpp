#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	const int MAGIC = 1e5 + 20;
	std::vector<long long> sum(1, 0);
	std::vector<std::pair<int, int>> times(1);
	while(n--) {
		int t;
		std::cin >> t;
		if(t == 1) {
			int x;
			std::cin >> x;
			sum.push_back(sum.back() + 1);
			times.emplace_back(-1, x);
		} else {
			int len, c;
			std::cin >> len >> c;
			while(c > 0 && (int) sum.size() < MAGIC) {
				c--;
				for(int i = 1; i <= len; i++) {
					sum.push_back(sum.back() + 1);
					times.emplace_back(-1, times[i].second);
				}
			}
			if(c > 0) {
				sum.push_back(sum.back() + (long long) len * c);
				times.emplace_back(len, c);
			}
		}
	}
	std::cin >> n;
	while(n--) {
		long long id;
		std::cin >> id;
		id--;
		auto pos = std::upper_bound(sum.begin(), sum.end(), id) - sum.begin();
		assert(pos < (int) sum.size() && pos != 0);
		if(times[pos].first == -1) {
			std::cout << times[pos].second << (n ? ' ' : '\n');
		} else {
			id -= sum[pos-1];
			std::cout << times[1 + (int) (id % times[pos].first)].second << (n ? ' ' : '\n');
		}
	}
}