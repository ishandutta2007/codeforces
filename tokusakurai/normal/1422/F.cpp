#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define each(e, v) for(auto &e: v)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
//const int MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

struct io_setup{
    io_setup(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
    }
} io_setup;

template<int mod>
struct Mod_Int{
    int x;

    Mod_Int() : x(0) {}

    Mod_Int(ll y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    Mod_Int &operator += (const Mod_Int &p){
        if((x += p.x) >= mod) x -= mod;
        return *this;
    }

    Mod_Int &operator -= (const Mod_Int &p){
        if((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }

    Mod_Int &operator *= (const Mod_Int &p){
        x = (int) (1LL * x * p.x % mod);
        return *this;
    }

    Mod_Int &operator /= (const Mod_Int &p){
        *this *= p.inverse();
        return *this;
    }

    Mod_Int &operator ++ () {return *this += Mod_Int(1);}

    Mod_Int operator ++ (int){
        Mod_Int tmp = *this;
        ++*this;
        return tmp;
    }

    Mod_Int &operator -- () {return *this -= Mod_Int(1);}

    Mod_Int operator -- (int){
        Mod_Int tmp = *this;
        --*this;
        return tmp;
    }

    Mod_Int operator - () const {return Mod_Int(-x);}

    Mod_Int operator + (const Mod_Int &p) const {return Mod_Int(*this) += p;}

    Mod_Int operator - (const Mod_Int &p) const {return Mod_Int(*this) -= p;}

    Mod_Int operator * (const Mod_Int &p) const {return Mod_Int(*this) *= p;}

    Mod_Int operator / (const Mod_Int &p) const {return Mod_Int(*this) /= p;}

    bool operator == (const Mod_Int &p) const {return x == p.x;}

    bool operator != (const Mod_Int &p) const {return x != p.x;}

    Mod_Int inverse() const {
        assert(*this != Mod_Int(0));
        return pow(mod-2);
    }

    Mod_Int pow(ll k) const{
        Mod_Int now = *this, ret = 1;
        for(; k; k >>= 1, now *= now){
            if(k&1) ret *= now;
        }
        return ret;
    }

    friend ostream &operator << (ostream &os, const Mod_Int &p){
        return os << p.x;
    }

    friend istream &operator >> (istream &is, Mod_Int &p){
        ll a;
        is >> a;
        p = Mod_Int<mod>(a);
        return is;
    }
};

using mint = Mod_Int<MOD>;

template<typename T> vector<T> divisors(const T &n){
    vector<T> ret;
    for(T i = 1; i*i <= n; i++){
        if(n%i == 0){
            ret.pb(i);
            if(i*i != n) ret.pb(n/i);
        }
    }
    sort(all(ret));
    return ret;
}

template<typename T> vector<pair<T, int>> prime_factor(T n){
    vector<pair<T, int>> ret;
    for(T i = 2; i*i <= n; i++){
        int cnt = 0;
        while(n%i == 0) cnt++, n /= i;
        if(cnt > 0) ret.eb(i, cnt);
    }
    if(n > 1) ret.eb(n, 1);
    return ret;
}

template<typename T> bool is_prime(const T &n){
    if(n == 1) return false;
    for(T i = 2; i*i <= n; i++){
        if(n%i == 0) return false;
    }
    return true;
}

vector<bool> Eratosthenes(const int &n){
    vector<bool> ret(n+1, true);
    if(n >= 0) ret[0] = false;
    if(n >= 1) ret[1] = false;
    for(int i = 2; i*i <= n; i++){
        if(!ret[i]) continue;
        for(int j = i+i; j <= n; j += i) ret[j] = false;
    }
    return ret;
}

vector<int> Eratosthenes2(const int &n){
    vector<int> ret(n+1);
    iota(all(ret), 0);
    if(n >= 0) ret[0] = -1;
    if(n >= 1) ret[1] = -1;
    for(int i = 2; i*i <= n; i++){
        if(ret[i] < i) continue;
        for(int j = i+i; j <= n; j += i) chmin(ret[j], i);
    }
    return ret;
}

template<typename Monoid>
struct Segment_Tree{
    using F = function<Monoid(Monoid, Monoid)>;
    int n;
    vector<Monoid> seg;
    const F f;
    const Monoid e1;
    
    Segment_Tree(const vector<Monoid> &v, const F &f, const Monoid &e1) : f(f), e1(e1){
        int m = sz(v);
        n = 1;
        while(n < m) n <<= 1;
        seg.assign(2*n, e1);
        copy(all(v), seg.begin()+n);
        for(int i = n-1; i > 0; i--) seg[i] = f(seg[2*i], seg[2*i+1]);
    }
 
    Monoid query(int l, int r) const{
        Monoid L = e1, R = e1;
        l += n, r += n;
        while(l < r){
            if(l&1) L = f(L, seg[l++]);
            if(r&1) R = f(seg[--r], R);
            l >>= 1, r >>= 1;
        }
        return f(L, R);
    }
};

template<typename Monoid>
struct Segment_Tree_2{
    using F = function<Monoid(Monoid, Monoid)>;
    int n;
    vector<Monoid> seg;
    vector<vector<mint>> seg2;
    const F f;
    const Monoid e1;
    
    Segment_Tree_2(const vector<Monoid> &v, const F &f, const Monoid &e1) : f(f), e1(e1){
        int m = sz(v);
        n = 1;
        while(n < m) n <<= 1;
        seg.assign(2*n, e1), seg2.resize(2*n);
        copy(all(v), seg.begin()+n);
        rep(i, n) build(seg[n+i], seg2[n+i]);

        for(int i = n-1; i > 0; i--){
            seg[i] = f(seg[2*i], seg[2*i+1]);
            build(seg[i], seg2[i]);
        }
    }

    void build(Monoid a, vector<mint> &b){
        int k = sz(a);
        b.assign(k+1, 1);
        rep(i, k) b[i+1] = b[i]*a[i].second;
    }

    mint sub_query(int i, int a){
        return seg2[i][lower_bound(all(seg[i]), pii(a, 0))-begin(seg[i])];
    }
 
    mint query(int l, int r, int a){
        mint ret = 1;
        l += n, r += n;
        while(l < r){
            if(l&1) ret *= sub_query(l++, a);
            if(r&1) ret *= sub_query(--r, a);
            l >>= 1, r >>= 1;
        }
        return ret;
    }
};

int main(){
    int N; cin >> N;

    vector<int> a(N), pre(N);
    rep(i, N) cin >> a[i];

    int MAX = 200000;

    vector<int> table = Eratosthenes2(MAX);
    vector<int> ps, id(500, -1);

    for(int i = 2; i*i <= MAX; i++){
        if(table[i] == i){
            id[i] = sz(ps), ps.eb(i);
        }
    }
    int K = sz(ps);
    
    auto f = [](vector<int> a, vector<int> b){
        vector<int> ret(sz(a), 0);
        rep(i, sz(a)) ret[i] = max(a[i], b[i]);
        return ret;
    };
    vector<int> e(K, 0);
    vector<vector<int>> v(N, vector<int>(K, 0));
    rep(i, N){
        while(a[i] > 1){
            int x = table[a[i]];
            if(1LL*x*x > MAX) break;
            v[i][id[x]]++, a[i] /= x;
        }
    }
    Segment_Tree<vector<int>> seg(v, f, e);

    vector<int> tmp(MAX+1, -1);
    rep(i, N){
        pre[i] = tmp[a[i]];
        tmp[a[i]] = i;
    }

    auto F = [](vector<pii> a, vector<pii> b){
        vector<pii> ret;
        int n = sz(a), m = sz(b);
        for(int i = 0, j = 0; i < n || j < m;){
            if(j == m) ret.eb(a[i++]);
            else if(i == n) ret.eb(b[j++]);
            else if(a[i] < b[j]) ret.eb(a[i++]);
            else ret.eb(b[j++]);
        }
        return ret;
    };
    vector<pii> E(0);
    vector<vector<pii>> V(N);
    rep(i, N) V[i].eb(pre[i], a[i]);
    
    Segment_Tree_2<vector<pii>> seg2(V, F, E);
    
    int last = 0, Q; cin >> Q;
    while(Q--){
        int x, y; cin >> x >> y;
        x += last, x %= N, y += last, y %= N;
        if(x > y) swap(x, y);
        y++;

        mint ans = 1;
        vector<int> tmp = seg.query(x, y);
        rep(i, K){
            ans *= mint(ps[i]).pow(tmp[i]);
        }
        ans *= seg2.query(x, y, x);
        last = ans.x;
        cout << last << '\n';
    }
}