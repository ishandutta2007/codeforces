#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template <class T>
class FenwickTree {
public:
	void init(int _n) {
		this->n = _n;
		bit.assign(n + 1, 0);
	}

	T qry(int x) {
		x = std::min(x, (int)bit.size() - 1);
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
	int t;
	std::cin >> t;
	while(t--) {
		int n, m;
		std::cin >> n >> m;
		std::vector<std::pair<int, int>> a(n*m);
		for(int i = 0; i < n*m; i++) {
			std::cin >> a[i].first;
			a[i].second = i;
		}
		std::sort(a.begin(), a.end());
		std::vector<FenwickTree<int>> trees(n);
		for(int i = 0; i < n; i++) {
			trees[i].init(m+1);
		}
		std::vector<std::pair<int, int>> order(n*m);
		for(int l = 0, r = 0; l < n*m; l = r) {
			while(r < n*m && a[l].first == a[r].first) r++;
			std::vector<std::pair<int, int>> seats;
			for(int i = l; i < r; i++) {
				seats.emplace_back(i / m, - (i % m));
			}
			std::sort(seats.begin(), seats.end());
			for(int i = l; i < r; i++) {
				auto got = seats[i - l];
				got.second = -got.second;
				order[a[i].second] = got;
			}
		}
		long long ans = 0;
		for(auto [x, y] : order) {
			ans += trees[x].qry(y+1);
			trees[x].upd(y+1, 1);
		}
		std::cout << ans << '\n';
	}
}