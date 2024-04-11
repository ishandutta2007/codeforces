#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int par[2002000], size[2002000];
int getPar(int x) { return x == par[x] ? x : par[x] = getPar(par[x]); }
bool makeUnion(int a, int b) {
	a = getPar(a);
	b = getPar(b);
	if(a == b) {
		if(size[a] == 0) {
			size[a] = 1;
			return true;
		}
	} else {
		if(size[a] + size[b] <= 1) {
			size[a] += size[b];
			par[b] = a;
			return true;
		}
	}
	return false;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> u;
	std::vector<std::pair<int, int>> edges(n);
	for(int i = 0; i < n; i++) {
		std::cin >> edges[i].first >> edges[i].second;
		u.push_back(edges[i].first), u.push_back(edges[i].second);
	}
	std::sort(u.begin(), u.end());
	u.resize(std::unique(u.begin(), u.end()) - u.begin());
	for(auto &edge : edges) {
		edge.first = std::lower_bound(u.begin(), u.end(), edge.first) - u.begin();
		edge.second = std::lower_bound(u.begin(), u.end(), edge.second) - u.begin();
	}
	auto check = [&](int x) {
		for(int i = 0; i < (int) u.size(); i++) {
			par[i] = i;
			size[i] = 0;
		}
		for(auto edge : edges) {
			if(edge.second <= x) {
				if(!makeUnion(edge.first, edge.second)) {
					return false;
				}
			} else if(edge.first <= x) {
				if(!makeUnion(edge.first, edge.first)) {
					return false;
				}
			} else {
				return false;
			}
		}
		return true;
	};
	int l = 0, r = (int) u.size();
	while(l != r) {
		int mid = (l + r) / 2;
		if(check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	if(l == (int) u.size()) {
		l = -1;
	} else {
		l = u[l];
	}
	std::cout << l << '\n';
}