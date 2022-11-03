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
const int MOD = 1000000007;
//const int MOD = 998244353;
using mint = Fp<MOD>;

// struct UnionFind {
//     vector<int> par, w, ck;
    
//     UnionFind(int n) : par(n, -1), w(n, 0), ck(n, -1) { }
    
//     int root(int x) {
//         if (par[x] < 0) return x;
//         else return par[x] = root(par[x]);
//     }
    
//     bool issame(int x, int y) {
//         return root(x) == root(y);
//     }
    
//     int merge(int x, int y) {
//         x = root(x); y = root(y);
//         if (x == y) {
//             ++w[x];
//             return -1;
//         }
//         int res = -1;
//         if (par[x] > par[y]) swap(x, y); // merge technique
//         if(ck[x] >= 0 and ck[y] >= 0) {
//             if(ck[x] > ck[y]) {
//                 res = ck[y];
//                 ck[x] = ck[y]; ck[y] = -1;
//             } else {
//                 res = ck[x];
//                 ck[y] = -1;
//             }
//         } else if(ck[y]) {
//             ck[x] = ck[y];
//             ck[y] = -1;
//         }
//         par[x] += par[y];
//         par[y] = x;
//         w[x] += w[y];
//         ++w[x];
//         return res;
//     }
    
//     int size(int x) {
//         return -par[root(x)];
//     }
 
//     int wei(int x) {
//         return w[root(x)];
//     }

//     int check(int x) {
//         return ck[root(x)];
//     }

//     void on(int x, int i) {
//         x = root(x);
//         ck[x] = i;
//     }
// };

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

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, n) {
        int k; cin >> k;
        rep(j, k) {
            int x;
            cin >> x; -- x;
            g[i].push_back(x);
        }
    }
    UnionFind uf(m);
    int num = -1;
    set<int> b;
    // rep(i, n) {
    //     if(g[i].size() >= 2) {
    //         // cerr << i << "\n";
    //         int x = g[i][0], y = g[i][1];
    //         if(!uf.issame(x, y)) {
    //             b.insert(i);
    //             int res = uf.merge(x, y);
    //             if(res != -1) b.erase(res);
    //         }
    //     } else {
    //         int x = g[i][0];
    //         // cerr << uf.check(x) << "\n";
    //         if(uf.check(x) == -1) {
    //             b.insert(i);
    //             uf.on(x, i);
    //             // cerr << i << "\n";
    //         }
    //     }
    // }
    rep(i, n) {
        if(g[i].size() >= 2) {
            int x = g[i][0], y = g[i][1];
            if(!uf.issame(x, y)) {
                b.insert(i);
                uf.merge(x, y);
                // if(res != -1) b.erase(res);
            }
        } else {
            int x = g[i][0];
            // cerr << uf.check(x) << "\n";
            // if(uf.check(x) == -1) {
            //     b.insert(i);
            //     uf.on(x, i);
            //     // cerr << i << "\n";
            // }
            if(num == -1 or !uf.issame(num, x)) {
                if(num != -1) uf.merge(num, x);
                b.insert(i);
                num = x;
            }
        }
    }
    int sz = (int)b.size();
    cout << modpow((mint)2, sz) << " " << sz << "\n";
    for(int x: b) {
        cout << x + 1 << " ";
    }
    cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}