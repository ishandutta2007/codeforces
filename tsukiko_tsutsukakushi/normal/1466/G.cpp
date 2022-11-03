/**
 *    author:  otera    
**/
#include<bits/stdc++.h>
using namespace std;

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

vector<int> Zalgo(const string& s) {
    int n = (int)s.size();
    vector<int> res(n);
    res[0] = n;
    int i = 1, j = 0;
    while(i < n) {
        while(i + j < n && s[j] == s[i+j]) ++j;
        res[i] = j;
        if(j == 0) {++i; continue;}
        int k = 1;
        while(i + k < n && k + res[k] < j) res[i + k] = res[k], ++k;
        i += k, j -= k;
    }
    return res;
}

const int MAX = 1000007;
mint pw[200200];

void solve() {
    pw[0] = 1;
    for(int i = 1; i < 200200; ++ i) pw[i] = pw[i - 1] * 2;
    int n, q; cin >> n >> q;
    string s0, t; cin >> s0 >> t;
    vector<string> s(n + 1, "?");
    s[0] = s0;
    int ma = -1;
    rep(i, n) {
        s[i + 1] = s[i] + t[i] + s[i];
        if((int)s[i + 1].size() >= MAX) {
            ma = i + 1;
            break;
        }
    }
    int sz = (int)s0.size();
    vector<vector<mint>> sum(26, vector<mint>(n + 1, 0));
    rep(i, n) {
        rep(j, 26) {
            sum[j][i + 1] = sum[j][i];
        }
        sum[t[i] - 'a'][i + 1] += pw[n - (i + 1)];
    }
    rep(_, q) {
        int k; string w; cin >> k >> w;
        int id = 0;
        while(id < k and s[id].size() < w.size()) {
            ++ id;
        }
        // cerr << "id = " << id << "\n";
        mint fsum = 0, gsum = 0;
        // fsum
        string v = w + '?' + s[id];
        auto zalgo_v = Zalgo(v);
        for(int i = (int)w.size() + 1; i < (int)zalgo_v.size(); ++ i) {
            fsum += (zalgo_v[i] >= (int)w.size());
        }
        fsum *= pw[k - id];
        // cerr << t << "\n";
        // gsum
        // for(int i = id + 1; i <= k; ++ i) {
        //     char c = t[i - 1];
        //     // cerr << i << " " << c << "\n";
        //     int j = min(id, i - 1);
        //     string u = w + '?' + s[j] + c + s[j];
        //     auto zalgo_u = Zalgo(u);
        //     mint g = 0;
        //     int pos = (int)w.size() + 1 + (int)s[j].size();
        //     for(int i = max((int)w.size() + 1, pos + 1 - (int)w.size()); i <= pos; ++ i) {
        //         g += (zalgo_u[i] >= (int)w.size());
        //     }
        //     // cerr << w << "\n";
        //     // cerr << u << " " << g << "\n";
        //     gsum += g * pw[k - i];
        // }
        vector<mint> cnt(26, 0);
        // for(int i = id + 1; i <= k; ++ i) {
        //     cnt[t[i - 1] - 'a'] += pw[k - i];
        // }
        rep(j, 26) {
            cnt[j] = sum[j][k] - sum[j][id];
            cnt[j] /= pw[n - k];
            mint g = 0;
            char c = 'a' + j;
            string u = w + '?' + s[id] + c + s[id];
            auto zalgo_u = Zalgo(u);
            int pos = (int)w.size() + 1 + (int)s[id].size();
            for(int i = max((int)w.size() + 1, pos + 1 - (int)w.size()); i <= pos; ++ i) {
                g += (zalgo_u[i] >= (int)w.size());
            }
            gsum += g * cnt[j];
        }
        cout << fsum + gsum << "\n";
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}