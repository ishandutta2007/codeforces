#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;
std::vector<int> edges[ms];
int curDist[ms], maxDist[ms];
int prep(int on, int par = -1, int cd = 0) {
	//std::cout << "on (" << on << ", " << par << ", " << cd << ")" << std::endl;
	curDist[on] = cd;
	maxDist[on] = std::max(maxDist[on], cd);
	int ans = on;
	for(auto to : edges[on]) {
		if(to == par) continue;
		int bst = prep(to, on, cd + 1);
		if(curDist[ans] < curDist[bst]) {
			ans = bst;
		}
	}
	return ans;
}

bool check(int on, int k, int par = -1) {
	if(k < 0) return false;
	int down = 0;
	bool ans = true;
	for(auto to : edges[on]) {
		if(to == par) continue;
		ans = ans && check(to, k - 1, on);
		down++;
	}
	if(k == 0) {
		ans = ans && down == 0;
	} else {
		ans = ans && down >= 3;
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	prep(prep(prep(0)));
	int root = 0;
	for(int i = 1; i < n; i++) {
		if(maxDist[i] < maxDist[root]) {
			root = i;
		}
	}
	//std::cout << "root is " << root + 1 << "\n";
	std::cout << (check(root, k) ? "Yes\n" : "No\n");
}