#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template<class T, class F>
std::vector<T> multiplicativeFunction(int n, F f) {
	std::vector<T> ans(n+1, 1);
	std::vector<bool> isPrime(n+1, true);
	for(int i = 2; i <= n; i++) {
		if(!isPrime[i]) continue;
		for(int j = i, e = 1; 1; j *= i, e++) {
			ans[j] = f(i, e);
			if(n / i / j == 0) break;
		}
		for(int j = i+i; j <= n; j += i) {
			int x = j;
			while(x % i == 0) x /= i;
			ans[j] = ans[x] * ans[j / x];
			isPrime[j] = false;
		}
	}
	return ans;
}

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
	int k, n;
	std::cin >> k >> n;
	auto mob = multiplicativeFunction<int>(n, [](int p, int e) { return e == 0 ? 1 : (e == 1 ? -1 : 0); });
	std::vector<modBase<>> ans(n+1, 0), kek(n+1, 0);
	for(int i = 1; i <= n; i++) {
		kek[i] = fexp(modBase<>(i), k);
	}
	for(int i = 1; i <= n; i++) {
		if(mob[i] == 0) continue;
		for(int j = i; j <= n; j += i) {
			auto got = (kek[j / i] - kek[j / i - 1]) * mob[i];
			ans[j] += got;
		}
	}
	long long wtf = 0;
	for(int i = 1; i <= n; i++) {
		ans[i] += ans[i-1];
		wtf += ans[i].val ^ i;
	}
	std::cout << wtf % MOD << '\n';
}