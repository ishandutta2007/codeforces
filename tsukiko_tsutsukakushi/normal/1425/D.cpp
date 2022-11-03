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

const int MOD = 1000000007;
//const int MOD = 998244353;
using mint = Fp<MOD>;
BiCoef<mint> bc;

template<typename T>
vector<T> compress(vector<T> A){
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    return A;
}

void solve() {
	int n, m, r; cin >> n >> m >> r;
    vector<int> x(n), y(n), b(n);
    vector<int> X, Y;
    rep(i, n) {
        cin >> x[i] >> y[i] >> b[i];
        X.push_back(x[i]), X.push_back(x[i] - r), X.push_back(x[i] + r);
        Y.push_back(y[i]), Y.push_back(y[i] - r), Y.push_back(y[i] + r);
    }
    auto comx = compress(X);
    auto comy = compress(Y);
    int szx = (int)comx.size(), szy = (int)comy.size();
    vector<vector<int>> co(szx + 1, vector<int>(szy + 1, 0));
    rep(i, n) {
        int cx = lower_bound(all(comx), x[i]) - comx.begin();
        int cy = lower_bound(all(comy), y[i]) - comy.begin();
        co[cx][cy] ++;
    }
    vector<vector<int>> sco(szx + 1, vector<int>(szy + 1, 0));
    for(int i = 1; i <= szx; ++ i) {
        for(int j = 1; j <= szy; ++ j) {
            sco[i][j] = sco[i - 1][j] + sco[i][j - 1] - sco[i - 1][j - 1] + co[i - 1][j - 1];
        }
    }
    vector<int> cnt(n, 0);
    vector<vector<int>> cnt2(n, vector<int>(n, 0));
    rep(i, n) {
        rep(j, n) {
            if(max(abs(x[i] - x[j]), abs(y[i] - y[j])) <= r) {
                ++ cnt[i];
            }
        }
    }
    // rep(i, n) {
    //     rep(j, n) {
    //         rep(k, n) {
    //             if(max(abs(x[i] - x[k]), abs(y[i] - y[k])) <= r and max(abs(x[j] - x[k]), abs(y[j] - y[k])) <= r ) {
    //                 ++ cnt2[i][j];
    //             }
    //         }
    //     }
    // }
    rep(i, n) {
        for(int j = i + 1; j < n; ++ j) {
            int xmi = max(x[i] - r, x[j] - r);
            int xma = min(x[i] + r, x[j] + r);
            int ymi = max(y[i] - r, y[j] - r);
            int yma = min(y[i] + r, y[j] + r);
            if(xmi > xma or ymi > yma) continue;
            int cxmi = lower_bound(all(comx), xmi) - comx.begin();
            int cxma = lower_bound(all(comx), xma) - comx.begin();
            int cymi = lower_bound(all(comy), ymi) - comy.begin();
            int cyma = lower_bound(all(comy), yma) - comy.begin();
            cnt2[i][j] = sco[cxma + 1][cyma + 1] - sco[cxma + 1][cymi] - sco[cxmi][cyma + 1] + sco[cxmi][cymi];
        }
    }
    bc.init(500500);
    mint ans = 0;
    rep(i, n) {
        ans += modpow((mint)b[i], 2) * (bc.com(n, m) - bc.com(n - cnt[i], m));
    }
    rep(i, n) {
        for(int j = i + 1; j < n; ++ j) {
            ans += (mint)2 * (mint)b[i] * (mint)b[j] * (bc.com(n, m) - bc.com(n - cnt[i], m) - bc.com(n - cnt[j], m) + bc.com(n - (cnt[i] + cnt[j] - cnt2[i][j]), m));
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