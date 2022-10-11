#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 770;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int good[ms][ms];
int a[ms];
bool vis[ms][ms][2];
bool memo[ms][ms][2];

template<const int t>
bool dp(int l, int r) {
	if(l >= r) return true;
	bool &ans = memo[l][r][t];
	if(vis[l][r][t]) return ans;
	vis[l][r][t] = true;
	ans = false;
	for(int i = l; i < r && !ans; i++) {
		if(t == 0 ? good[i][r] : good[l-1][i]) {
			ans = dp<0>(l, i) && dp<1>(i+1, r);
		}
	}
	//std::cout << "at [" << l << ", " << r << "), " << t << " got " << ans << '\n';
	return ans;
}


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= n; j++) {
			good[i][j] = gcd(a[i], a[j]) != 1;
		}
	}
	std::cout << (dp<0>(0, n) ? "Yes\n" : "No\n");
}