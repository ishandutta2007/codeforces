#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

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
	void operator /= (modBase<mod> o) { *this = *this / o; }
	modBase<mod> operator * (modBase<mod> o) { return (int)((long long) val * o.val % mod); }
	modBase<mod> operator / (modBase<mod> o) { return *this * fexp(o, mod - 2); }
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
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> a(m, std::vector<int>(n));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			std::cin >> a[j][i];
		}
	}
	modBase<> fat(1);
	for(int i = 1; i <= n; i++) {
		fat *= i;
	}
	modBase<> ans(0);
	for(int i = 0; i < m; i++) {
		std::vector<int> sum(n+2, 0);
		for(int j = 0; j < n; j++) {
			// 1 can't be chosen at all
			// 2 can be chosen at time N
			// 3 can be chosen at time >= N-1
			// x can be chosen at time >= N - x + 2
			//std::cout << n - a[i][j] + 2 << (j+1 == n ? '\n' : ' ');
			sum[n - a[i][j] + 2]++;
		}
		int got = 0;
		modBase<> cur(1);
		for(int j = 1; j <= n; j++) {
			got += sum[j] - 1;
			//std::cout << got << (j == n ? '\n' : ' ');
			cur *= got + 1;
		}
		ans += modBase<>(1) - cur / fat;
	}
	std::cout << ans << '\n';
}