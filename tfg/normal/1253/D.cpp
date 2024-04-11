#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int par[300300];
int getPar(int x) { return x == par[x] ? x : par[x] = getPar(par[x]); }
void makeUnion(int a, int b) {
	a = getPar(a);
	b = getPar(b);
	if(a < b) std::swap(a, b);
	par[b] = a;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) {
		par[i] = i;
	}
	while(m--) {
		int u, v;
		std::cin >> u >> v;
		makeUnion(u-1, v-1);
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(getPar(i) == i) {
			ans++;
		}
	}
	for(int l = 0, r = 0; l < n; l = r) {
		ans--;
		r = getPar(l) + 1;
		while(l < r) {
			r = std::max(r, getPar(l) + 1);
			l++;
		}
	}
	std::cout << ans << '\n';
}