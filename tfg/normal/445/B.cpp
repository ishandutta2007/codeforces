#include <iostream>

const int ms = 100100;

int deg[ms];
int par[ms];
int get_par(int x) {
	if(par[x] == x) {
		return x;
	} else {
		return par[x] = get_par(par[x]);
	}
}
void make_union(int a, int b) {
	a = get_par(a);
	b = get_par(b);
	par[b] = a;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) {
		par[i] = i;
	}
	for(int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		deg[u]++;
		deg[v]++;
		make_union(u, v);
	}
	long long ans = 1;
	for(int i = 0; i < n; i++) {
		if(deg[i] == 0) {
			continue;
		}
		ans *= 2;
		if(get_par(i) == i) {
			ans /= 2;
		}
	}
	std::cout << ans << '\n';
}