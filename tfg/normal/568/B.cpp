#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 4040;
const int MOD = 1e9 + 7;

template <int mod = MOD>
struct modBase {
	modBase(int v = 0) : val(v) {}
	int val;
 
	void operator += (modBase<mod> o) { *this = *this + o; }
	void operator -= (modBase<mod> o) { *this = *this - o; }
	void operator *= (modBase<mod> o) { *this = *this * o; }
	modBase<mod> operator * (modBase<mod> o) { return (long long) val * o.val % mod; }
	//modBase<mod> operator / (modBase<mod> o) { return *this * fexp(o, mod - 2); }
	modBase<mod> operator + (modBase<mod> o) { return val + o.val >= mod ? val + o.val - mod : val + o.val; }
	modBase<mod> operator - (modBase<mod> o) { return val - o.val < 0 ? val - o.val + mod : val - o.val; }
};

modBase<MOD> comb[ms][ms], dp[ms][2];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	for(int i = 0; i < ms; i++) {
		comb[i][0] = 1;
		for(int j = 1; j <= i; j++) {
			comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]);
		}
	}
	int n;
	std::cin >> n;
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < i; j++) {
			// completing with 0
			dp[i][0] += dp[j][0] * comb[i-1][j];
			// completing with 0
			dp[i][1] += dp[j][1] * comb[i-1][j];
			// completing with 1
			// can do only with j + 1 == i
			if(j + 1 == i) {
				dp[i][1] += dp[j][0];
				dp[i][1] += dp[j][1];
			}
		}
		//std::cout << "(" << dp[i][0].val << ", " << dp[i][1].val << ")\n";
	}
	std::cout << dp[n][1].val << '\n';
}