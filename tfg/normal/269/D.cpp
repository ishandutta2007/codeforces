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

	std::vector<Range> upd(int l, int r, Info v) {
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
		ranges.insert(Range(l, r, v));
		return ans;
	}
private:
	std::set<Range> ranges;
};

struct Segment {
	int l, r, h;
	bool operator < (const Segment &seg) const { return h > seg.h; }
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, t;
	std::cin >> n >> t;
	const int INF = 1e9;
	std::vector<Segment> segs;
	std::vector<int> dp(n+2, 0);
	for(int i = 0; i < n; i++) {
		Segment seg;
		std::cin >> seg.h >> seg.l >> seg.r;
		segs.push_back(seg);
	}
	{
		Segment seg;
		seg.h = t;
		seg.l = -INF;
		seg.r = INF;
		segs.push_back(seg);
	}
	{
		Segment seg;
		seg.h = -t;
		seg.l = -INF;
		seg.r = INF;
		segs.push_back(seg);
	}
	std::sort(segs.begin(), segs.end());
	ColorUpdate<int> all;
	all.upd(-INF, INF, 0);
	n += 2;
	dp[0] = 2 * INF;
	for(int i = 1; i < n; i++) {
		auto ranges = all.upd(segs[i].l, segs[i].r, i);
		std::vector<int> vals;
		for(auto info : ranges) {
			vals.push_back(info.v);
		}
		std::sort(vals.rbegin(), vals.rend());
		vals.resize(std::unique(vals.begin(), vals.end()) - vals.begin());
		ColorUpdate<int> now;
		dp[i] = 0;
		for(auto v : vals) {
			int l = std::max(segs[v].l, segs[i].l);
			int r = std::min(segs[v].r, segs[i].r);
			if(now.upd(l, r, -1).empty()) {
				dp[i] = std::max(dp[i], std::min(r - l, dp[v]));
			}
		}
	}
	std::cout << dp.back() << '\n';
}