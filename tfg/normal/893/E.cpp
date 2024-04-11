#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;

const int ms = 1002000;
const int me = 21;

int comb[ms][me];

std::vector<int> fact[ms];
int pot[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	for(int i = 0; i < ms; i++) {
		comb[i][0] = 1;
		for(int j = 1; j <= i && j < me; j++) {
			comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
		}
	}
	pot[0] = 1;
	for(int i = 1; i < ms; i++) {
		pot[i] = (pot[i-1] + pot[i-1]) % MOD;
	}
	for(int i = 2; i < ms; i++) {
		if(!fact[i].empty()) continue;
		for(int j = i; j < ms; j += i) {
			int e = 0;
			int x = j;
			while(x % i == 0) {
				x /= i;
				e++;
			}
			fact[j].push_back(e);
		}
	}
	int q;
	std::cin >> q;
	while(q--) {
		int x, y;
		std::cin >> x >> y;
		int ans = pot[y-1];
		for(auto f : fact[x]) {
			ans = (int) ((long long) ans * comb[y+f-1][f] % MOD);
		}
		std::cout << ans << '\n';
	}
}