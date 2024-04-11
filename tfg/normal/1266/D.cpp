#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Edge {
	int u, v;
	long long c;
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<long long> bal(n, 0);
	while(m--) {
		int u, v;
		int c;
		std::cin >> u >> v >> c;
		u--;v--;
		bal[u] += c;
		bal[v] -= c;
	}
	std::vector<Edge> wtf;
	for(int i = 0, j = 0; i < n; i++) {
		while(bal[i] > 0) {
			while(bal[j] >= 0) j++;
			long long use = std::min(bal[i], -bal[j]);
			bal[i] -= use;
			bal[j] += use;
			Edge cur;
			cur.u = i + 1;
			cur.v = j + 1;
			cur.c = use;
			wtf.push_back(cur);
		}
	}
	std::cout << wtf.size() << '\n';
	for(auto e : wtf) {
		std::cout << e.u << ' ' << e.v << ' ' << e.c << '\n';
	}
}