#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;
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

modBase<> fat[ms], ifat[ms];
void initComb() {
	fat[0] = 1;
	for(int i = 1; i < ms; i++) {
		fat[i] = fat[i-1] * i;
	}
	ifat[ms-1] = fexp(fat[ms-1], MOD - 2);
	for(int i = ms-1; i > 0; i--) {
		ifat[i-1] = ifat[i] * i;
	}
}
modBase<> comb(int n, int a) { return a < 0 || a > n ? modBase<>(0) : fat[n] * ifat[a] * ifat[n-a]; }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	initComb();
	int n, m;
	std::string str;
	std::cin >> n >> m >> str;
	int e = 0, s = 0;
	for(int i = 0; i < n; i += 2) {
		auto cur = str.substr(i, 2);
		if(cur == "??") {
			e += 2;
			s -= 1;
		} else if(cur == "wb") {
			s -= 1;
		} else if(cur == "bw") {
			s += 1;
		} else if(cur[0] != cur[1]) {
			if(cur[0] == 'w') {
				e += 1;
				s -= 1;
			} else if(cur[0] == 'b') {
				e += 1;
			} else if(cur[1] == 'w') {
				e += 1;
			} else if(cur[1] == 'b') {
				e += 1;
				s -= 1;
			} else assert(0);
		}
	}
	//std::cout << e << ", " << s << '\n';
	modBase<> ans[2] = {0, 0};
	for(int i = 0; i <= e; i++) {
		int bal = i + s;
		if(bal % 2) continue;
		//std::cout << "at (" << e << ", " << i << ") got " << comb(e, i) << " with bal " << bal << '\n';
		ans[0] += comb(e, i) * std::abs(bal) / 2;
		ans[1] += comb(e, i);
	}
	std::cout << ans[0] / ans[1] << '\n';
}