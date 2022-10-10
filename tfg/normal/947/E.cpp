#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <map>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;

const int MOD = 998244353;
const int me = 18;
const int ms = 1 << me;
ll fexp(ll x, ll e, ll mod = MOD) {
	ll ans = 1;
	x %= mod;
	for(; e > 0; e /= 2) {
		if(e & 1) {
			ans = ans * x % mod;
		}
		x = x * x % mod;
	}
	return ans;
}
//is n primitive root of p ?
bool test(ll x, ll p) {
	ll m = p - 1;
	for(int i = 2; i * i <= m; ++i) if(!(m % i)) {
		if(fexp(x, i, p) == 1) return false;
		if(fexp(x, m / i, p) == 1) return false;
	}
	return true;
}
//find the largest primitive root for p
int search(int p) {
	for(int i = p - 1; i >= 2; --i) if(test(i, p)) return i;
	return -1;
}
std::map<int, int> roots;
int get_root(int p) {
	if(roots[p]) {
		return roots[p];
	} else {
		roots[p]=search(p);
		return roots[p];
	}
}

#define add(x, y) x+y>=MOD?x+y-MOD:x+y

const int gen = search(MOD);
int bits[ms], root[ms];

void initFFT() {
	root[1] = 1;
	for(int len = 2; len < ms; len += len) {
		int z = fexp(gen, (MOD - 1) / len / 2);
		for(int i = len / 2; i < len; i++) {
			root[2 * i] = root[i];
			root[2 * i + 1] = (long long) root[i] * z % MOD;
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
	int mod = MOD;
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
				int u = a[i + j], v = (ll) a[i + j + len] * root[len + j] % mod;
				a[i + j] = add(u, v);
				a[i + j + len] = add(u, mod - v);
			}
		}
	}
	if(inv) {
		int rev = fexp(n, mod-2, mod);
		for(int i = 0; i < n; i++)
			a[i] = (ll) a[i] * rev % mod;
	}
	return a;
}

long long fat[ms], ifat[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	fat[0] = 1;
	for(int i = 1; i < ms; i++) {
		fat[i] = fat[i-1] * i % MOD;
	}
	ifat[ms-1] = fexp(fat[ms-1], MOD - 2, MOD);
	for(int i = ms-1; i > 0; i--) {
		ifat[i-1] = ifat[i] * i % MOD;
	}
	initFFT();
	int n;
	long long m;
	std::cin >> n >> m;
	int size = 1;
	while(size <= n+n) size += size;
	std::vector<int> a(size, 0);
	std::vector<int> b(size, 0);
	for(int i = 0; i <= n; i++) {
		std::cin >> a[i];
		a[i] = a[i] * fat[i] % MOD;
		b[i] = ifat[n-i];
	}
	{
		auto A = fft(a);
		auto B = fft(b);
		for(int i = 0; i < size; i++) {
			A[i] = (long long) A[i] * B[i] % MOD;
		}
		A = fft(A, true);
		a.assign(size, 0);
		for(int i = 0; i <= n; i++) {
			a[i] = A[n+i] * fexp(fexp(i+1, MOD - 2, MOD), m, MOD) % MOD * fexp(MOD - 1, i, MOD) % MOD;
			b[i] = ifat[n-i];
		}
	}
	{
		auto A = fft(a);
		auto B = fft(b);
		for(int i = 0; i < size; i++) {
			A[i] = (long long) A[i] * B[i] % MOD;
		}
		A = fft(A, true);
		a.assign(size, 0);
		for(int i = 0; i <= n; i++) {
			a[i] = A[n+i] * ifat[i] % MOD;
			a[i] = a[i] * fexp(MOD - 1, i, MOD) % MOD;
			std::cout << a[i] << (i == n ? '\n' : ' ');
		}
	}
}