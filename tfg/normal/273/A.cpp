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

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	ColorUpdate<long long> col;
	for(int i = 0; i < n; i++) {
		long long x;
		std::cin >> x;
		col.upd(i, i+1, x);
	}
	int q;
	std::cin >> q;
	while(q--) {
		long long x;
		int r;
		int l = 0;
		std::cin >> r >> x;
		long long ans = 0;
		for(auto range : col.erase(l, r)) ans = std::max(ans, range.v);
		std::cout << ans << '\n';
		col.upd(l, r, ans + x);
	}
}