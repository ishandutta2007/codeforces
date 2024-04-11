#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::vector<int> solve(const std::vector<int> &a, int x) {
	std::vector<int> ans;
	std::vector<int> lis;
	std::vector<int> where;
	std::vector<int> to;
	for(int i = 0; i < (int) a.size(); i++) {
		int v = x * a[i];
		int id = std::lower_bound(lis.begin(), lis.end(), v) - lis.begin();
		if(id == (int) lis.size()) {
			lis.push_back(v);
			where.push_back(i);
		}
		to.push_back(-1);
		if(id > 0) {
			to.back() = where[id-1];
		}
		lis[id] = v;
		where[id] = i;
	}
	for(int i = where.back(); i >= 0; i = to[i]) {
		ans.push_back(i);
	}
	std::reverse(ans.begin(), ans.end());
	return ans;
}

std::vector<std::vector<int>> solve3(const std::vector<int> &a, int x) {
	std::vector<std::vector<int>> ans;
	std::vector<int> lis;
	for(auto v : a) {
		v *= x;
		int id = std::lower_bound(lis.begin(), lis.end(), v) - lis.begin();
		if(id == (int) lis.size()) {
			lis.push_back(v);
			ans.push_back(std::vector<int>(0));
		}
		ans[id].push_back(v);
		lis[id] = v;
	}
	return ans;
}

const int ms = 500500;

int worst[ms];

void solve2(std::vector<int> a) {
	std::vector<std::vector<int>> ans;
	std::vector<std::vector<int>> anss;
	while(!a.empty()) {
		auto v1 = solve(a, 1);
		std::vector<int> v2;
		//std::cout << "new answer of size " << ans.size() + v1.size() << "\n";
		if(anss.size() == 0 || ans.size() + v1.size() < anss.size()) {
			anss = solve3(a, 1);
			for(auto v : ans) {
				anss.push_back(v);
			}
		}
		ans.push_back(std::vector<int>(0));
		for(int i = 0, j = 0; i < (int) a.size(); i++) {
			if(j < (int) v1.size() && i == v1[j]) {
				ans.back().push_back(a[i]);
				j++;
			} else {
				v2.push_back(a[i]);
			}
		}
		a = v2;
		if(ans.size() >= anss.size()) break;
	}
	if(ans.size() < anss.size()) {
		anss = ans;
	}
	std::cout << (int) anss.size() << '\n';
	for(auto v : anss) {
		std::cout << v.size() << ' ';
		for(int j = 0; j < (int) v.size(); j++) {
			std::cout << std::max(v[j], -v[j]) << (j + 1 == (int) v.size() ? '\n' : ' ');
		}
	}
}

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	solve2(a);
}

int main() {
	for(int i = 1; i * i + 1 < ms; i++) {
		worst[i * i + 1] = i;
	}
	for(int i = 1; i < ms; i++) {
		worst[i] = std::max(worst[i], worst[i-1]);
	}
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	} return 0;
	int n = t;
	std::vector<int> p(n);
	for(int i = 0; i < n; i++) {
		p[i] = i + 1;
	}
	do {
		std::cout << "!!!! new array:";
		for(auto v : p) std::cout << ' ' << v;
		std::cout << '\n';
		solve2(p);
	} while(std::next_permutation(p.begin(), p.end()));
}