/**
 *    author:  otera    
**/
#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60;
#define rep(i, n) for(int i = 0; i < n; ++ i)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
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

void solve() {
	int n, m; cin >> n >> m;
    vector<vector<char>> f(n, vector<char>(m));
    rep(i, n) {
        rep(j, m) {
            cin >> f[i][j];
        }
    } 
    if(n == 1 and m == 1) {
        if(f[0][0] == '.') cout << 1 << "\n";
        else cout << 0 << "\n";
        return;
    }
    vector<vector<int>> cntr(n, vector<int>(m, 0)), cntd(n, vector<int>(m, 0));
    rep(i, n) {
        cntr[i][m - 1] = (f[i][m - 1] == 'R' ? 1 : 0);
        per(j, m - 1) {
            cntr[i][j] = cntr[i][j + 1] + (f[i][j] == 'R' ? 1 : 0);
        }
    }
    rep(j, m) {
        cntd[n - 1][j] = (f[n - 1][j] == 'R' ? 1 : 0);
        per(i, n - 1) {
            cntd[i][j] = cntd[i + 1][j] + (f[i][j] == 'R' ? 1 : 0);
        }
    }
    vector<vector<mint>> dpu(n, vector<mint>(m, 0)), dpl(n, vector<mint>(m, 0));
    dpu[0][0] = 1, dpl[0][0] = 1;
    if(1 < n) dpu[1][0] = -1;
    if(1 < m) dpl[0][1] = -1;
    rep(i, n) {
        rep(j, m) {
            if(j - 1 >= 0) dpl[i][j] += dpl[i][j - 1];
            if(i - 1 >= 0) dpu[i][j] += dpu[i - 1][j];
            // right dpu[i][j]
            if(j + 1 < m) {
                int mi = j + 1, ma = m - 1 - cntr[i][j + 1];
                dpl[i][mi] += dpu[i][j];
                if(ma + 1 < m) dpl[i][ma + 1] -= dpu[i][j];
            }
            // down
            if(i + 1 < n) {
                int mi = i + 1, ma = n - 1 - cntd[i + 1][j];
                dpu[mi][j] += dpl[i][j];
                if(ma + 1 < n) dpu[ma + 1][j] -= dpl[i][j];
            }
        }
    }
    cout << dpu[n - 1][m - 1] + dpl[n - 1][m - 1] << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}