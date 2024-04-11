#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <set>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template <class Info = int>
class ColorUpdate {
public:
	struct Range {
		Range(int ll = 0) { this->l = ll; }
		Range(int ll, int rr, Info vv) {
			this->l = ll;
			this->r = rr;
			this->v = vv;
		}
		int l, r;
		Info v;

		bool operator < (const Range &b) const { return l < b.l; }
	};

	std::vector<Range> upd(int l, int r, Info v, bool ha = true) {
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
		if(ha) ranges.insert(Range(l, r, v));
		return ans;
	}
private:
	std::set<Range> ranges;
};


struct Query {
	Query(int a, int b, int c) : l(a), r(b), v(c) {}
	int l, r, v;
	bool operator < (const Query &o) const { return v > o.v; }
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int m, n;
	std::cin >> m >> n;
	std::vector<long long> ans(n+1, 0);
	while(m--) {
		int size;
		std::cin >> size;
		std::vector<Query> qries;
		qries.emplace_back(0, n-size, 0);
		qries.emplace_back(n-(n-size), n, 0);
		for(int i = 0; i < size; i++) {
			int x;
			std::cin >> x;
			qries.emplace_back(i, n-size+i+1, x);
		}
		std::sort(qries.begin(), qries.end());
		ColorUpdate<int> colors;
		colors.upd(0, n, -1, true);
		for(auto qry : qries) {
			auto ranges = colors.upd(qry.l, qry.r, 0);
			for(auto lul : ranges) {
				if(lul.v == -1) {
					ans[lul.l] += qry.v;
					ans[lul.r] -= qry.v;
				}
			}
		}
	}
	for(int i = 0; i < n; i++) {
		if(i) ans[i] += ans[i-1];
		std::cout << ans[i] << (i+1==n?'\n':' ');
	}
}