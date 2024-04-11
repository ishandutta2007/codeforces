#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 300300;

std::vector<int> edges[ms];
int to[ms][20];
int size[ms];

void dfs(int on) {
	int mx = -1;
	size[on] = 1;
	for(auto tto : edges[on]) {
		dfs(tto);
		size[on] += size[tto];
		if(mx == -1 || size[tto] > size[mx]) mx = tto;
	}
	if(mx == -1) {
		to[on][0] = on;
	} else {
		to[on][0] = mx;
	}
	for(int i = 1; i < 20; i++) {
		to[on][i] = to[to[on][i-1]][i-1];
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, q;
	std::cin >> n >> q;
	for(int i = 1; i < n; i++) {
		int p;
		std::cin >> p;
		edges[p-1].push_back(i);
	}
	dfs(0);
	while(q--) {
		int x;
		std::cin >> x;
		x--;
		int target = (size[x] + 1) / 2;
		for(int i = 19; i >= 0; i--) {
			if(size[to[x][i]] >= target) {
				x = to[x][i];
			}
		}
		std::cout << x + 1 << '\n';
	}
}