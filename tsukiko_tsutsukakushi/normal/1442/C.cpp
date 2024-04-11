/**
 *    author:  otera    
**/
#include<iostream>
#include<string> 
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm> 
#include<functional>
#include<iomanip>
#include<queue>
#include<deque>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<cassert>
#include<array>
using namespace std;

#define int long long
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60 ;
const ll mod=1e9+7 ;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<int, int> P;
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// modint: mod  int 
template<int MOD> struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0) val += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr Fp operator - () const noexcept {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    constexpr Fp& operator -= (const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr Fp& operator *= (const Fp& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator == (const Fp& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const Fp& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
        return os << x.val;
    }
    friend constexpr istream& operator >> (istream &is, Fp<MOD>& x) noexcept {
        return is >> x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};

// 
template<class T> struct BiCoef {
    vector<T> fact_, inv_, finv_;
    constexpr BiCoef() {}
    constexpr BiCoef(int n) noexcept : fact_(n, 1), inv_(n, 1), finv_(n, 1) {
        init(n);
    }
    constexpr void init(int n) noexcept {
        fact_.assign(n, 1), inv_.assign(n, 1), finv_.assign(n, 1);
        int MOD = fact_[0].getmod();
        for(int i = 2; i < n; i++){
            fact_[i] = fact_[i-1] * i;
            inv_[i] = -inv_[MOD%i] * (MOD/i);
            finv_[i] = finv_[i-1] * inv_[i];
        }
    }
    constexpr T com(int n, int k) const noexcept {
        if (n < k || n < 0 || k < 0) return 0;
        return fact_[n] * finv_[k] * finv_[n-k];
    }
    constexpr T fact(int n) const noexcept {
        if (n < 0) return 0;
        return fact_[n];
    }
    constexpr T inv(int n) const noexcept {
        if (n < 0) return 0;
        return inv_[n];
    }
    constexpr T finv(int n) const noexcept {
        if (n < 0) return 0;
        return finv_[n];
    }
};

// const int MOD = 1000000007;
const int MOD = 998244353;
using mint = Fp<MOD>;
BiCoef<mint> bc;

typedef pair<int, pair<int, int>> P2;
typedef pair<int, array<int, 3>> P3;

int n, m;
vector<vector<int>> g, invg;

void solve() {
	cin >> n >> m;
    g.assign(n, vector<int>());
    invg.assign(n, vector<int>());
    rep(i, m) {
        int a, b; cin >> a >> b;
        -- a, -- b;
        g[a].push_back(b);
        invg[b].push_back(a);
    }
    priority_queue<P2, vector<P2>, greater<P2>> pque;
    vector<vector<int>> cnt(2, vector<int>(n, inf));
    cnt[0][0] = 0;
    pque.push({0, {0, 0}});
    while(pque.size()) {
        P2 p = pque.top(); pque.pop();
        int v = p.sc.fr, co = p.fr, num = p.sc.sc;
        if(co > cnt[num][v]) continue;
        for(int nv: g[v]) {
            if(num == 0) {
                if(chmin(cnt[0][nv], cnt[0][v])) {
                    pque.push({cnt[0][nv], {nv, 0}});
                }
            } else {
                if(chmin(cnt[0][nv], cnt[1][v] + 1)) {
                    pque.push({cnt[0][nv], {nv, 0}});
                }
            }
        }
        for(int nv: invg[v]) {
            if(num == 0) {
                if(chmin(cnt[1][nv], cnt[0][v] + 1)) {
                    pque.push({cnt[1][nv], {nv, 1}});
                }
            } else {
                if(chmin(cnt[1][nv], cnt[1][v])) {
                    pque.push({cnt[1][nv], {nv, 1}});
                }
            }
        }
        // if(chmin(cnt[num ^ 1][v], cnt[num][v] + 1)) {
        //     pque.push({cnt[num ^ 1][v], {v, num ^ 1}});
        // }
    }
    vector<vector<vector<int>>> dist(2, vector<vector<int>>(32, vector<int>(n, inf)));
    dist[0][0][0] = 0;
    priority_queue<P3, vector<P3>, greater<P3>> pque2;
    pque2.push({0, {0, 0, 0}});
    while(pque2.size()) {
        auto p = pque2.top(); pque2.pop();
        int di = p.fr, num = p.sc[0], fi = p.sc[1], v = p.sc[2];
        int co = cnt[num][v] + fi;
        if(di > dist[num][fi][v]) continue;
        for(int nv: g[v]) {
            int nnum = 0;
            int nfi = co + (num == 1) - cnt[nnum][nv];
            if(nfi >= 0 and nfi < 32 and chmin(dist[nnum][nfi][nv], dist[num][fi][v] + 1)) {
                pque2.push({dist[nnum][nfi][nv], {nnum, nfi, nv}});
            }
        }
        for(int nv: invg[v]) {
            int nnum = 1;
            int nfi = co + (num == 0) - cnt[nnum][nv];
            if(nfi >= 0 and nfi < 32 and chmin(dist[nnum][nfi][nv], dist[num][fi][v] + 1)) {
                pque2.push({dist[nnum][nfi][nv], {nnum, nfi, nv}});
            }
        }
    }
    ll ans = INF;
    mint ans2 = 0;
    bool check = 0;
    int tmp = inf;
    rep(i, 2) {
        rep(j, 32) {
            int co = cnt[i][n - 1] + j;
            ll di = dist[i][j][n - 1];
            if(co <= 60) {
                check = 1;
                chmin(ans, di + (1LL<<co) - 1);
            } else {
                if(chmin(tmp, co)) {
                    ans2 = (mint)di + modpow((mint)2, co) - (mint)1;
                }
            }
        }
    }
    if(check) {
        cout << ans % MOD << endl;
    } else {
        cout << ans2 << endl;
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}