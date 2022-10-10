#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;

template <int mod = MOD>
struct modBase {
	modBase(int v = 0) : val(v % MOD) {}
	int val;

	modBase<mod> operator * (modBase<mod> o) { return (long long) val * o.val % mod; }
	modBase<mod> operator + (modBase<mod> o) { return val + o.val > mod ? val + o.val - mod : val + o.val; }
	modBase<mod> operator - (modBase<mod> o) { return val - o.val < 0 ? val - o.val + mod : val - o.val; }
};

template <class T>
T fexp(T x, long long e) {
	T ans(1);
	for(; e > 0; e /= 2) {
		if(e & 1) ans = ans * x;
		x = x * x;
	}
	return ans;
}

const int ms = 1001000;

modBase<> fat[ms], ifat[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	fat[0] = 1;
	for(int i = 1; i < ms; i++) {
		fat[i] = fat[i-1] * i;
	}
	ifat[ms-1] = fexp(fat[ms-1], MOD-2);
	for(int i = ms-1; i > 0; i--) {
		ifat[i-1] = ifat[i] * i;
	}
	int n, k;
	std::cin >> n >> k;
	std::vector<modBase<>> wtf(n+1, 0);
	for(int i = 1; i <= n; i++) {
		wtf[i] = fat[std::max(i-2, 0)] * fat[n] * ifat[i];
		//std::cout << i << ": " << wtf[i].val << '\n';
		wtf[i] = wtf[i-1] + wtf[i];
	}
	std::vector<modBase<>> dp(n+1, 0);
	dp[1] = 1;
	modBase<> acum = 0;
	modBase<> ans = 0;
	for(int i = 1; i <= n; i++) {
		// get dp
		if(i != 1) dp[i] = acum * fat[i-2];
		//std::cout << "at position " << i << " got " << dp[i].val << '\n';
		if(i + k < n) {
			//std::cout << "adding (" << dp[i].val << " * " << (fat[i+k-1] * ifat[i-1]).val << " * " << ((wtf[n] - wtf[i+k]) * ifat[i+k-1]).val << ")\n";
			ans = ans + (dp[i] * fat[i+k-1] * ifat[i-1] * (wtf[n] - wtf[i+k]) * ifat[i+k-1]);
		}
		// remove element
		if(i > k) {
			acum = acum - (dp[i-k] * ifat[i-k-1]);
		}
		acum = acum + (dp[i] * ifat[i-1]);
	}
	std::cout << ans.val << '\n';
}