#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 101;

int par[ms];
int getPar(int x) { return par[x] == x ? x : par[x] = getPar(par[x]); }

void makeUnion(int a, int b) {
	a = getPar(a), b = getPar(b);
	par[b] = a;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i].first >> a[i].second;
		par[i] = i;
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(a[i].first == a[j].first || a[i].second == a[j].second) {
				makeUnion(i, j);
			}
		}
	}
	int ans = -1;
	for(int i = 0; i < n; i++) {
		if(par[i] == i) ans++;
	}
	std::cout << ans << '\n';
}