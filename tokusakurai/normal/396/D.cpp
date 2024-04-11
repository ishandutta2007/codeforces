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

    Mod_Int(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

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

    Mod_Int inverse() const{
        assert(*this != Mod_Int(0));
        return pow(mod-2);
    }

    Mod_Int pow(long long k) const{
        Mod_Int now = *this, ret = 1;
        for(; k > 0; k >>= 1, now *= now){
            if(k&1) ret *= now;
        }
        return ret;
    }

    friend ostream &operator << (ostream &os, const Mod_Int &p){
        return os << p.x;
    }

    friend istream &operator >> (istream &is, Mod_Int &p){
        long long a;
        is >> a;
        p = Mod_Int<mod>(a);
        return is;
    }
};

using mint = Mod_Int<MOD>;

template<typename T>
struct Binary_Indexed_Tree{
    vector<T> bit;
    const int n;
    
    Binary_Indexed_Tree(const vector<T> &v) : n((int)v.size()){
        bit.resize(n+1);
        copy(begin(v), end(v), begin(bit)+1);
        for(int a = 2; a <= n; a <<= 1){
            for(int b = a; b <= n; b += a){
                bit[b] += bit[b-a/2];
            }
        }
    }
    
    void add(int i, const T &x){
        for(i++; i <= n; i += (i & -i)) bit[i] += x;
    }

    void change(int i, const T&x){
        add(i, x-query(i, i+1));
    }
    
    T sum(int i) const{
        T ret = 0;
        for(; i > 0; i -= (i & -i)) ret += bit[i];
        return ret;
    }
    
    T query(int l, int r) const{
        return sum(r) - sum(l);
    }

    T operator [] (int i) const {return query(i, i+1);}

    int lower_bound(T x) const{
        int ret = 0;
        for(int k = 31-__builtin_clz(n); k >= 0; k--){
            if(ret+(1<<k) <= n && bit[ret+(1<<k)] < x) x -= bit[ret += (1<<k)]; 
        }
        return ret;
    }

    int upper_bound(T x) const {return lower_bound(x+1);}
};

int main(){
    int N; cin >> N;

    vector<int> p(N);
    rep(i, N){
        cin >> p[i]; p[i]--;
    }

    Binary_Indexed_Tree<int> b1(vector<int>(N, 0)), b2(vector<int>(N, 1));

    vector<mint> c(N);
    rep3(i, N-1, 0){
        c[i] = b1.query(0, p[i]);
        b1.add(p[i], 1);
    }

    vector<mint> fac(N+1, 1);
    rep(i, N) fac[i+1] = fac[i]*(i+1);

    mint ans = 0;
    mint tmp = 0;
    mint tw = mint(2).inverse();

    rep(i, N){
        mint k = b2.query(0, p[i]); //K
        mint n = N-1-i;

        ans += k*(n*(n-1)*tw*fac[n.x]*tw);
        ans += tmp*k*fac[n.x];
        ans += k*(k-1)*fac[n.x]*tw;

        tmp += c[i];
        b2.add(p[i], -1);

        //cout << k << ' ' << ans << '\n';
    }

    cout << ans+tmp << '\n';
}