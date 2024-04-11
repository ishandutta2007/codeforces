#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<bool> got(3 * n, false);
	std::vector<int> ind;
	for(int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		if(!got[u] && !got[v] && ind.size() < n) {
			got[u] = got[v] = true;
			ind.push_back(i + 1);
		}
	}
	if(ind.size() == n) {
		std::cout << "Matching\n";
		for(int i = 0; i < n; i++) {
			std::cout << ind[i] << (i + 1 == n ? '\n' : ' ');
		}
	} else {
		std::cout << "IndSet\n";
		std::vector<int> wtf;
		for(int i = 0; i < 3 * n; i++) {
			if(!got[i] && wtf.size() < n) {
				wtf.push_back(i + 1);
			}
		}
		for(int i = 0; i < n; i++) {
			std::cout << wtf[i] << (i + 1 == n ? '\n' : ' ');
		}
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