#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template <class Info = int, class T = int>
struct ColorUpdate {
public:
	struct Range {
		Range(T _l = 0) : l(_l) {}
		Range(T _l, T _r, Info _v) : l(_l), r(_r), v(_v) { }
		T l, r;
		Info v;

		bool operator < (const Range &b) const { return l < b.l; }
	};

	std::vector<Range> erase(T l, T r) {
		std::vector<Range> ans;
		if(l >= r) return ans;
		auto it = ranges.lower_bound(l);
		if(it != ranges.begin()) {
			it--;
			if(it->r > l) {
				auto cur = *it;
				ranges.erase(it);
				ranges.insert(Range(cur.l, l, cur.v));
				ranges.insert(Range(l, cur.r, cur.v));
			}
		}
		it = ranges.lower_bound(r);
		if(it != ranges.begin()) {
			it--;
			if(it->r > r) {
				auto cur = *it;
				ranges.erase(it);
				ranges.insert(Range(cur.l, r, cur.v));
				ranges.insert(Range(r, cur.r, cur.v));
			}
		}
		for(it = ranges.lower_bound(l); it != ranges.end() && it->l < r; it++) {
			ans.push_back(*it);
		}
		ranges.erase(ranges.lower_bound(l), ranges.lower_bound(r));
		return ans;
	}

	std::vector<Range> upd(T l, T r, Info v) {
		auto ans = erase(l, r);
		ranges.insert(Range(l, r, v));
		return ans;
	}

	bool exists(T x) {
		auto it = ranges.upper_bound(x);
		if(it == ranges.begin()) return false;
		it--;
		return it->l <= x && x < it->r;
	}
	std::set<Range> ranges;
};

struct CrazySet {
	ColorUpdate<bool, long long> ranges;
	bool inverted = false;
	long long lazy = 0;

	void addLazy(long long x) {
		lazy += x;
	}

	void invert() {
		lazy = -lazy;
		inverted = !inverted;
	}

	void addRange(long long l, long long r) {
		if(!inverted) {
			ranges.upd(l-lazy, r-lazy, true);
		} else {
			ranges.upd(-r+1+lazy, -l+1+lazy, true);
		}
	}

	void removeRange(long long l, long long r) {
		if(!inverted) {
			ranges.erase(l-lazy, r-lazy);
		} else {
			ranges.erase(-r+1+lazy, -l+1+lazy);
		}
	}

	bool exists(long long x) {
		if(!inverted) {
			return ranges.exists(x - lazy);
		} else {
			return ranges.exists(-x + lazy);
		}
	}

	bool empty() { return ranges.ranges.empty(); }
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	const int INF = 1e9;
	while(t--) {
		int n;
		std::cin >> n;
		CrazySet wtf;
		int ans = 0;
		while(n--) {
			int x;
			std::cin >> x;
			wtf.removeRange(x, INF);
			if(wtf.empty()) {
				wtf.addRange(1, x);
				ans++;
			}
			wtf.invert();
			wtf.addLazy(x);
			if(x % 2 == 0) {
				if(wtf.exists(x / 2)) {
					wtf.removeRange(1, INF);
					wtf.addRange(x / 2, x / 2 + 1);
				} else {
					ans++;
					wtf.addRange(x / 2, x / 2 + 1);
				}
			} else {
				ans++;
			}
		}
		std::cout << ans << '\n';
	}
}