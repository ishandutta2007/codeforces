#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Info {
	int val, l, r;
	std::pair<int, int> mx;
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<Info> st;
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		Info cur;
		cur.l = i;
		cur.r = i+1;
		cur.val = x;
		cur.mx = std::pair<int, int>(x, i+1);
		for(auto &info : st) {
			info.val |= x;
			info.mx = std::max(info.mx, cur.mx);
		}
		st.push_back(cur);
		for(int l = 0, r = 0, j = 0; l < (int) st.size(); l = r) {
			cur = st[r++];
			while(r < (int) st.size() && st[l].val == st[r].val) {
				cur.r = st[r].r;
				cur.mx = std::max(cur.mx, st[r].mx);
				r++;
			}
			st[j++] = cur;
			if(r == (int) st.size()) {
				st.resize(j);
			}
		}
		for(auto info : st) {
			if(info.val > info.mx.first) {
				ans += info.r - info.l;
			} else {
				ans += std::max(0, info.r - info.mx.second);
			}
		}
	}
	std::cout << ans << '\n';
}