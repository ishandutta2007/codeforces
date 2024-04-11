#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;

int par[ms];
int getPar(int x) { return x == par[x] ? x : par[x] = getPar(par[x]); }
std::vector<int> v[ms];
void makeUnion(int a, int b) {
	a = getPar(a);
	b = getPar(b);
	if(a == b) return;
	if(v[a].size() < v[b].size()) std::swap(a, b);
	for(auto val : v[b]) {
		v[a].push_back(val);
	}
	v[b].clear();
	par[b] = a;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 1; i <= n; i++) {
		par[i] = i;
		v[i].push_back(i);
	}
	for(int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		makeUnion(u, v);
	}
	for(auto val : v[getPar(1)]) {
		std::cout << val << ' ';
	}
	std::cout << '\n';
}