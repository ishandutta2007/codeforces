#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;
const int MOD = 1e9 + 7;

std::vector<int> edges[ms];
bool vis[ms];
bool wtf = false;

std::pair<int, int> dfs(int on) {
	std::pair<int, int> ans((int) edges[on].size(), 1);
	vis[on] = true;
	for(auto to : edges[on]) {
		if(!vis[to]) {
			auto got = dfs(to);
			ans.first += got.first;
			ans.second += got.second;
		} else if(on == to) {
			wtf = true;
		}
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	while(n--) {
		int u, v;
		std::cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	long long ans = 1;
	for(int i = 0; i < ms; i++) {
		if(!vis[i] && !edges[i].empty()) {
			wtf = false;
			auto got = dfs(i);
			//std::cout << "got (" << got.first << ", " << got.second << ")\n";
			if(got.first == got.second * 2 - 2) {
				ans = ans * got.second % MOD;
			} else if(got.first != got.second * 2) {
				ans = 0;
			} else if(!wtf) {
				ans = ans * 2 % MOD;
			}
		}
	}
	std::cout << ans << '\n';
}