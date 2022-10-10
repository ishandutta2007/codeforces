#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template<const int T>
std::vector<int> dumb(int n, const std::vector<std::vector<int>> &out, const std::vector<std::vector<int>> &in) {
	std::vector<int> p(n);
	for(int i = 0; i < n; i++) {
		p[i] = i;
	}
	if(T == 0) std::shuffle(p.begin(), p.end(), rng);
	else if(T == 1) std::sort(p.begin(), p.end(), [&](int v1, int v2) { return in[v1].size() + out[v1].size() > in[v2].size() + out[v2].size(); });
	else if(T == 2) std::sort(p.begin(), p.end(), [&](int v1, int v2) { return in[v1].size() + out[v1].size() < in[v2].size() + out[v2].size(); });
	std::vector<bool> present(n, false);
	std::vector<int> wtf(n, 0);
	std::vector<int> ans;
	for(auto i : p) {
		int mask = 0;
		for(auto j : in[i]) {
			if(present[j] && (wtf[j] & 1)) {
				mask = 3;
				break;
			}
			if(present[j]) {
				mask |= 1;
			}
		}
		for(auto j : out[i]) {
			if(present[j] && (wtf[j] & 2)) {
				mask = 3;
				break;
			}
			if(present[j]) {
				mask |= 2;
			}
		}
		if(mask == 3) {
			ans.push_back(i);
		} else {
			present[i] = true;
			wtf[i] = mask;
			for(auto j : in[i]) {
				if(present[j]) {
					wtf[j] |= 2;
					assert(wtf[j] != 3);
				}
			}
			for(auto j : out[i]) {
				if(present[j]) {
					wtf[j] |= 1;
					assert(wtf[j] != 3);
				}
			}
		}
	}
	return ans;
}

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> out(n), in(n);
	while(m--) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		out[u].push_back(v);
		in[v].push_back(u);
	}
	std::vector<int> ans(n);
	for(int rep = 0; (int) ans.size() * 7 > 4 * n; rep++) {
		if(rep == 0) ans = dumb<1>(n, out, in);
		else if(rep == 1) ans = dumb<2>(n, out, in);
		else ans = dumb<0>(n, out, in);
	}
	std::cout << ans.size() << '\n';
	for(int i = 0; i < (int) ans.size(); i++) {
		std::cout << ans[i]+1 << (i + 1 == (int) ans.size() ? '\n' : ' ');
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}