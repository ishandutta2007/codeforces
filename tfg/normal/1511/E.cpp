#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 300300;
const int MOD = 998244353;

template <class T>
T fexp(T x, long long e) {
	T ans(1);
	for(; e > 0; e /= 2) {
		if(e & 1) ans = ans * x;
		x = x * x;
	}
	return ans;
}

template <int mod = MOD>
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

std::string mat[ms];

modBase<> solve(const std::string &str) {
	modBase<> dp[2] = {1, 0};
	modBase<> ans(0);
	for(auto ch : str) {
		if(ch == 'o') {
			modBase<> other[2] = {dp[0] + dp[1] * 2, dp[0]};
			ans = ans * 2 + dp[1];
			dp[0] = other[0], dp[1] = other[1];
		} else {
			dp[0] = dp[1] + dp[0];
			dp[1] = 0;
		}
		//std::cout << dp[0] << ' ' << dp[1] << '\n';
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < n; i++) {
		std::cin >> mat[i];
	}
	modBase<> ans(0);
	int choices = 0;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(mat[i][j] == 'o') choices++;
	for(int i = 0; i < n; i++) {
		std::string now;
		int tot = 0;
		for(int j = 0; j < m; j++) {
			now += mat[i][j];
			if(mat[i][j] == 'o') tot++;
		}
		ans += fexp(modBase<>(2), choices - tot) * solve(now);
	}
	for(int j = 0; j < m; j++) {
		std::string now;
		int tot = 0;
		for(int i = 0; i < n; i++) {
			now += mat[i][j];
			if(mat[i][j] == 'o') tot++;
		}
		ans += fexp(modBase<>(2), choices - tot) * solve(now);
	}
	std::cout << ans << '\n';
}