#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Group {
	int l, r, f;
	bool operator < (Group o) const { return l < o.l; }
};

std::vector<Group> solve(std::vector<Group> a) {
	std::sort(a.begin(), a.end());
	std::vector<Group> ans;
	for(int l = 0, r = 0; l < (int) a.size(); l = r) {
		Group cur = a[r++];
		while(r < (int) a.size() && cur.r >= a[r].l) {
			cur.r = std::max(cur.r, a[r].r);
			cur.f = std::max(cur.f, a[r].f);
			r++;
		}
		ans.push_back(cur);
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, q;
	std::cin >> n >> q;
	const int ms = 200200;
	std::vector<int> l, r;
	std::vector<int> a(n);
	std::vector<int> freq;
	auto pre = [&]() {
		l.assign(ms, n + 1);
		r.assign(ms, -1);
		freq.assign(ms, 0);
		for(int i = 0; i < n; i++) {
			l[a[i]] = std::min(l[a[i]], i);
			r[a[i]] = std::max(r[a[i]], i);
			freq[a[i]]++;
		}
	};
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	pre();
	std::vector<Group> b;
	for(int i = 0; i < ms; i++) {
		if(l[i] <= r[i]) {
			Group cur;
			cur.l = l[i];
			cur.r = r[i];
			cur.f = freq[i];
			//std::cout << "creating group (" << cur.l << ", " << cur.r << ", " << cur.f << ")\n";
			b.push_back(cur);
		}
	}
	b = solve(b);
	int ans = n;
	for(auto g : b) {
		ans -= g.f;
	}
	std::cout << ans << '\n';
}