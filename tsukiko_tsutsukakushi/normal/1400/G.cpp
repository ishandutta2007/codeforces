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
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
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
#define debug(x)  cerr << #x << " = " << (x) << endl;
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
//const int MOD = 1000000007;
const int MOD = 998244353;
using mint = Fp<MOD>;
BiCoef<mint> bc;

struct UnionFind {
    vector<int> par, w;
    
    UnionFind(int n) : par(n, -1), w(n, 0) { }
    void init(int n) { par.assign(n, -1); w.assign(n, 0); }
    
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) {
            ++w[x];
            return false;
        }
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        w[x] += w[y];
        ++w[x];
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
 
    int wei(int x) {
        return w[root(x)];
    }
};

int n, m;
vector<int> l, r;
vector<vector<int>> adj;
vector<vector<int>> comps;
vector<vector<vector<int>>> comp_dp;

void solve() {
	cin >> n >> m;
    bc.init(600600);
    l.resize(n), r.resize(n);
    rep(i, n) {
        cin >> l[i] >> r[i];
    }
    adj.assign(n, vector<int>());
    UnionFind uf(n);
    rep(i, m) {
        int a, b; cin >> a >> b;
        -- a, -- b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        uf.merge(a, b);
    }
    rep(i, n) sort(all(adj[i]));
    rep(r, n) {
        if(uf.root(r) == r and uf.size(r) > 1) {
            vector<int> comp;
            rep(i, n) {
                if(uf.root(i) == r) comp.push_back(i);
            }
            comps.push_back(comp);
        }
    }
    int sz = (int)comps.size();
    comp_dp.assign(sz, vector<vector<int>>());
    rep(c, sz) {
        int csz = (int)comps[c].size();
        auto &dp = comp_dp[c];
        vector<vector<bool>> bad(csz, vector<bool>(csz, 0));
        rep(i, csz) {
            rep(j, csz) {
                bad[i][j] = binary_search(all(adj[comps[c][i]]), comps[c][j]);
            }
        }
        dp.assign((1<<csz), vector<int>(csz + 1, 0));
        for(int mask = 0; mask < (1<<csz); ++ mask) {
            bool check = 1;
            rep(i, csz) {
                if(mask & (1<<i)) {
                    for(int j = i + 1; j < csz; ++ j) {
                        if(mask & (1<<j)) {
                            if(bad[i][j]) {
                                check = 0;
                            }
                        }
                    }
                }
            }
            if(check) dp[mask][__builtin_popcount(mask)] = 1;
        }
        rep(i, csz) {
            rep(bit, csz) {
                for(int mask = 0; mask < (1<<csz); ++ mask) {
                    if(mask >> bit & 1) {
                        dp[mask][i] += dp[mask ^ (1<<bit)][i]; //
                    }
                }
            }
        }
    }
    vector<int> fq(n + 2, 0);
    rep(i, n) {
        fq[l[i]] ++;
        fq[r[i] + 1] --;
    }
    rep(i, n + 1) {
        fq[i + 1] += fq[i];
    }
    mint ans = 0;
    for(int num = 1; num <= n; ++ num) {
        int cnt = fq[num];
        vector<mint> knp(2 * m + 1, 0);
        knp[0] = 1;
        rep(c, sz) {
            int mask = 0;
            rep(i, comps[c].size()) {
                if(l[comps[c][i]] <= num and num <= r[comps[c][i]]) {
                    -- cnt;
                    mask |= (1<<i);
                }
            }
            per(i, 2 * m + 1) {
                for(int j = 1; j <= __builtin_popcount(mask); ++ j) {
                    if(i - j >= 0) knp[i] += knp[i - j] * comp_dp[c][mask][j];
                }
            }
        }
        for(int co = 0; co <= 2 * m; ++ co) {
            ans += knp[co] * bc.com(cnt, num - co);
        }
    }
    cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}