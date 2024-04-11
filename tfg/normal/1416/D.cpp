#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;

int p[ms], inv[ms];
int par[ms], t[ms];
int pt[ms];
std::vector<int> wtf[ms];

int up(int x, int tm) {
	while(x >= 0 && t[x] > tm) x = par[x];
	assert(x >= 0);
	return x;
}
int getPar(int x) { return par[x] < 0 ? x : getPar(par[x]); }
void makeUnion(int a, int b, int tm) {
	a = getPar(a), b = getPar(b);
	if(a == b) return;
	if(par[a] > par[b]) std::swap(a, b);
	// a has biggest size
	par[a] += par[b];
	par[b] = a;
	t[b] = tm;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, q;
	std::cin >> n >> m >> q;
	for(int i = 0; i < n; i++) {
		par[i] = -1;
		int x;
		std::cin >> x;
		x--;
		p[i] = x;
		inv[x] = i;
	}
	std::vector<std::pair<int, int>> edges(m), others;
	std::vector<int> timing;
	for(int i = 0; i < m; i++) {
		std::cin >> edges[i].first >> edges[i].second;
		edges[i].first--;
		edges[i].second--;
	}
	std::vector<std::pair<int, int>> qries(q);
	for(int i = 0; i < q; i++) {
		std::cin >> qries[i].first >> qries[i].second;
		qries[i].second--;
		if(qries[i].first == 2) {
			others.push_back(edges[qries[i].second]);
			timing.push_back(i);
			edges[qries[i].second].first = -1;
		}
	}
	for(auto e : edges) {
		if(e.first != -1) {
			makeUnion(e.first, e.second, q);
		}
	}
	for(int i = (int) others.size() - 1; i >= 0; i--) {
		makeUnion(others[i].first, others[i].second, timing[i]);
	}
	for(int i = n-1; i >= 0; i--) {
		int id = inv[i];
		for(int on = id; on >= 0; on = par[on]) {
			//std::cout << "pushing " << id << " to " << on << std::endl;
			wtf[on].push_back(id);
		}
	}
	for(int i = 0; i < n; i++) {
		//std::cout << "parent of " << i << " is " << par[i] << " with timing " << t[i] << '\n';
		//for(auto v : wtf[i]) std::cout << v << ' ';
		//std::cout << '\n';
	}
	for(int i = 0; i < q; i++) {
		//std::cout << i << ": (" << qries[i].first << ", " << qries[i].second << ")\n";
		if(qries[i].first == 1) {
			int u = up(qries[i].second, i);
			//std::cout << "u is " << u << std::endl;
			while(pt[u] < (int) wtf[u].size() && (p[wtf[u][pt[u]]] == -1 || up(wtf[u][pt[u]], i) != u)) {
				//std::cout << "tested " << wtf[u][pt[u]] << " but failed with (" << p[wtf[u][pt[u]]] << ", " << up(wtf[u][pt[u]], i) << ")\n";
				pt[u]++;
			}
			if(pt[u] < (int) wtf[u].size()) {
				//std::cout << "got " << wtf[u][pt[u]] << " from position " << pt[u] << std::endl;
				int got = wtf[u][pt[u]++];
				std::cout << p[got] + 1 << '\n';
				p[got] = -1;
			} else {
				std::cout << "0\n";
			}
		}
	}
}