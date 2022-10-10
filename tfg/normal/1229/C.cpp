#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;

std::vector<int> edges[ms];
int in[ms], out[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	long long ans = 0;
	while(m--) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		if(u > v) {
			std::swap(u, v);
		}
		// v earns more than u
		// v brags to u
		// creating edge v to u
		//std::cout << "for " << u << ", " << v << " got " << out[u] << '\n';
		ans += out[u] + in[v];
		edges[u].push_back(v);
		in[u]++;
		out[v]++;
	}
	std::cin >> m;
	std::cout << ans << '\n';
	while(m--) {
		int id;
		std::cin >> id;
		id--;
		assert(in[id] == (int) edges[id].size());
		for(auto to : edges[id]) {
			// removing this edge
			ans -= out[id] + in[to];
			//std::cout << "-= " << out[id] << '\n';
			in[id]--;
			out[to]--;
			// adding it in other direction
			ans += out[to] + in[id];
			//std::cout << "+= " << out[to] << '\n';
			in[to]++;
			out[id]++;
			edges[to].push_back(id);
		}
		edges[id].clear();
		std::cout << ans << '\n';
	}
}