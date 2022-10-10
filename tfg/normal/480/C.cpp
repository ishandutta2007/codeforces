#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;
template <int mod = MOD>
struct modBase {
	modBase(int v = 0) : val(v < 0 ? v + mod : v) {}
	int val;
 
	void operator += (modBase<mod> o) { *this = *this + o; }
	void operator -= (modBase<mod> o) { *this = *this - o; }
	void operator *= (modBase<mod> o) { *this = *this * o; }
	modBase<mod> operator * (modBase<mod> o) { return (int)((long long) val * o.val % mod); }
	//modBase<mod> operator / (modBase<mod> o) { return *this * fexp(o, mod - 2); }
	modBase<mod> operator + (modBase<mod> o) { return val + o.val >= mod ? val + o.val - mod : val + o.val; }
	modBase<mod> operator - (modBase<mod> o) { return val - o.val < 0 ? val - o.val + mod : val - o.val; }

	friend std::ostream& operator << (std::ostream &os, const modBase<mod> &p) {
		return os << p.val;
	}
	friend std::istream& operator >> (std::istream &is, modBase<mod> &p) {
		return is >> p.val;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, a, b, k;
	std::cin >> n >> a >> b >> k;
	a--;b--;
	std::vector<modBase<>> dp(n+1, 0);
	dp[a] = 1;
	while(k--) {
		std::vector<modBase<>> nxt(n+1, 0);
		for(int i = 0; i < n; i++) {
			int dist = abs(i - b);
			if(dist == 0) continue;
			dist--;
			int l = std::max(0, i - dist);
			int r = std::min(n, i + dist + 1);
			nxt[l] += dp[i];
			nxt[r] -= dp[i];
		}
		for(int i = 1; i <= n; i++) {
			nxt[i] += nxt[i-1];
			nxt[i-1] -= dp[i-1];
		}
		dp = nxt;
	}
	modBase<> ans(0);
	for(auto val : dp) {
		ans += val;
	}
	std::cout << ans << '\n';
}