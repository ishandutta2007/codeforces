#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1001000;
const int me = 20;

int par[ms][me];
int h[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int q;
	std::cin >> q;
	int n = 1;
	int dia[3] = {2, 1, 2};
	auto add = [&](int up) {
		par[n][0] = up;
		for(int i = 1; i < me; i++) {
			par[n][i] = par[par[n][i-1]][i-1];
		}
		h[n] = h[up] + 1;
		n++;
	};
	auto check = [&](int u, int v) {
		if(u == v) return;
		int a = u, b = v;
		int dist = 0;
		int mn = std::min(h[u], h[v]);
		for(int i = me-1; i >= 0; i--) {
			if(h[u] - (1 << i) >= mn) {
				dist += (1 << i);
				u = par[u][i];
			}
			if(h[v] - (1 << i) >= mn) {
				dist += (1 << i);
				v = par[v][i];
			}
		}
		if(u == v) {
			if(dist > dia[0]) {
				dia[0] = dist;
				dia[1] = a;
				dia[2] = b;
			}
			return;
		}
		for(int i = me-1; i >= 0; i--) {
			if(par[u][i] != par[v][i]) {
				dist += (1 << (i+1));
				u = par[u][i];
				v = par[v][i];
			}
		}
		dist += 2;
		if(dist > dia[0]) {
			dia[0] = dist;
			dia[1] = a;
			dia[2] = b;
		}
	};
	add(0);
	add(0);
	add(0);
	while(q--) {
		int v;
		std::cin >> v;
		v--;
		add(v);
		add(v);
		check(dia[1], n-1);
		check(dia[2], n-1);
		std::cout << dia[0] << '\n';
	}
}