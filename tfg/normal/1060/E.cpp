#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;

std::vector<int> edges[ms];
int size[ms];
long long paths[ms][2], up[ms][2];

void preSize(int on = 0, int par = -1) {
	size[on] = 1;
	for(auto to : edges[on]) {
		if(to == par) {
			continue;
		}
		preSize(to, on);
		size[on] += size[to];
	}
}

void go(int on = 0, int par = -1) {
	paths[on][0] = 1;
	up[on][1] = 1;
	for(auto to : edges[on]) {
		if(to == par) {
			continue;
		}
		go(to, on);
		long long old0 = up[on][1], old1 = up[on][0];
		paths[on][0] += old1 * up[to][1] + old0 * up[to][0];
		paths[on][1] += old0 * up[to][1] + old1 * up[to][0];
		up[on][0] += up[to][1];
		up[on][1] += up[to][0];
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	long long ans = 0;
	preSize();
	for(int i = 0; i < n; i++) {
		for(auto j : edges[i]) {
			if(size[j] < size[i]) {
				ans += (long long) size[j] * (n - size[j]);
			}
		}
	}
	go();
	for(int i = 0; i < n; i++) {
		ans += paths[i][1];
	}
	std::cout << ans / 2 << std::endl;
}