#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		std::vector<std::vector<int>> edges(n);
		std::vector<int> deg(n, 0);		
		for(int i = 0; i < n; i++) {
			int size;
			std::cin >> size;
			while(size--) {
				deg[i]++;
				int j;
				std::cin >> j;
				edges[j-1].push_back(i);
			}
		}
		int ans = 0;
		std::set<int> q;
		for(int i = 0; i < n; i++) {
			if(deg[i] == 0) {
				q.insert(i);
			}
		}
		int got = 0;
		while(!q.empty()) {
			ans++;
			int i = -1;
			while(1) {
				auto it = q.lower_bound(i);
				if(it == q.end()) break;
				got++;
				i = *it;
				q.erase(it);
				for(auto to : edges[i]) {
					deg[to]--;
					if(deg[to] == 0) {
						q.insert(to);
					}
				}
			}
		}
		if(got < n) ans = -1;
		std::cout << ans << '\n';
	}
}