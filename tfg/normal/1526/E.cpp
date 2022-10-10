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
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n), inv(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		inv[a[i]] = i;
	}
	for(int i = 0; i+1 < n; i++) {
		if(a[i] == n-1 || (a[i+1] != n-1 && inv[a[i]+1] < inv[a[i+1]+1])) {
			// str[a[i]] should be <= str[a[i+1]]
		} else {
			// str[a[i]] should be < str[a[i+1]]
			//std::cout << "break in " << a[i] << ", " << a[i+1] << '\n';
			k--;
		}
	}
	if(k <= 0) {
		std::cout << "0\n";
	} else {
		modBase<> ans(1);
		// answer is n+k-1 choose n
		//std::cout << n+k-1 << " choose " << n << '\n';
		for(int i = 1; i <= n; i++) {
			ans *= modBase<>(n+k-1-i+1);
			ans /= modBase<>(i);
		}
		std::cout << ans << '\n';
	}
}