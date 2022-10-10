#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 998244353;
const int me = 19;
const int ms = 1 << me;

typedef long long ll;
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

#define add(x, y) x+y>=MOD?x+y-MOD:x+y

const int gen = 3;
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

std::vector<int> fft(std::vector<int> a, int mod, bool inv = false) {
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

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	initFFT();
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(ms, 0);
	a[0] = k-2;
	a[1] = a[ms-1] = 1;
	long long b = 1;
	std::vector<int> vals(n);
	int f[2] = {0, 0};
	for(int i = 0; i < n; i++) {
		std::cin >> vals[i];
	}
	for(int i = 0; i < n; i++) {
		if(vals[i] != vals[(i+1)%n]) {
			f[1]++;
		} else {
			f[0]++;
		}
	}
	b = fexp(k, f[0]);
	a = fft(a, MOD);
	for(auto &i : a) {
		i = fexp(i, f[1]);
	}
	a = fft(a, MOD, true);
	long long ans = 0;
	for(int i = 1; i <= n; i++) {
		ans = (ans + a[i] * b) % MOD;
	}
	std::cout << ans << '\n';
}