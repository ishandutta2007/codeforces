#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
//const ll MOD = 1000000007;
const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const double pi = acos(-1.0);
const double EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

template<ll mod>
struct Mod_Int{
    ll x;
    Mod_Int() {}
    Mod_Int(ll y) : x (y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    Mod_Int &operator += (const Mod_Int &p){
        x = (x + p.x) % mod;
        return *this;
    }

    Mod_Int &operator -= (const Mod_Int &p){
        x = (x + mod - p.x) % mod;
        return *this;
    }

    Mod_Int &operator *= (const Mod_Int &p){
        x = (x * p.x) % mod;
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
        while(k){
            if(k&1) ret *= now;
            now *= now, k >>= 1;
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

template<typename T>
struct combination{
    vector<T> _fac, _ifac;

    combination(int n){
        _fac.resize(n+1), _ifac.resize(n+1);
        _fac[0] = 1;
        rep2(i, 1, n) _fac[i] = _fac[i-1]*i;
        _ifac[n] = _fac[n].inverse();
        rep3(i, n, 1) _ifac[i-1] = _ifac[i]*i;
    }

    T fac(int k) const {return _fac[k];}

    T ifac(int k) const {return _ifac[k];}

    T comb(int n, int k) const{
        if(k < 0 || n < k) return 0;
        return fac(n) * ifac(n-k) * ifac(k);
    }

    T perm(int n, int k) const{
        if(k < 0 || n < k) return 0;
        return fac(n) * ifac(n-k);
    }
};

template<typename Monoid>
struct Lazy_Segment_Tree{
    Monoid f(Monoid a, Monoid b){
        return a+b;
    }
    const Monoid unit;
    int n;
    vector<Monoid> seg, lazy;
    
    Lazy_Segment_Tree(int N, const Monoid &x) : unit(x){
        n = 1;
        while(n < N) n <<= 1;
        seg.assign(2*n, unit);
        lazy.assign(2*n, unit);
    }
    
    void eval(int i, int l, int r){
        if(lazy[i] != unit){
            seg[i] = f(seg[i], lazy[i]);
            if(r-l > 1){
                lazy[2*i] = f(lazy[2*i] ,lazy[i]/2);
                lazy[2*i+1] = f(lazy[2*i+1], lazy[i]/2);
            }
            lazy[i] = unit;
        }
    }
    
    void add(int a, int b, const Monoid &x, int i = 1, int l = 0, int r = -1){
        if(r < 0) r = n;
        eval(i, l, r);
        if(a >= r || b <= l) return;
        if(a <= l && r <= b){
            lazy[i] = f(lazy[i], (r-l)*x);
            eval(i, l, r);
        }
        else{
            add(a, b, x, 2*i, l, (l+r)/2);
            add(a, b, x, 2*i+1, (l+r)/2, r);
            seg[i] = f(seg[2*i], seg[2*i+1]);
        }
    }
    
    Monoid query(int a, int b, int i = 1, int l = 0, int r = -1){
        if(r < 0) r = n;
        if(a >= r || b <= l) return unit;
        eval(i, l, r);
        if(a <= l && r <= b) return seg[i];
        Monoid vl = query(a, b, 2*i, l, (l+r)/2);
        Monoid vr = query(a, b, 2*i+1, (l+r)/2, r);
        return f(vl, vr);
    }
    
    void update(int i = 1, int l = 0, int r = -1){
        if(r < 0) r = n;
        seg[i] = f(seg[i], lazy[i]);
        if(r-l > 1){
            lazy[2*i] = f(lazy[2*i], lazy[i]/2);
            lazy[2*i+1] = f(lazy[2*i+1], lazy[i]/2);
            update(2*i, l, (l+r)/2);
            update(2*i+1, (l+r)/2, r);
        }
        lazy[i] = unit;
    }
    
    Monoid operator [] (int i) const {return seg[n+i];}
    
    void clear(){
        fill(seg.begin(), seg.end(), unit);
        fill(lazy.begin(), lazy.end(), unit);
    }
};

int main(){
    int N, M;
    cin >> N >> M;
    int l[N], r[N];
    Lazy_Segment_Tree<ll> seg(N+1, 0);
    rep(i, N){
        cin >> l[i] >> r[i];
        seg.add(l[i], r[i]+1, 1);
    }
    seg.update();
    int a[M], b[M];
    rep(i, M){
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
    }
    combination<mint> C(1000000);
    mint ans = 0;
    mint sum[2*M+1][N+1];
    rep(i, 2*M+1){
        sum[i][0] = 0;
        rep2(j, 1, N){
            sum[i][j] = sum[i][j-1];
            if(j >= i) sum[i][j] += C.comb(seg[j]-i, j-i);
        }
    }
    rep(i, 1<<M){
        int L = 1, R = N;
        set<int> used;
        rep(j, M){
            if(!(i&(1<<j))) continue;
            chmax(L, l[a[j]]), chmin(R, r[a[j]]);
            chmax(L, l[b[j]]), chmin(R, r[b[j]]);
            used.insert(a[j]), used.insert(b[j]);
        }
        if(R < L) continue;
        int n = sz(used);
        mint tmp = sum[n][R]-sum[n][L-1];
        if(__builtin_parity(i)) ans -= tmp;
        else ans += tmp;
    }
    cout << ans << endl;
}