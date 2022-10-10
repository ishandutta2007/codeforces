#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 998244353;
const int me = 20;
const int ms = 1 << me;

long long fexp(long long x, long long e, long long mod = MOD) {
	long long ans = 1;
	x %= mod;
	for(; e > 0; e /= 2, x = x * x % mod) {
		if(e & 1) ans = ans * x % mod;
	}
	return ans;
}

#define add(x, y) x+y>=MOD?x+y-MOD:x+y

const int gen = 3; // use search() from PrimitiveRoot.cpp if MOD isn't 998244353
int bits[ms], root[ms];

void initFFT() {
	root[1] = 1;
	for(int len = 2; len < ms; len += len) {
		int z = (int) fexp(gen, (MOD - 1) / len / 2);
		for(int i = len / 2; i < len; i++) {
			root[2 * i] = root[i];
			root[2 * i + 1] = (int)((long long) root[i] * z % MOD);
		}
	}
}

void pre(int n) {
	int LOG = 0;
	while(1 << (LOG + 1) < n) {
		LOG++;
	}
	for(int i = 1; i < n; i++) {
		bits[i] = (bits[i >> 1] >> 1) | ((i & 1) << LOG);
	}
}

std::vector<int> fft(std::vector<int> a, bool inv = false) {
	int n = (int) a.size();
	pre(n);
	if(inv) {
		std::reverse(a.begin() + 1, a.end());
	}
	for(int i = 0; i < n; i++) {
		int to = bits[i];
		if(i < to) { std::swap(a[i], a[to]); }
	}
	for(int len = 1; len < n; len *= 2) {
		for(int i = 0; i < n; i += len * 2) {
			for(int j = 0; j < len; j++) {
				int u = a[i + j], v = (int)((long long) a[i + j + len] * root[len + j] % MOD);
				a[i + j] = add(u, v);
				a[i + j + len] = add(u, MOD - v);
			}
		}
	}
	if(inv) {
		long long rev = fexp(n, MOD-2, MOD);
		for(int i = 0; i < n; i++)
			a[i] = (int)(a[i] * rev % MOD);
	}
	return a;
}

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

std::vector<int> operator *(std::vector<int> a, std::vector<int> b) {
	while(!a.empty() && a.back() == 0) a.pop_back();
	while(!b.empty() && b.back() == 0) b.pop_back();
	if(a.empty() || b.empty()) return std::vector<int>(0, 0);
	int n = 1;
	while(n-1 < (int) a.size() + (int) b.size() - 2) n += n;
	a.resize(n, 0);
	b.resize(n, 0);
	a = fft(a, false);
	b = fft(b, false);
	for(int i = 0; i < n; i++) {
		a[i] = (int) ((long long) a[i] * b[i] % MOD); 
	}
	return fft(a, true);
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	initComb();
	initFFT();
	int n;
	std::cin >> n;
	std::vector<int> poly(1, 1);
	int got = 1;
	while(n-- && !poly.empty()) {
		int a, b;
		std::cin >> a >> b;
		std::vector<int> other(2 * got + 20, 0);
		for(int i = 0; i < (int) other.size(); i++) {
			int id = i - (got + 10) + b;
			other[i] = comb(a+b, id).val;
		}
		poly = poly * other;
		std::vector<int> ans(got+a-b, 0);
		for(int i = 0; i < (int) poly.size(); i++) {
			int id = i - (got + 10);
			if(0 <= id && id < (int) ans.size()) {
				ans[id] = poly[i];
			}
		}
		got += a - b;
		poly = ans;
	}
	modBase<> ans(0);
	for(auto v : poly) {
		ans += v;
	}
	std::cout << ans << '\n';
}