#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Bucket {
	std::vector<int> a, dp;
	int lazy = 0;
	bool flag = false;

	void push_back(int x) {
		assert(x < 0);
		//std::cout << "pushing " << x << '\n';
		a.push_back(x);
		dp.push_back(0);
	}

	void upd(int l, int r, int x) {
		l = std::max(l, 0);
		r = std::min(r, (int) a.size());
		//std::cout << "updating [" << l << ", " << r << ")\n";
		if(r <= l) assert(0);
		if(flag || r - l != (int) dp.size()) {
			for(int i = l; i < r; i++) {
				a[i] = std::max(a[i] - x, -1001000);
			}
			init();
		} else {
			lazy = std::min(lazy + x, 1001000);
		}
	}

	void init() {
		flag = false;
		for(int i = 0; i < (int) a.size(); i++) {
			int to = i + a[i] - lazy;
			dp[i] = to < 0 ? i : dp[to];
			flag = flag || dp[i] != i;
		}
	}

	int big(int on) { return dp[on] - on; }
	int small(int on) { return a[on] - lazy; }
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, q;
	std::cin >> n >> q;
	const int bs = 330;
	std::vector<Bucket> buckets(n / bs + 10);
	for(int i = 0; i < n; i++) {
		int x = 0;
		if(i) std::cin >> x;
		buckets[i / bs].push_back(x-1 - i);
	}
	for(int i = 0; i < (int) buckets.size(); i++) {
		buckets[i].init();
	}
	while(q--) {
		int t;
		std::cin >> t;
		if(t == 1) {
			int l, r, x;
			std::cin >> l >> r >> x;
			l--;r--;
			for(int i = l / bs; i <= r / bs; i++) {
				buckets[i].upd(l - i * bs, r+1 - i * bs, x);
			}
		} else {
			int u, v;
			std::cin >> u >> v;
			u--;v--;
			//std::cout << "at (" << u << ", " << v << ")\n";
			while(u != v) {
				if(u < v) std::swap(u, v);
				if(u / bs != v / bs) {
					//std::cout << "first case!\n";
					//int bu = u/bs;
					u += buckets[u/bs].big(u%bs);
					//assert(bu == u/bs);
					u = std::max(0, u + buckets[u/bs].small(u%bs));
				} else if(buckets[u/bs].big(u%bs) == 0 || buckets[u/bs].big(u%bs) + u == buckets[u/bs].big(v%bs) + v) {
					//std::cout << "second case!\n";
					u = std::max(0, u + buckets[u/bs].small(u%bs));
				} else {
					//std::cout << "third case!\n";
					u += buckets[u/bs].big(u%bs);
					v += buckets[v/bs].big(v%bs);
				}
				//std::cout << "at (" << u << ", " << v << ")\n";
			}
			std::cout << u+1 << '\n';
		}
	}
}