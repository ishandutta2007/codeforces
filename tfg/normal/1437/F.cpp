#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 5050;
const int MOD = 998244353;
int n, a[ms], l[ms], r[ms];
int memo[ms][ms][2];

int dp(int used, int on, int t) {
	int &ans = memo[used][on][t];
	if(ans != -1) return ans;
	ans = 0;
	if(t == 0) {
		if(on == n) {
			return ans = 0;
		} else {
			return ans = (dp(used, on, 1) + dp(used, on+1, 0)) % MOD;
		}
	} else {
		if(on == n-1 && used == n-1) {
			return ans = 1;
		}
		int choice = l[on] - used;
		if(choice > 0) {
			//std::cout << "at (" << used << ", " << on << ", " << t << ") choice is " << choice << "\n";
			ans = (int)((long long) choice * dp(used+1, on, t) % MOD);
		}
		ans = (ans + dp(used+1, r[on], 0)) % MOD;
		return ans;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a, a+n);
	for(int i = 0, j = 0, k = 0; i < n; i++) {
		while(a[j]*2 <= a[i]) j++;
		while(k < n && 2*a[i] > a[k]) k++;
		//std::cout << "[" << j << ", " << k << ")\n";
		l[i] = j, r[i] = k;
	}
	memset(memo, -1, sizeof memo);
	std::cout << dp(0, 0, 0) << '\n';
}