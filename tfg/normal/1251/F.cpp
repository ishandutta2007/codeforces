#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;

const int MOD = 998244353;
const int me = 20;
const int ms = 1 << me;
ll fexp(ll x, ll e) {
	ll ans = 1;
	x %= MOD;
	for(; e > 0; e /= 2) {
		if(e & 1) {
			ans = ans * x % MOD;
		}
		x = x * x % MOD;
	}
	return ans;
}

#define add(x, y) x+y>=MOD?x+y-MOD:x+y

const int gen = 3;
int bits[ms], root[ms];

void initFFT() {
	root[1] = 1;
	for(int len = 2; len < ms; len += len) {
		int z = (int) fexp(gen, (MOD - 1) / len / 2);
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
				int u = a[i + j], v = (ll) a[i + j + len] * root[len + j] % MOD;
				a[i + j] = add(u, v);
				a[i + j + len] = add(u, MOD - v);
			}
		}
	}
	if(inv) {
		int rev = (int) fexp(n, MOD-2);
		for(int i = 0; i < n; i++)
			a[i] = (ll) a[i] * rev % MOD;
	}
	return a;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	initFFT();
	int n, k;
	std::cin >> n >> k;
	std::vector<int> freq(ms, 0);
	while(n--) {
		int x;
		std::cin >> x;
		freq[x]++;
	}
	std::vector<int> first(ms, 0);
	first[0] = 1;
	first[1] = 2;
	first = fft(first);
	std::vector<int> second(ms, 0);
	second[0] = 1;
	second[1] = 2;
	second[2] = 1;
	second = fft(second);
	std::vector<int> ans(ms, 0);
	while(k--) {
		int red;
		std::cin >> red;
		auto A = first;
		auto B = second;
		int f[2] = {0, 0};
		for(int i = 0; i < red; i++) {
			if(freq[i] == 1) {
				f[0]++;
			} else if(freq[i] > 1) {
				f[1]++;
			}
		}
		for(auto &x : A) {
			x = fexp(x, f[0]);
		}
		for(auto &x : B) {
			x = fexp(x, f[1]);
		}
		for(int i = 0; i < ms; i++) {
			A[i] = (ll) A[i] * B[i] % MOD;
		}
		A = fft(A, true);
		for(int i = 0; i + red + 1 < ms; i++) {
			ans[i + red + 1] = (ans[i + red + 1] + A[i]) % MOD;
		}
	}
	int q;
	std::cin >> q;
	while(q--) {
		int x;
		std::cin >> x;
		std::cout << ans[x / 2] << '\n';
	}
}