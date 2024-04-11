/**
 *    author:  otera    
**/
#include<bits/stdc++.h>
using namespace std;

// #define int long long
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(int i = 0; i < n; ++ i)
#define per(i,n) for(int i=n-1;i>=0;i--)
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

// 
//  LCP 
struct RollingHash {
    static const int base1 = 1007, base2 = 2009;
    static const int mod1 = 1000000007, mod2 = 1000000009;
    vector<long long> hash1, hash2, power1, power2;

    // construct
    RollingHash(const string &S) {
        int n = (int)S.size();
        hash1.assign(n+1, 0);
        hash2.assign(n+1, 0);
        power1.assign(n+1, 1);
        power2.assign(n+1, 1);
        for (int i = 0; i < n; ++i) {
            hash1[i+1] = (hash1[i] * base1 + S[i]) % mod1;
            hash2[i+1] = (hash2[i] * base2 + S[i]) % mod2;
            power1[i+1] = (power1[i] * base1) % mod1;
            power2[i+1] = (power2[i] * base2) % mod2;
        }
    }
    
    // get hash of S[left:right)
    inline pair<long long, long long> get(int l, int r) const {
        long long res1 = hash1[r] - hash1[l] * power1[r-l] % mod1;
        if (res1 < 0) res1 += mod1;
        long long res2 = hash2[r] - hash2[l] * power2[r-l] % mod2;
        if (res2 < 0) res2 += mod2;
        return {res1, res2};
    }

    // get lcp of S[a:] and S[b:]
    inline int getLCP(int a, int b) const {
        int len = min((int)hash1.size()-a, (int)hash1.size()-b);
        int low = 0, high = len;
        while (high - low > 1) {
            int mid = (low + high) >> 1;
            if (get(a, a+mid) != get(b, b+mid)) high = mid;
            else low = mid;
        }
        return low;
    }

    // get lcp of S[a:] and T[b:]
    inline int getLCP(const RollingHash &T, int a, int b) const {
        int len = min((int)hash1.size()-a, (int)hash1.size()-b);
        int low = 0, high = len;
        while (high - low > 1) {
            int mid = (low + high) >> 1;
            if (get(a, a+mid) != T.get(b, b+mid)) high = mid;
            else low = mid;
        }
        return low;
    }
};

template<typename T, typename S>
struct LazySegmentTree{
private:
    int n;
    vector<T> node;
    vector<S> lazy;
    T E0;
    S E1;

    inline void updatef(S& lazy,S& value){
        lazy += value;
        //lazy = max(lazy, value);
        //lazy = min(lazy, value);
    }
    inline void calculatef(T& node,S& lazy,int len){
        node += lazy * len; //sum
        //node += lazy ; //max
    }
    inline T queryf(T& x,T& y){
        return x + y;
        //return x * y;
        //return max(x, y);
    }
public:
    LazySegmentTree(int sz,T nodeE,S lazyE ):E0(nodeE), E1(lazyE){
        n=1;
        while(n<sz)n<<=1;
        node.resize(2*n-1,E0);
        lazy.resize(2*n-1,E1);
    }

    LazySegmentTree(vector<T>& v,T E0,S E1 ):E0(E0),E1(E1){
        n=1;
        int sz=v.size();
        while(n<sz)n<<=1;
        node.resize(2*n-1,E0);
        lazy.resize(2*n-1,E1);
        rep(i,sz)node[i+n-1] = v[i];
        for(int i=n-2; i>=0; --i){
            node[i] = queryf(node[2*i+1],node[2*i+2]);
        }
    }

    void eval(int k,int l,int r){
        if(lazy[k]==E1)return ;
        calculatef(node[k], lazy[k], r-l);
        if(r-l>1){
            updatef(lazy[2*k+1], lazy[k]);
            updatef(lazy[2*k+2], lazy[k]);
        }
        lazy[k]=E1;
    }

    void update(int a, int b, S x,int k=0,int l=0,int r=-1){
        if(r<0)r=n;
        eval(k,l,r);
        if(r<=a||b<=l)return;
        if(a<=l&&r<=b){
            updatef(lazy[k], x);
            eval(k,l,r);
        }
        else {
            update(a,b,x,2*k+1,l,(l+r)/2);
            update(a,b,x,2*k+2,(l+r)/2,r);
            node[k]=queryf(node[2*k+1], node[2*k+2]);
        }
    }

    T query(int a,int b,int k=0,int l=0,int r=-1){
        if(r<0)r=n;
        eval(k,l,r);
        if(r<=a||b<=l)return E0;
        if(a<=l&&r<=b)return node[k];
        T xl=query(a,b,2*k+1,l,(l+r)/2);
        T xr=query(a,b,2*k+2,(l+r)/2,r);
        return queryf(xl, xr);
    }
};

void solve() {
	string s, t; cin >> s >> t;
    int n = (int)s.size(), m = (int)t.size();
    if(n < m) {
        cout << 0 << endl;
        return;
    }
    RollingHash rhs(s), rht(t);
    vector<int> nxt(n + 1, n + 1);
    for(int i = n - m; i >= 0; -- i) {
        if(rhs.get(i, i + m) == rht.get(0, m)) {
            nxt[i] = i + m;
        } else {
            nxt[i] = nxt[i + 1];
        }
        // cerr << nxt[i] << endl;
    }
    LazySegmentTree<mint, mint> dp(n + 2, 0, 0);
    for(int i = 0; i <= n; ++ i) {
        mint x = dp.query(0, i + 1);
        // cerr << x << endl;
        dp.update(nxt[i], n + 1, x + 1);
    }
    cout << dp.query(0, n + 1) << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}