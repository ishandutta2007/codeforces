#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <complex>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 490019;
const int ms = 1 << 20;

typedef long double ld;

const ld PI = acosl(-1.0);

struct Complex {
	ld real, imag;

	Complex(ld a = 0, ld b = 0) : real(a), imag(b) {}
	Complex operator + (const Complex &o) const { return Complex(real + o.real, imag + o.imag); }
	Complex operator - (const Complex &o) const { return Complex(real - o.real, imag - o.imag); }
	Complex operator * (const Complex &o) const { return Complex(real * o.real - imag * o.imag, real * o.imag + imag * o.real); }
	Complex operator / (ld o) const { return Complex(real / o, imag / o); }
	void operator *= (Complex o) { *this = *this * o; }
	void operator /= (ld o) { real /= o, imag /= o; }
};
//typedef std::complex<ld> Complex;
typedef std::vector<Complex> CVector;

int bits[ms * 4];

void pre(int n) {
	int LOG = 0;
	while(1 << (LOG + 1) < n) {
		LOG++;
	}
	for(int i = 1; i < n; i++) {
		bits[i] = (bits[i >> 1] >> 1) | ((i & 1) << LOG);
	}
}

void fft(CVector &a, bool inv = false) {
	int n = a.size();
	for(int i = 0; i < n; i++) {
		int to = bits[i];
		if(to > i) {
			std::swap(a[to], a[i]);
		}
	}
	
	ld angle = inv ? -PI : PI;
	for(int len = 1; len < n; len *= 2) {
		Complex delta(cosl(angle / len), sinl(angle / len));
		for(int i = 0; i < n; i += 2 * len) {
			Complex cur_root = 1;
			for(int j = 0; j < len; j++) {
				Complex u = a[i + j], v = a[i + j + len] * cur_root;
				a[i + j] = u + v;
				a[i + j + len] = u - v;
				cur_root *= delta;
			}
		}
	}
	if(inv) {
		for(int i = 0; i < n; i++)
			a[i] /= n;
	}
}

int fexp(long long x, long long e, long long mod) {
	long long ans = 1;
	for(; e > 0; e /= 2) {
		if(e & 1) ans = ans * x % mod;
		x = x * x % mod;
	}
	return (int) ans;
}

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
int g[ms], inv[ms];
int rs[ms], val[ms], p[3][ms];
int table[2][491][499];
int curt[3];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int root = 7;
	int n, m, c;
	std::cin >> n >> m >> c;
	for(int i = 0; i < MOD - 1; i++) {
		g[i] = gcd(i, MOD - 1);
	}
	for(int i = 0; i < MOD - 1; i++) {
		rs[i] = fexp(root, i, MOD - 1);
	}
	std::vector<int> A(MOD - 1, 0);
	std::vector<int> B(MOD - 1, 0);
	for(int i = 0; i < n; i++) {
		int v;
		std::cin >> v;
		int pos = fexp(i, 2, MOD - 1);
		A[pos] += v;
		A[pos] %= MOD;
	}
	for(int i = 0; i < m; i++) {
		int v;
		std::cin >> v;
		int pos = fexp(i, 3, MOD - 1);
		B[pos] += v;
		B[pos] %= MOD;
	}
	std::vector<int> dvs;
	for(int i = 1; i <= MOD - 1; i++) {
		if((MOD - 1) % i == 0) {
			dvs.push_back(i);
		}
	}
	int primes[] = {2, 491, 499};
	for(int i = 1; i < MOD - 1; i++) {
		table[i%2][i%491][i%499] = i;
	}
	assert(2 * 491 * 499 == MOD - 1);
	for(int k = 0; k < 3; k++) {
		int pr = primes[k];
		for(int j = 1; rs[j] % pr != 1; j++) {
			p[k][rs[j] % pr] = j;
		}
		for(int j = 2; j < pr; j++) {
			assert(p[k][j] < MOD - 1 && p[k][j] != 0);
		}
	}
	long long ans = 0;
	CVector poly;
	for(auto f : dvs) {
		for(auto s : dvs) {
			int curG = lcm(f, s);
			if(curG == MOD - 1) {
				long long vals[2] = {0, 0};
				for(int i = 0; i < MOD - 1; i++) {
					if(g[i] == f && A[i]) {
						vals[0] += A[i];
					}
					if(g[i] == s && B[i]) {
						vals[1] += B[i];
					}
				}
				if(vals[0] && vals[1]) {
					ans = (ans + vals[0] * vals[1]) % MOD;
				}
				continue;
			}
			int tot = (MOD - 1) / curG;
			int size = 1;
			int valid = 0;
			for(int i = 0; i < MOD - 1; i++) {
				if(g[i] == f && A[i]) valid |= 1;
				if(g[i] == s && B[i]) valid |= 2;
			}
			if(valid != 3) continue;
			while(size < tot + tot + tot) size += size;
			size = std::min(size, ms);
			poly.assign(size, 0);
			//std::cout << "trying to solve " << tot << " with " << size << std::endl;
			for(int i = 0; i < MOD - 1; i++) {
				int pos = 0;
				for(int j = 1; j < 3; j++) {
					if(tot % primes[j] != 0) continue;
					pos = pos * (2 * primes[j] - 1) + p[j][i % primes[j]];
				}
				if(g[i] == f && A[i]) {
					assert(pos + pos < size);
					int nxt = int(poly[pos].real + 0.5);
					nxt = (nxt + A[i] + MOD) % MOD;
					poly[pos].real = nxt;
				}
				if(g[i] == s && B[i]) {
					assert(pos + pos < size);
					int nxt = int(poly[pos].imag + 0.5);
					nxt = (nxt + B[i] + MOD) % MOD;
					poly[pos].imag = nxt;
				}
			}
			pre(size);
			fft(poly);
			for(int i = 0; i < size; i++) {
				poly[i] *= poly[i];
			}
			fft(poly, true);
			long long wtf = 0;
			for(int i = 0; i < size; i++) {
				int cur = (int) ((long long)(poly[i].imag + 0.5) / 2 % MOD);
				if(cur == 0) continue;
				//std::cout << "got " << cur << "on " << i << std::endl;
				//std::cout << "ori was " << poly[i].imag() / 2 << std::endl;
				int v = i;
				for(int j = 2; j >= 0; j--) {
					if(tot % primes[j] == 0) {
						curt[j] = v % (2 * primes[j] - 1) % (primes[j] - 1);
						v /= 2 * primes[j] - 1;
						curt[j] = rs[curt[j]] % primes[j];
					} else {
						curt[j] = 0;
					}
				}
				v = table[curt[0]][curt[1]][curt[2]];
				v = fexp(c, v, MOD);
				//std::cout << "end value is " << v << std::endl;
				wtf = (wtf + (long long) v * cur) % MOD;
			}
			//std::cout << "got " << wtf << std::endl;
			ans = (ans + wtf) % MOD;
			
		}
	}
	ans = (ans % MOD + MOD) % MOD;//
	std::cout << ans << std::endl;
}