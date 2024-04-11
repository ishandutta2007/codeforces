#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <utility>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;

struct FenwickTree {
	long long bit[ms];
	FenwickTree() {
		for(int i = 0; i < ms; i++) {
			bit[i] = 0;
		}
	}

	int lift(int k) {
		int x = 0;
		for(int i = 19; i >= 0; i--) {
			if(x + (1 << i) >= ms) continue;
			int nx = x + (1 << i);
			if(bit[nx] < k) {
				k -= (int) bit[nx];
				x = nx;
			}
		}
		return x;
	}

	void upd(int x, long long v) {
		for(; x < ms; x += x & -x) {
			bit[x] += v;
		}
	}

	long long qry(int x) {
		long long ans = 0;
		for(; x > 0; x -= x & -x) {
			ans += bit[x];
		}
		return ans;
	}
};

FenwickTree freq, sum;
std::vector<std::pair<int, int>> add[5 * ms], del[5 * ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k, m;
	std::cin >> n >> k >> m;
	std::vector<int> vals;
	for(int i = 0; i < m; i++) {
		int l, r, c, p;
		std::cin >> l >> r >> c >> p;
		add[l].emplace_back(c, p);
		del[r + 1].emplace_back(c, p);
		vals.push_back(p);
	}
	std::sort(vals.begin(), vals.end());
	long long ans = 0;
	for(int i = 1; i <= n; i++) {
		for(auto &e : add[i]) {
			//std::cout << "adding (" << e.first << ", " << e.second << ")\n";
			e.second = std::lower_bound(vals.begin(), vals.end(), e.second) - vals.begin();
			//std::cout << "index is " << e.second << "\n";
			freq.upd(e.second + 1, e.first);
			sum.upd(e.second + 1, (long long) e.first * vals[e.second]);
		}
		for(auto &e : del[i]) {
			//std::cout << "deleting (" << e.first << ", " << e.second << ")\n";
			e.second = std::lower_bound(vals.begin(), vals.end(), e.second) - vals.begin();
			//std::cout << "index is " << e.second << "\n";
			freq.upd(e.second + 1, -e.first);
			sum.upd(e.second + 1, (long long) -e.first * vals[e.second]);
		}
		int idx = freq.lift(k);
		//std::cout << "on day " << i << " got idx " << idx << "\n";
		ans += sum.qry(idx);
		//std::cout << "summed base " << sum.qry(idx) << "\n";
		if(idx < m) {
			ans += (k - freq.qry(idx)) * vals[idx];
			//std::cout << "summed rest " << (k - freq.qry(idx)) * vals[idx] << ", " << (k - freq.qry(idx)) << " cores of price " << vals[idx] << "\n";
		}
	}
	std::cout << ans << std::endl;
}