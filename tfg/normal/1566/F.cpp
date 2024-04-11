#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 400400;
const long long INF = 1e10;

struct Info {
	int l, r;
	bool operator < (const Info &o) const { return l < o.l; }
};

int sz;
int curStep = 0;
long long memo[ms][5];
Info inf[ms];
int step[ms][5];

long long dp(int on, int st) {
	// st == 0 is not going
	// st == 1 is going to right
	// st == 2 is going to right then back
	// st == 3 is incoming from right
	// st == 4 is coming from right then back

	// [1, 2] already has point
	// [3, 4] consumes a point
	long long &ans = memo[on][st];
	if(step[on][st] == curStep) return ans;
	step[on][st] = curStep;
	ans = INF;
	if(on == sz) {
		if(st == 0) {
			ans = 0;
		}
	} else if(inf[on].l != inf[on].r) {
		// this is range
		if(st == 1 || st == 2) {
			int C = st - 0;
			long long dist = on+1 == sz ? INF : inf[on+1].l - inf[on].l;
			ans = std::min(dp(on+1, 0), dist * C + dp(on+1, st));
		} else if(st == 3 || st == 4) {
			int C = st - 2;
			long long dist = on+1 == sz ? INF : inf[on+1].l - inf[on].l;
			ans = dist * C + dp(on+1, st);
		} else {
			Info wtf = {inf[on].r, -1};
			int id = std::lower_bound(inf, inf+sz, wtf) - inf;
			long long dist = id == sz ? INF : inf[id].l - (inf[on].r-1);
			assert(dist >= 0);
			ans = std::min(dp(id, 3) + dist, dp(id, 4) + dist * 2LL);
		}
	} else {
		// this is point
		long long dist = on+1 == sz ? INF : inf[on+1].l - inf[on].l;
		if(st == 1 || st == 2) {
			int C = st - 0;
			ans = dist * C + dp(on+1, st);
		} else if(st == 3 || st == 4) {
			int C = st - 2;
			ans = std::min(dp(on+1, 0), dist * C + dp(on+1, st));
			if(st == 4) ans = std::min(ans, dp(on+1, 1) + dist);
			else ans = std::min(ans, dp(on+1, 2) + 2LL * dist);
		} else {
			ans = std::min(dp(on+1, 1) + dist, dp(on+1, 0));
		}
	}
	//std::cout << "at (" << on << ", " << st << ") got " << ans << std::endl;
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		curStep++;
		int n, m;
		std::cin >> n >> m;
		std::vector<int> a(n);
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		std::sort(a.begin(), a.end());
		a.resize(std::unique(a.begin(), a.end()) - a.begin());
		n = (int) a.size();
		sz = 0;
		for(int i = 0; i < n; i++) {
			inf[sz++] = {a[i], a[i]};
		}
		std::vector<Info> wtf;
		while(m--) {
			int l, r;
			std::cin >> l >> r;
			auto id = std::lower_bound(a.begin(), a.end(), l) - a.begin();
			if(id == n || a[id] > r) {
				wtf.push_back({l, r+1});
			}
		}
		std::sort(wtf.begin(), wtf.end(), [](Info v1, Info v2) { return v1.r-v1.l < v2.r-v2.l; });
		std::set<Info> haha;
		for(auto [l, r] : wtf) {
			auto it = haha.lower_bound({l, r});
			if(it == haha.end() || it->r > r) {
				haha.insert({l, r});
				inf[sz++] = {l, r};
			}
		}
		std::sort(inf, inf + sz);
		std::cout << dp(0, 0) << '\n';
	}
}