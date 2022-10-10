#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1010;

int n;
int h[ms], up[ms];
std::vector<int> edges[ms];

void go(int on, int par) {
	up[on] = par;
	for(auto to : edges[on]) {
		if(to == par) continue;
		h[to] = 1 + h[on];
		go(to, on);
	}
}

void pre(int root) {
	h[root] = 0;
	go(root, root);
}

void go2(int on, int par, std::vector<int> &spec) {
	if((int) edges[on].size() == 1 && on != par) {
		spec.push_back(on);
	}
	for(auto to : edges[on]) {
		if(to == par) continue;
		go2(to, on, spec);
	}
}

std::pair<int, int> qry(std::vector<int> a) {
	assert(!a.empty());
	std::sort(a.begin(), a.end());
	std::cout << "? " << a.size();
	for(auto x : a) std::cout << ' ' << x + 1;
	std::cout << std::endl;
	std::pair<int, int> ans;
	std::cin >> ans.first >> ans.second;
	ans.first--;
	return ans;
}

void solve() {
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		edges[i].clear();
	}
	std::vector<int> deg(n, 0);
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	std::vector<int> all;
	for(int i = 0; i < n; i++) {
		if(deg[i] == 1) {
			all.push_back(i);
			deg[i] = 0;
		}
	}
	for(int i = 0; i < n; i++) {
		assert(i < (int) all.size());
		for(auto to : edges[all[i]]) {
			deg[to]--;
			if(deg[to] == 1) {
				deg[to] = 0;
				all.push_back(to);
			}
		}
	}
	auto q1 = qry(all);
	int l = 1, r = n;
	while(l != r) {
		int mid = (l + r) / 2;
		std::vector<int> cur;
		for(int i = 0; i < mid; i++) {
			cur.push_back(all[i]);
		}
		if(qry(cur).second == q1.second) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	int ans[2] = {-1, -1};
	q1.first = all[l-1];
	ans[0] = q1.first;
	pre(q1.first);
	std::vector<int> special;
	int want = q1.second;
	for(int i = 0; i < n; i++) {
		if(h[i] == want) {
			special.push_back(i);
		}
	}
	assert(!special.empty());
	auto q2 = qry(special);
	assert(q2.second == q1.second);
	ans[1] = q2.first;
	assert(ans[0] != ans[1]);
	std::cout << "! " << ans[0]+1 << " " << ans[1]+1 << std::endl;
	std::string str;
	std::cin >> str;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}