#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

const int mod = 31607;
inline int add (int u, int v) { u += v; if (u >= mod) u -= mod; return u; }
inline int dec (int u, int v) { u -= v; if (u < 0) u += mod; return u; }
inline int qpow (int x, int y) {
    int ret = 1;
    while (y) {
        if (y & 1) ret = ret * x % mod;
        x = x * x % mod; y >>= 1;
    }
    return ret;
}
inline int inv (int x) { return qpow(x, mod - 2); }

int a[22][21], n, N;
void FWT (int *f) {
    for (int i = 2; i <= N; i <<= 1)
        for (int j = 0; j < N; j += i)
            for (int k = j; k < j + (i >> 1); k++)
                f[k] = add(f[k], f[k + (i >> 1)]);
}
void IFWT (int *f) {
    for (int i = 2; i <= N; i <<= 1)
        for (int j = 0; j < N; j += i)
            for (int k = j; k < j + (i >> 1); k++)
                f[k] = dec(f[k], f[k + (i >> 1)]);
}
int f[1 << 21], g[22][1 << 21], savg[22][1 << 21], h[1 << 21];

int solve () {
    int i, j, k;
    for (i = 0; i < N; i++) f[i] = 0;
    f[N - 1] = 1; FWT(f);
    for (i = 1; i <= n; i++) {
        for (j = 0; j < N; j++)
            h[j] = g[i][j];
        FWT(h);
        for (j = 0; j < N; j++) f[j] = f[j] * h[j] % mod;
    }
	int ret = 0; for (i = 0; i < N; i++) if (__builtin_popcount(i) & 1) ret = dec(ret, f[i]); else ret = add(ret, f[i]); return ret;
    // IFWT(f); return f[0];
}

int main () {
    n = read(); N = 1 << n; int i, j;
    for (i = 1; i <= n; i++) for (j = 0; j < n; j++) a[i][j] = 3973 * read() % mod;
	for (i = 1; i <= n; i++) {
		for (j = 0; j < N - 1; j++) {
            g[i][j] = 1;
            for (int k = 0; k < n; k++) {
                if ((j >> k) & 1) g[i][j] = g[i][j] * a[i][k] % mod;
                else g[i][j] = g[i][j] * (mod + 1 - a[i][k]) % mod;
            }
			savg[i][j] = g[i][j];
        }
	}
    int ans = solve(), s1 = 1, s2 = 1;
    for (i = 1; i <= n; i++) s1 = s1 * a[i][i - 1] % mod, s2 = s2 * a[i][n - i] % mod;

	for (i = 1; i <= n; i++) {
		int ival = inv(a[i][i - 1]);
		for (j = 0; j < N; j++) {
			if ((j >> (i - 1)) & 1) g[i][j] = savg[i][j] * ival % mod;
			else g[i][j] = 0;
		}
	}
    ans = dec(ans, s1 * solve() % mod);
    
	for (i = 1; i <= n; i++) {
		int ival = inv(a[i][n - i]);
		for (j = 0; j < N; j++) {
			if ((j >> (n - i)) & 1) g[i][j] = savg[i][j] * ival % mod;
			else g[i][j] = 0;
		}
	}
    ans = dec(ans, s2 * solve() % mod);
    
	for (i = 1; i <= n; i++) {
		int ival1 = inv(a[i][i - 1]), ival2 = inv(a[i][n - i]);
		for (j = 0; j < N; j++) {
			if (((j >> (n - i)) & 1) && ((j >> (i - 1)) & 1)) {
				if (i - 1 != n - i) g[i][j] = savg[i][j] * ival1 % mod * ival2 % mod;
				else g[i][j] = savg[i][j] * ival1 % mod;
			}
			else g[i][j] = 0;
		}
	}
    if (n & 1) ans = add(ans, s1 * s2 % mod * inv(a[(n + 1) >> 1][n >> 1]) % mod * solve() % mod);
    else ans = add(ans, s1 * s2 % mod * solve() % mod);
    
    ans = dec(1, ans); printf("%d\n", ans);
    return 0;
}