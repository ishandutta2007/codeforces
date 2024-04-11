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

template<class T>
std::vector<T> partitionNumber(int n) {
	std::vector<T> ans(n, 0);
	ans[0] = 1;
	for(int i = 1; i < n; i++) {
		for(int j = 1; j * (3 * j + 1) / 2 <= i; j++) {
			ans[i] = ((j & 1) ? ans[i] + ans[i - j * (3 * j + 1) / 2] : ans[i] - ans[i - j * (3 * j + 1) / 2]);
		}
		for(int j = 1; j * (3 * j - 1) / 2 <= i; j++) {
			ans[i] = ((j & 1) ? ans[i] + ans[i - j * (3 * j - 1) / 2] : ans[i] - ans[i - j * (3 * j - 1) / 2]);
		}
	}
	return ans;
}

const int ms = 200200;
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
	int n, k;
	std::cin >> n >> k;
	k--;
	modBase<> sum(0);
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		sum += x;
	}
	modBase<> other(0);
	for(int i = 0; i <= k; i++) {
		modBase<> cur = (k - i) % 2 ? -1 : 1;
		cur *= comb(k, i);
		cur *= fexp(modBase<>(i + 1), n-2) * (modBase<>(i + 1) * n - modBase<>(i) * (n - 1));
		other += cur;
	}
	std::cout << sum * other * ifat[k] << '\n';
}