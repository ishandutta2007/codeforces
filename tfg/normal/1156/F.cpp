#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cstring>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 998244353;

template <int mod = MOD>
struct modBase {
	modBase(int v = 0) : val(v) {}
	int val;

	modBase<mod> operator * (modBase<mod> o) { return (long long) val * o.val % mod; }
	modBase<mod> operator + (modBase<mod> o) { return val + o.val > mod ? val + o.val - mod : val + o.val; }
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

const int ms = 5050;

int n, a[ms];
int memo[2][ms][ms];
int nxt[ms];
modBase<> inv[ms];

modBase<> dp(int t, int i, int j) {
	if(i == n) {
		return modBase<>(0);
	}
	if(memo[t][i][j] != -1) {
		return modBase<>(memo[t][i][j]);
	}
	modBase<> ans(0);
	if(t == 0) {
		ans = dp(1, nxt[i], j + 1) * inv[n - j];
		ans = ans + inv[n - j] * modBase<>(nxt[i] - i - 1);
	} else {
		ans = dp(0, i, j) * modBase<>(nxt[i] - i) + dp(1, nxt[i], j);
	}
	memo[t][i][j] = ans.val;
	//std::cout << "answer for " << t << ", " << i << ", " << j << " is " << ans.val << '\n';
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	for(int i = 1; i < ms; i++) {
		inv[i] = fexp(modBase<>(i), MOD - 2);
	}
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a, a + n);
	nxt[n-1] = n;
	for(int i = n-2; i >= 0; i--) {
		nxt[i] = a[i] == a[i+1] ? nxt[i+1] : i + 1;
	}
	memset(memo, -1, sizeof memo);
	std::cout << (dp(1, 0, 1) * inv[n]).val << '\n';
}