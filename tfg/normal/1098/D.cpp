#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <set>
#include <algorithm>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template <class T>
class FenwickTree {
public:
	void init(int s) {
		this->n = s;
		bit.assign(n + 1, 0);
	}

	T qry(int x) {
		x = std::min(x, n);
		T ans = 0;
		for(; x > 0; x -= x & -x) {
			ans += bit[x];
		}
		return ans;
	}

	void upd(int x, T v) {
		if(x <= 0) return;
		for(; x <= n; x += x & -x) {
			bit[x] += v;
		}
	}
private:
	int n;
	std::vector<T> bit;
};


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int q;
	std::cin >> q;
	std::vector<int> u;
	std::vector<std::pair<char, int>> query(q);
	for(int i = 0; i < q; i++) {
		std::cin >> query[i].first >> query[i].second;
		u.push_back(query[i].second);
	}
	std::sort(u.begin(), u.end());
	u.resize(std::unique(u.begin(), u.end()) - u.begin());
	FenwickTree<long long> tree;
	tree.init((int) u.size());
	std::multiset<long long> values;
	for(auto qu : query) {
		if(qu.first == '-') {
			int on = std::upper_bound(u.begin(), u.end(), qu.second) - u.begin();
			tree.upd(on, -qu.second);
			values.erase(values.lower_bound(qu.second));
		} else {
			int on = std::upper_bound(u.begin(), u.end(), qu.second) - u.begin();
			tree.upd(on, qu.second);
			values.insert(qu.second);
		}
		if(values.size() == 0) {
			std::cout << "0\n";
			continue;
		}
		int on = std::lower_bound(u.begin(), u.end(), *values.begin()) - u.begin();
		on++;
		int ans = (int) values.size();
		while(true) {
			long long sum = tree.qry(on);
			//std::cout << "on " << on << " has sum " << sum << '\n';
			auto it = values.lower_bound(sum * 2);
			if(it == values.end()) {
				ans--;
				break;
			}
			int to = std::lower_bound(u.begin(), u.end(), *it) - u.begin();
			to += 1;
			assert(to != on);
			sum = tree.qry(to-1);
			if(sum * 2 < *it) {
				ans--;
			}
			on = to;
		}
		std::cout << ans << '\n';
	}
}