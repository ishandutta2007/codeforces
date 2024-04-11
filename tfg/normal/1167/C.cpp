#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 500500;

int par[ms], size[ms];
int getPar(int x) { return x == par[x] ? x : par[x] = getPar(par[x]); }

void makeUnion(int a, int b) {
	a = getPar(a);
	b = getPar(b);
	if(a == b) return;
	if(size[a] > size[b]) std::swap(a, b);
	size[b] += size[a];
	par[a] = b;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		par[i] = i;
		size[i] = 1;
	}
	while(m--) {
		int k;
		std::cin >> k;
		if(k > 0) {
			k--;
			int i;
			std::cin >> i;
			while(k--) {
				int j;
				std::cin >> j;
				makeUnion(i, j);
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		std::cout << size[getPar(i)] << (i == n ? '\n' : ' ');
	}
}