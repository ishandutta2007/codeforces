#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template <class T>
T fexp(T x, long long e) {
	T ans(1);
	for(; e > 0; e /= 2) {
		if(e & 1) ans = ans * x;
		x = x * x;
	}
	return ans;
}

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

const int ms = 100100;

modBase<> fat[ms], ifat[ms];
modBase<> comb(int n, int a) { return fat[n] * ifat[a] * ifat[n-a]; }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	fat[0] = 1;
	ifat[0] = 1;
	for(int i = 1; i < ms; i++) {
		fat[i] = fat[i-1] * i;
		ifat[i] = fexp(fat[i], MOD - 2);
	}
	int n, k;
	std::cin >> n >> k;
	modBase<> ans(0);
	for(int i = 1; i <= k; i++) {
		ans = ans + fat[i-1] * comb(k-1, i-1) * (i == k ? modBase<>(1) : fexp(modBase<>(k), k-i-1) * i);
	}
	std::cout << (ans * fexp(modBase<>(n-k), n-k)).val << std::endl;
}