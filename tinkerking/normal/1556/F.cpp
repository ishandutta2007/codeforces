#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

template<int MOD, int RT> struct mint {
	static const int mod = MOD;
	static constexpr mint rt() { return RT; } // primitive root for FFT
	int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
	mint() { v = 0; }
	mint(LL _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
		if (v < 0) v += MOD; }
	friend bool operator==(const mint& a, const mint& b) { 
		return a.v == b.v; }
	friend bool operator!=(const mint& a, const mint& b) { 
		return !(a == b); }
	friend bool operator<(const mint& a, const mint& b) { 
		return a.v < b.v; }
	friend void read(mint& a) { LL x; scanf("%lld",&x); a = mint(x); }
   
	mint& operator+=(const mint& m) { 
		if ((v += m.v) >= MOD) v -= MOD; 
		return *this; }
	mint& operator-=(const mint& m) { 
		if ((v -= m.v) < 0) v += MOD; 
		return *this; }
	mint& operator*=(const mint& m) { 
		v = int((LL)v*m.v%MOD); return *this; }
	mint& operator/=(const mint& m) { return (*this) *= inv(m); }
	friend mint pow(mint a, LL p) {
		mint ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans; }
	friend mint inv(const mint& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	mint operator-() const { return mint(-v); }
	mint& operator++() { return *this += 1; }
	mint& operator--() { return *this -= 1; }
	friend mint operator+(mint a, const mint& b) { return a += b; }
	friend mint operator-(mint a, const mint& b) { return a -= b; }
	friend mint operator*(mint a, const mint& b) { return a *= b; }
	friend mint operator/(mint a, const mint& b) { return a /= b; }
};

const int MOD = 1e9 + 7;
typedef mint<MOD,5> mi; // 5 is primitive root for both common mods

int n, M;
mi a[20], b[20][20], dp[1 << 14], fucked[14][1 << 14];
unordered_map<int, mi> beat[1 << 14];

int main() {
    scanf("%d",&n);
    M = 1 << n;
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d",&tmp);
        a[i] = tmp;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            b[i][j] = (a[i]) / (a[i] + a[j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < M; j++) {
            fucked[i][j] = 1;
            for (int k = 0; k < n; k++) {
                if (j & (1 << k)) fucked[i][j] *= b[k][i];
            }
        }
    }
    for (int mask = 0; mask < M; mask++) {
        int other = (M - 1) ^ mask;
        for (int t = other; t; t = (t - 1) & other) {
            mi ret = 1;
            for (int i = 0; i < n; i++) {
                if (t & (1 << i)) {
                    ret *= fucked[i][mask];
                }
            }
            //printf("beat %d %d = %d\n",mask,t,int(ret));
            beat[mask][t] = ret;
        }
        beat[mask][0] = 1;
    }
    mi ans = 0;
    for (int mask = 0; mask < M; mask++) {
        dp[mask] = 1;
        for (int sub = mask; sub; sub = (sub - 1) & mask) {
            if (sub == mask) continue;
            //printf("?? %d %d %d\n",mask,sub,int(beat[sub][mask^sub]));
            dp[mask] -= dp[sub] * beat[sub][mask ^ sub];
        }
        //printf("dp[%d] = %d\n",mask,int(dp[mask]));
        ans += dp[mask] * __builtin_popcount(mask) * beat[mask][(M - 1) ^ mask];
    }
    printf("%d\n",int(ans));
}