#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;
const long long MOD = 1e9 + 7;

int u[ms], v[ms], c[ms];
int par[ms], size[ms];

long long fexp(long long x, long long e) {
	long long ans = 1;
	for(; e > 0; e /= 2) {
		if(e & 1) ans = ans * x % MOD;
		x = x * x % MOD;
	}
	return ans;
}

int getPar(int x) { return x == par[x] ? x : par[x] = getPar(par[x]); }
void makeUnion(int a, int b) {
	a = getPar(a);
	b = getPar(b);
	if(a == b) return;
	size[a] += size[b];
	par[b] = a;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	for(int i = 0; i < n; i++) {
		par[i] = i;
		size[i] = 1;
	}
	for(int i = 1; i < n; i++) {
		std::cin >> u[i] >> v[i] >> c[i];
		u[i]--;v[i]--;
		if(c[i] == 0) {
			makeUnion(u[i], v[i]);
		}
	}
	long long ans = fexp(n, k);
	for(int i = 0; i < n; i++) {
		if(par[i] != i) continue;
		ans = (ans - fexp(size[i], k) + MOD) % MOD;
	}
	std::cout << ans << '\n';
}