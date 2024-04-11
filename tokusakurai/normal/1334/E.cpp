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
//const int MOD = 1000000007;
const int MOD = 998244353;
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

template<int mod>
struct Combination{
    using T = Mod_Int<mod>;
    vector<T> _fac, _ifac;

    Combination(int n){
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
        return fac(n)*ifac(n-k)*ifac(k);
    }

    T perm(int n, int k) const{
        if(k < 0 || n < k) return 0;
        return fac(n)*ifac(n-k);
    }

    T second_stirling_number(int n, int k) const{
        T ret = 0;
        rep(i, k+1){
            T tmp = comb(k, i)*T(i).pow(n);
            ret += ((k-i)&1)? -tmp : tmp;
        }
        return ret*ifac(k);
    }

    T bell_number(int n, int k) const{
        if(n == 0) return 1;
        chmin(k, n);
        vector<T> pref(k+1);
        pref[0] = 1;
        rep2(i, 1, k){
            if(i&1) pref[i] = pref[i-1]-ifac(i);
            else pref[i] = pref[i-1]+ifac(i);   
        }
        T ret = 0;
        rep2(i, 1, k){
            ret += T(i).pow(n)*ifac(i)*pref[k-i];
        }
        return ret;
    }
};

using comb = Combination<MOD>;

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

vector<pli> ps;
map<ll, vector<pii>> mp;
vector<pii> tmp;

void dfs(int i, ll now){
    if(i == sz(ps)) {mp[now] = tmp; return;}
    dfs(i+1, now);
    tmp.eb(i, 0);
    rep(j, ps[i].second){
        now *= ps[i].first, tmp.back().second++;
        dfs(i+1, now);
    }
    rep(j, ps[i].second){
        now /= ps[i].first;
    }
    tmp.pop_back();
}

int main(){
    ll D;
    cin >> D;

    ps = prime_factor(D);
    dfs(0, 1);

    comb C(1000000);

    int Q;
    cin >> Q;
    while(Q--){
        ll u, v; cin >> u >> v;
        map<int, int> mp2;
        each(e, mp[u]) mp2[e.first] += e.second;
        each(e, mp[v]) mp2[e.first] -= e.second;

        vector<int> a, b;
        each(e, mp2){
            if(e.second > 0) a.eb(e.second);
            if(e.second < 0) b.eb(-e.second);
        }

        mint ans = 1;
        int sa = 0, sb = 0;
        each(e, a) ans *= C.ifac(e), sa += e;
        each(e, b) ans *= C.ifac(e), sb += e;
        ans *= C.fac(sa), ans *= C.fac(sb);

        cout << ans << '\n';
    }
}