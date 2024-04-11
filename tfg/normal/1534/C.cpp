#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1001000;
const int MOD = 1e9 + 7;

int par[ms];
int getPar(int x) { return par[x] < 0 ? x : par[x] = getPar(par[x]); }
void makeUnion(int a, int b) {
	a = getPar(a), b = getPar(b);
	if(a == b) return;
	par[a] += par[b];
	par[b] = a;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		std::vector<int> a[2];
		std::vector<int> at[2];
		a[0] = a[1] = at[0] = at[1] = std::vector<int>(n, 0);
		for(int i = 0; i < 2*n; i++) {
			par[i] = -1;
		}
		for(int rep = 0; rep < 2; rep++) {
			for(int i = 0; i < n; i++) {
				std::cin >> a[rep][i];
				a[rep][i]--;
				at[rep][a[rep][i]] = i;
			}
		}
		for(int i = 0; i < n; i++) {
			makeUnion(i, n + i);
			makeUnion(i, at[0][a[1][i]]);
		}
		for(int i = 0; i < n; i++) {
			assert(getPar(n + i) == getPar(at[1][a[0][i]]));
		}
		int ans = 1;
		for(int i = 0; i < 2*n; i++) {
			if(par[i] < -2) {
				ans = (ans + ans) % MOD;
			}
		}
		std::cout << ans << '\n';
	}
}