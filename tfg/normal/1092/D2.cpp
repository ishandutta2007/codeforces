#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;

int par[ms], size[ms];
int f[2];

int getPar(int x) { return x == par[x] ? x : par[x] = getPar(par[x]); }
void makeUnion(int a, int b) {
	a = getPar(a);
	b = getPar(b);
	if(a == b) return;
	f[size[a] % 2]--;
	f[size[b] % 2]--;
	size[a] += size[b];
	f[size[a] % 2]++;
	par[b] = a;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	std::vector<int> p(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		p[i] = i;
		par[i] = -1;
	}
	std::sort(p.begin(), p.end(), [&](int v1, int v2) { return a[v1] < a[v2]; });
	for(int l = 0, r = 0; a[p[l]] < a[p[n-1]]; l = r) {
		while(a[p[l]] == a[p[r]]) {
			// add x
			int x = p[r++];
			par[x] = x;
			size[x] = 1;
			f[1]++;
			if(x && par[x-1] != -1) {
				makeUnion(x, x-1);
			}
			if(x + 1 < n && par[x+1] != -1) {
				makeUnion(x, x + 1);
			}
		}
		if(f[1]) {
			std::cout << "NO\n";
			return 0;
		}
	}
	std::cout << "YES\n";
}