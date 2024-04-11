#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;

int par[ms];

int getPar(int x) { return x == par[x] ? x : par[x] = getPar(par[x]); }
bool makeUnion(int a, int b) {
	a = getPar(a);
	b = getPar(b);
	if(a == b) return false;
	par[a] = b;
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, d;
	std::cin >> n >> m >> d;
	std::vector<int> fi;
	std::vector<std::pair<int, int> > edges(n);
	for(int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		if(u > v) {
			std::swap(u, v);
		}
		u--;v--;
		if(u == 0) {
			fi.push_back(v);
		} else {
			edges.emplace_back(u, v);
		}
	}
	auto count = [](std::vector<std::pair<int, int> > &ed) {
		int ans = 0;
		for(auto e : ed) {
			if(e.first == 1) {
				ans++;
			}
		}
		return ans;
	};
	auto solve = [&](int x) {
		std::vector<std::pair<int, int> > ans;
		for(int i = 0; i < n; i++) {
			par[i] = i;
		}
		for(int i = 0; i < x; i++) {
			if(makeUnion(0, fi[i])) {
				ans.emplace_back(1, fi[i] + 1);
			}
		}
		for(auto e : edges) {
			if(makeUnion(e.first, e.second)) {
				ans.emplace_back(e.first + 1, e.second + 1);
			}
		}
		for(int i = x; i < (int) fi.size(); i++) {
			if(makeUnion(0, fi[i])) {
				ans.emplace_back(1, fi[i] + 1);
			}
		}
		return ans;
	};
	int l = 0, r = (int) fi.size();
	while(l != r) {
		int mid = (l + r) / 2;
		auto a = solve(mid);
		if(count(a) < d) l = mid + 1;
		else r = mid;
	}
	auto ans = solve(l);
	if(count(ans) != d) {
		std::cout << "NO\n";
	} else {
		std::cout << "YES\n";
		for(auto e : ans) {
			std::cout << e.first << ' ' << e.second << '\n';
		}
	}
}