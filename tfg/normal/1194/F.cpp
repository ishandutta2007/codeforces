#include <iostream>
#include <vector>
#include <chrono>
#include <random>

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
	modBase(int v = 0) : val(v) {}
	int val;
 
	void operator += (modBase<mod> o) { *this = *this + o; }
	void operator -= (modBase<mod> o) { *this = *this - o; }
	void operator *= (modBase<mod> o) { *this = *this * o; }
	modBase<mod> operator * (modBase<mod> o) { return (long long) val * o.val % mod; }
	modBase<mod> operator / (modBase<mod> o) { return *this * fexp(o, mod - 2); }
	modBase<mod> operator + (modBase<mod> o) { return val + o.val >= mod ? val + o.val - mod : val + o.val; }
	modBase<mod> operator - (modBase<mod> o) { return val - o.val < 0 ? val - o.val + mod : val - o.val; }
};

const int ms = 200200;
modBase<MOD> fat[ms], ifat[ms];

modBase<> comb(int n, int a) {
	if(a > n || a < 0) return modBase<>(0);
	else return fat[n] * ifat[a] * ifat[n-a];
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	fat[0] = ifat[0] = 1;
	for(int i = 1; i < ms; i++) {
		fat[i] = fat[i-1] * i;
		ifat[i] = ifat[i-1] / i;
	}
	int n;
	long long rest;
	std::cin >> n >> rest;
	int pt = 0;
	modBase<> ways = 1;
	modBase<> ans = 0;
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		rest -= x;
		if(rest > i) {
			ways = ways + ways;
			pt = i + 1;
			ans = ans + 1;
			//std::cout << "at " << i << " got first\n";
		} else if(rest >= 0) {
			//std::cout << "at " << i << " got rest " << rest << '\n';
			while(pt > rest) {
				ways = ways - comb(i, pt--);
			}
			while(pt < rest) {
				ways = ways + comb(i, ++pt);
			}
			// getting 0
			//std::cout << "for 0 got " << ways.val << " ways\n";
			ans = ans + ways * fexp(modBase<>((MOD + 1) / 2), i+1);
			while(pt > rest - 1) {
				ways = ways - comb(i, pt--);
			}
			// getting 1
			//std::cout << "for 1 got " << ways.val << " ways\n";
			ans = ans + ways * fexp(modBase<>((MOD + 1) / 2), i+1);
			ways = ways + ways - comb(i, pt);
		}
	}
	std::cout << ans.val << '\n';
}