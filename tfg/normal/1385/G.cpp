#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		std::vector<std::vector<int>> pos(n);
		for(int i = 0; i < 2; i++) for(int j = 0; j < n; j++) {
			int x;
			std::cin >> x;
			x--;
			pos[x].push_back(j*2 + i);
		}
		bool good = true;
		for(int i = 0; i < n; i++) {
			good = good && (int) pos[i].size() == 2;
		}
		if(!good) {
			std::cout << "-1\n";
			continue;
		}
		std::vector<std::vector<std::pair<int, int>>> edges(n);
		for(int i = 0; i < n; i++) {
			int a = pos[i][0], b = pos[i][1];
			if(a / 2 == b / 2) {
				continue;
			}
			int c = (a ^ b ^ 1) & 1;
			edges[a/2].emplace_back(b/2, c);
			edges[b/2].emplace_back(a/2, c);
		}
		std::vector<int> col(n, -1);
		std::vector<int> ans;
		for(int i = 0; i < n; i++) {
			if(col[i] != -1) continue;
			col[i] = 0;
			std::vector<int> q(1, i);
			int f[2] = {0, 0};
			for(int id = 0; id < (int) q.size(); id++) {
				int on = q[id];
				f[col[on]]++;
				for(auto [to, c] : edges[on]) {
					if(col[to] != -1) {
						good = good && col[to] == (col[on] ^ c);
					} else {
						col[to] = col[on] ^ c;
						q.push_back(to);
					}
				}
			}
			int best = f[0] < f[1] ? 0 : 1;
			for(auto vert : q) if(col[vert] == best) {
				ans.push_back(vert);
			}
		}
		if(!good) {
			std::cout << "-1\n";
		} else {
			std::cout << ans.size() << '\n';
			for(auto x : ans) {
				std::cout << x+1 << ' ';
			}std::cout << '\n';
		}
	}
}