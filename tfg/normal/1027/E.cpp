#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template <int mod = 998244353>
struct modBase {
	modBase(int v = 0) : val(v < 0 ? v + mod : v) {}
	int val;
 
	void operator += (modBase<mod> o) { *this = *this + o; }
	void operator -= (modBase<mod> o) { *this = *this - o; }
	void operator *= (modBase<mod> o) { *this = *this * o; }
	//void operator /= (modBase<mod> o) { *this = *this / o; }
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

modBase<> dp[2][505][505];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	dp[0][1][1] = 1;
	for(int i = 1; i < n; i++) {
		for(int j = 1; j <= i; j++) {
			for(int jj = 1; jj <= j; jj++) {
				dp[i&1][j][jj] = 0;
			}
		}
		for(int j = 1; j <= i; j++) {
			for(int jj = 1; jj <= j; jj++) {
				dp[i&1][std::max(j, jj+1)][jj+1] += dp[(i+1)&1][j][jj];
				dp[i&1][j][1] += dp[(i+1)&1][j][jj];
			}
		}
	}
	std::vector<modBase<>> vals(n+1);
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= n; j++) {
			vals[i] += dp[(n+1)&1][i][j];
		}
		//std::cout << vals[i] << (i == n ? '\n' : ' ');
	}
	modBase<> ans(0);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; i * j < k && j <= n; j++) {
			ans += vals[i] * vals[j];
		}
	}
	std::cout << ans * 2 << '\n';
}