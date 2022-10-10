#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;

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
	modBase(int v = 0) : val((v % MOD + MOD) % MOD) {}
	int val;
 
	void operator += (modBase<mod> o) const { *this = *this + o; }
	void operator -= (modBase<mod> o) const { *this = *this - o; }
	void operator *= (modBase<mod> o) const { *this = *this * o; }
	modBase<mod> operator * (modBase<mod> o) const { return (long long) val * o.val % mod; }
	modBase<mod> operator / (modBase<mod> o) const { return *this * fexp(o, mod - 2); }
	modBase<mod> operator + (modBase<mod> o) const { return val + o.val >= mod ? val + o.val - mod : val + o.val; }
	modBase<mod> operator - (modBase<mod> o) const { return val - o.val < 0 ? val - o.val + mod : val - o.val; }
};

std::vector<modBase<>> base;
struct Polynomial {
	Polynomial(int val) {
		coef.assign(1, val);
	}
	Polynomial(const std::vector<modBase<>> &P) {
		coef = P;
		while((int) coef.size() > 1 && coef.back().val == 0) {
			coef.pop_back();
		}
	}

	Polynomial pureMul(const Polynomial& o) const {
		std::vector<modBase<>> ans((int) coef.size() + (int) o.coef.size() - 1, 0);
		for(int i = 0; i < (int) coef.size(); i++) {
			for(int j = 0; j < (int) o.coef.size(); j++) {
				ans[i+j] = ans[i+j] + coef[i] * o.coef[j];
			}
		}
		return Polynomial(ans);
	}

	Polynomial operator * (const Polynomial &o) const {
		return pureMul(o) % base;
	}

	Polynomial operator % (const Polynomial &o) const {
		std::vector<modBase<>> rest(o.coef.size(), 0);
		for(int i = (int) coef.size() - 1; i >= 0; i--) {
			auto cur = coef[i];
			for(int j = (int) rest.size() - 1; j > 0; j--) {
				rest[j] = rest[j-1];
			}
			rest[0] = cur;
			// lambda * o.back() == rest.back()
			// lambda = rest.back() / o.back()
			auto lambda = rest.back() / o.coef.back();
			for(int j = 0; j < (int) rest.size(); j++) {
				rest[j] = rest[j] - o.coef[j] * lambda;
			}
			assert(rest.back().val == 0);
		}
		return Polynomial(rest);
	}

	std::vector<modBase<>> coef;
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int f, b;
	long long e;
	std::cin >> f >> b >> e;
	std::vector<int> A(f);
	for(int i = 0; i < f; i++) {
		std::cin >> A[i];
	}
	const int ms = 251;
	base.assign(ms, 0);
	base[ms-1] = 1;
	while(b--) {
		int x;
		std::cin >> x;
		base[ms-1-x] = base[ms-1-x] - 1;
	}
	// now solve for A
	std::vector<modBase<>> P(ms);
	for(auto n : A) {
		std::vector<modBase<>> wtf(2, 0);
		wtf[1] = 1;
		auto haha = fexp(Polynomial(wtf), n);
		for(int i = 0; i < (int) haha.coef.size(); i++) {
			P[i] = P[i] + haha.coef[i];
		}
	}
	auto poly = Polynomial(P);
	poly = fexp(poly, e);
	std::vector<modBase<>> dp(poly.coef.size(), 0);
	dp[0] = 1;
	for(int i = 1; i < (int) dp.size(); i++) {
		for(int j = 1; j <= i; j++) {
			dp[i] = dp[i] - dp[i-j] * base[ms-1-j];
		}
	}
	modBase<> ans(0);
	for(int i = 0; i < (int) dp.size(); i++) {
		ans = ans + dp[i] * poly.coef[i];
	}
	std::cout << ans.val << '\n';
}