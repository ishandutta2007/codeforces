#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1010;

int qry(int x, int y) {
	x++;y++;
	std::cout << "? " << x << ' ' << y << std::endl;
	std::cin >> x;
	return x-1;
}

std::vector<int> graph[ms];
std::vector<int> verts, leaf;

void build(int on, int par) {
	verts.push_back(on);
	for(auto to : graph[on]) {
		if(to != par) build(to, on);
	}
	if((int) graph[on].size() == 1) {
		leaf.push_back(on);
	}
}

bool cut(int on, int par, int want) {
	if(on == want) return true;
	for(int i = 0; i < (int) graph[on].size(); i++) {
		if(graph[on][i] == par) continue;
		if(cut(graph[on][i], on, want)) {
			std::swap(graph[on][i], graph[on].back());
			graph[on].pop_back();
			return true;
		}
	}
	return false;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int root = 0;
	build(root, root);
	while((int) verts.size() != 1) {
		int u, v;
		do {
			u = rng() % (int) leaf.size();
			v = rng() % (int) leaf.size();
		} while(u == v);
		u = leaf[u], v = leaf[v];
		root = qry(u, v);
		cut(root, root, u);
		cut(root, root, v);
		leaf.clear();
		verts.clear();
		build(root, root);
	}
	std::cout << "! " << root + 1 << std::endl;
}