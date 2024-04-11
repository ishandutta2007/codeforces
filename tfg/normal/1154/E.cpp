#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::vector<int> p(n), inv(n);
	std::set<int> s;
	for(int i = 0; i < n; i++) {
		std::cin >> p[i];
		p[i]--;
		inv[p[i]] = i;
		s.insert(i);
	}
	std::vector<int> ans(n, -1);
	for(int pt = n-1, t = 0; pt != -1; t ^= 1) {
		//std::cout << "pt is " << pt << '\n';
		int pos = inv[pt];
		//std::cout << "pos is " << pos << '\n';
		std::vector<int> got(1, pos);
		{
			// getting after
			auto it = s.lower_bound(pos);
			it++;
			for(int i = 0; it != s.end() && i < k; i++) {
				got.push_back(*it);
				it++;
			}
		}
		{
			// getting before
			auto it = s.lower_bound(pos);
			for(int i = 0; it != s.begin() && i < k; i++) {
				it--;
				got.push_back(*it);
			}
		}
		for(auto v : got) {
			ans[v] = t + 1;
			s.erase(v);
		}
		while(pt >= 0 && ans[inv[pt]] != -1) pt--;
	}
	for(auto v : ans) std::cout << v;
	std::cout << '\n';
}