#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = unsigned long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

constexpr cat mod = 1000000007;
constexpr int M = 200;
int fac[M+8], inv[M+8], outi[M+8];
cat out[M+8], out_cnt[M+8];

inline void __attribute__((always_inline)) __attribute__((optimize("Ofast")))
  multiply_inner(const int * __restrict a, const int * __restrict b, cat * __restrict c) {
constexpr cat m8 = mod * mod * 8;
c[0]  += 1ULL * a[0] * b[0];
if(c[0] >= m8) c[0] -= m8;
c[1]  += 1ULL * a[0] * b[1] + 1ULL * a[1] * b[0];
if(c[1] >= m8) c[1] -= m8;
c[2]  += 1ULL * a[0] * b[2] + 1ULL * a[1] * b[1] + 1ULL * a[2] * b[0];
if(c[2] >= m8) c[2] -= m8;
c[3]  += 1ULL * a[0] * b[3] + 1ULL * a[1] * b[2] + 1ULL * a[2] * b[1] + 1ULL * a[3] * b[0];
if(c[3] >= m8) c[3] -= m8;
c[4]  += 1ULL * a[0] * b[4] + 1ULL * a[1] * b[3] + 1ULL * a[2] * b[2] + 1ULL * a[3] * b[1] + 1ULL * a[4] * b[0];
if(c[4] >= m8) c[4] -= m8;
c[5]  += 1ULL * a[0] * b[5] + 1ULL * a[1] * b[4] + 1ULL * a[2] * b[3] + 1ULL * a[3] * b[2] + 1ULL * a[4] * b[1] + 1ULL * a[5] * b[0];
if(c[5] >= m8) c[5] -= m8;
c[6]  += 1ULL * a[0] * b[6] + 1ULL * a[1] * b[5] + 1ULL * a[2] * b[4] + 1ULL * a[3] * b[3] + 1ULL * a[4] * b[2] + 1ULL * a[5] * b[1] + 1ULL * a[6] * b[0];
if(c[6] >= m8) c[6] -= m8;
c[7]  += 1ULL * a[0] * b[7] + 1ULL * a[1] * b[6] + 1ULL * a[2] * b[5] + 1ULL * a[3] * b[4] + 1ULL * a[4] * b[3] + 1ULL * a[5] * b[2] + 1ULL * a[6] * b[1] + 1ULL * a[7] * b[0];
if(c[7] >= m8) c[7] -= m8;
c[8]  += 1ULL * a[1] * b[7] + 1ULL * a[2] * b[6] + 1ULL * a[3] * b[5] + 1ULL * a[4] * b[4] + 1ULL * a[5] * b[3] + 1ULL * a[6] * b[2] + 1ULL * a[7] * b[1];
if(c[8] >= m8) c[8] -= m8;
c[9]  += 1ULL * a[2] * b[7] + 1ULL * a[3] * b[6] + 1ULL * a[4] * b[5] + 1ULL * a[5] * b[4] + 1ULL * a[6] * b[3] + 1ULL * a[7] * b[2];
if(c[9] >= m8) c[9] -= m8;
c[10] += 1ULL * a[3] * b[7] + 1ULL * a[4] * b[6] + 1ULL * a[5] * b[5] + 1ULL * a[6] * b[4] + 1ULL * a[7] * b[3];
if(c[10] >= m8) c[10] -= m8;
c[11] += 1ULL * a[4] * b[7] + 1ULL * a[5] * b[6] + 1ULL * a[6] * b[5] + 1ULL * a[7] * b[4];
if(c[11] >= m8) c[11] -= m8;
c[12] += 1ULL * a[5] * b[7] + 1ULL * a[6] * b[6] + 1ULL * a[7] * b[5];
if(c[12] >= m8) c[12] -= m8;
c[13] += 1ULL * a[6] * b[7] + 1ULL * a[7] * b[6];
if(c[13] >= m8) c[13] -= m8;
c[14] += 1ULL * a[7] * b[7];
if(c[14] >= m8) c[14] -= m8;
}

void __attribute__((optimize("Ofast")))
  multiply(const int * __restrict a, const int * __restrict b, cat * __restrict c) {
	constexpr cat m8 = mod * mod * 8;
	for(int i = 0; i <= M; i += 8) {
		c[M] += 1ULL * a[i] * b[M-i];
		if(c[M] >= m8) c[M] -= m8;
	}
	for(int i = 0; i < M; i += 8, a += 8) {
		cat * __restrict out_ptr = c + i;
		for(const int * __restrict b_ptr = b, * b_fin = b + M-i; b_ptr != b_fin; b_ptr += 8, out_ptr += 8) {
			multiply_inner(a, b_ptr, out_ptr);
		}
	}
	for(int i = 0; i <= M; i++) c[i] %= mod;
}

template<typename T>
inline void __attribute__((always_inline)) __attribute__((optimize("Ofast"))) clear(T * __restrict ptr) {
	for(int i = 0; i <= M; i++, ptr++) *ptr = 0;
}

template<typename TI, typename TO>
inline void __attribute__((always_inline)) __attribute__((optimize("Ofast"))) copy(const TI * __restrict in, TO * __restrict o) {
	for(TO * __restrict o_fin = o + M + 1; o != o_fin; in++, o++) *o = *in;
}

void solve(int R, int par, auto & G, auto & cnt, int K, cat & ans) {
	cnt[R][0] = 2;
	cat sum = (K == 0);
	bool st = true;
	for(auto v : G[R]) if(v != par) {
		solve(v, R, G, cnt, K, ans);
		if((int)G[v].size() == 1) {
			for(int i = 0; i <= M; i++) out[i] = inv[i];
		}
		else {
			clear(out);
			multiply(inv, &(cnt[v][0]), out);
		}
		out[0] = (out[0]+1) % mod;
		sum = (sum + out[K]) % mod;
		copy(out, outi);
		clear(out_cnt);
		if(st) {
			st = false;
			for(int i = 0; i <= M; i++) cnt[R][i] = outi[i] * 2LL % mod;
		}
		else {
			multiply(&(cnt[R][0]), outi, out_cnt);
			copy(out_cnt, &(cnt[R][0]));
		}
	}
	ans += cnt[R][K] + mod - sum;
	cnt[R][0] = (cnt[R][0]+mod-1)%mod;
}

cat pw(cat a, cat e) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2);
	x = x * x % mod;
	if(e&1) x = x * a % mod;
	return x;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	fac[0] = inv[0] = 1;
	for(int i = 1; i <= M; i++) {
		fac[i] = 1ULL * fac[i-1] * i % mod;
		inv[i] = 1ULL * inv[i-1] * pw(i, mod-2) % mod;
	}
	int N, K;
	cin >> N >> K;
	vector< vector<int> > G(N);
	for(int i = 0; i < N-1; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);
	}
	cat ans = 0;
	vector< vector<int> > cnt(N, vector<int>(M+8, 0));
	solve(0, 0, G, cnt, K, ans);
	ans = ans % mod * fac[K] % mod;
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing