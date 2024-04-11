#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n), b(n), p(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		p[i] = i;
	}
	std::sort(p.begin(), p.end(), [&](int v1, int v2) { return a[v1] < a[v2]; });
	for(auto &v : b) {
		std::cin >> v;
	}
	std::sort(b.begin(), b.end());
	struct Query {
		Query(int v1, int v2, int v3) {
			i = v1, j = v2, k = v3;
		}
		int i, j, k;
	};
	std::vector<Query> ans;
	for(int i = 0, j = 0; i < n && j < n;) {
		if(a[p[i]] >= b[i]) i++;
		else if(a[p[j]] <= b[j] || j <= i) j++;
		else {
			int use = std::min(b[i] - a[p[i]], a[p[j]] - b[j]);
			if(use < 0) {
				std::cout << "NO\n";
				return 0;
			}
			ans.emplace_back(p[i] + 1, p[j] + 1, use);
			a[p[i]] += use;
			a[p[j]] -= use;
		}
	}
	for(int i = 0, j = n-1; i < j;) {
		if(a[p[i]] >= b[i]) i++;
		else if(a[p[j]] <= b[j]) j--;
		else {
			int use = std::min(b[i] - a[p[i]], a[p[j]] - b[j]);
			if(use < 0) {
				std::cout << "NO\n";
				return 0;
			}
			ans.emplace_back(p[i] + 1, p[j] + 1, use);
			a[p[i]] += use;
			a[p[j]] -= use;
		}
	}
	std::sort(a.begin(), a.end());
	if(a == b) {
		std::cout << "YES\n";
		std::cout << ans.size() << '\n';
		for(auto q : ans) {
			std::cout << q.i << ' ' << q.j << ' ' << q.k << '\n';
		}
	} else {
		std::cout << "NO\n";
	}
}