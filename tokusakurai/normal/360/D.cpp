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

struct Random_Number_Generator{
    mt19937_64 mt;

    Random_Number_Generator() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}

    int64_t operator () (int64_t l, int64_t r){ //[l,r)
        uniform_int_distribution<int64_t> dist(l, r-1);
        return dist(mt);
    }

    int64_t operator () (int64_t r){  //[0,r)
        return (*this)(0, r);
    }
};

template<typename T>
vector<T> divisors(const T &n){
    vector<T> ret;
    for(T i = 1; i*i <= n; i++){
        if(n%i == 0){
            ret.push_back(i);
            if(i*i != n) ret.push_back(n/i);
        }
    }
    sort(begin(ret), end(ret));
    return ret;
}

template<typename T>
vector<pair<T, int>> prime_factor(T n){
    vector<pair<T, int>> ret;
    for(T i = 2; i*i <= n; i++){
        int cnt = 0;
        while(n%i == 0) cnt++, n /= i;
        if(cnt > 0) ret.emplace_back(i, cnt);
    }
    if(n > 1) ret.emplace_back(n, 1);
    return ret;
}

template<typename T>
bool is_prime(const T &n){
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
    iota(begin(ret), end(ret), 0);
    if(n >= 0) ret[0] = -1;
    if(n >= 1) ret[1] = -1;
    for(int i = 2; i*i <= n; i++){
        if(ret[i] < i) continue;
        for(int j = i+i; j <= n; j += i) ret[j] = min(ret[j], i);
    }
    return ret;
}

long long modpow(long long x, long long n, const int &m){
    long long ret = 1;
    for(; n > 0; n >>= 1, x *= x, x %= m){
        if(n&1) ret *= x, ret %= m;
    }
    return ret;
}

template<typename T>
T Euler_Totient(T m){ //(xmx^(m)1(mod m))
    T ret = m;
    for(T i = 2; i*i <= m; i++){
        if(m%i == 0) ret /= i, ret *= i-1;
        while(m%i == 0) m /= i;
    }
    if(m > 1) ret /= m, ret *= m-1;
    return ret;
}

int modlog(const int &x, long long y, const int &m){ //x^k=y(mod m)k(xm)
    unordered_map<int, int> mp;
    int n = 0; long long now = 1;
    for(; n*n < m; n++){
        if(!mp.count(now)) mp[now] = n;
        now *= x, now %= m;
    }
    now = modpow(now, Euler_Totient(m)-1, m);
    for(int i = 0; i < n; i++){
        if(mp.count(y)) return n*i+mp[y];
        y *= now, y %= m;
    }
    return -1;
}

template<typename T>
T order(T x, const T &m){ //x^k=1(mod m)k(xm)
    T n = Euler_Totient(m);
    vector<T> ds;
    for(T i = 1; i*i <= n; i++){
        if(n%i == 0) ds.push_back(i), ds.push_back(n/i);
    }
    sort(begin(ds), end(ds));
    for(auto &e: ds){
        if(modpow(x, e, m) == 1) return e;
    }
    return -1;
}

template<typename T>
T primitive_root(const T &m){ //m
    vector<T> ds;
    for(T i = 1; i*i <= m-1; i++){
        if((m-1)%i == 0) ds.push_back(i), ds.push_back((m-1)/i);
    }
    sort(begin(ds), end(ds));
    Random_Number_Generator rnd;
    while(true){
        T r = rnd(1, m);
        for(auto &e: ds){
            if(e == m-1) return r;
            if(modpow(r, e, m) == 1) break;
        }
    }
}

vector<ll> ps;

//0 <= i < Ngcd(i,N) = 1i
ll coprime(ll N){
    int n = sz(ps);
    ll ret = 0;
    rep(i, 1<<n){
        ll mul = 1;
        rep(j, n){
            if((i>>j)&1) mul *= ps[j];
        }
        if(N%mul != 0) continue;
        ret += (__builtin_parity(i)? -(N/mul) : N/mul);
    }
    return ret;
}

int main(){
    int N, M; ll P; cin >> N >> M >> P;

    vector<ll> a(N);
    rep(i, N) cin >> a[i];

    vector<ll> b(M);
    rep(i, M) {cin >> b[i]; b[i] = gcd(b[i], P-1);}

    vector<ll> ds;
    for(ll i = 1; i*i <= P-1; i++){
        if((P-1)%i == 0){
            ds.push_back(i);
            if(i*i != P-1) ds.push_back((P-1)/i);
        }
    }
    sort(all(ds));

    each(e, prime_factor(P-1)) ps.eb(e.first);

    ll G = 0;
    rep(i, M) G = gcd(G, b[i]);

    vector<ll> c(N);

    rep(i, N){
        each(e, ds){
            if(modpow(a[i], e, P) == 1) {c[i] = (P-1)/e; break;}
        }
        c[i] = gcd(c[i]*G, P-1);
    }

    sort(all(c));
    c.erase(unique(all(c)), end(c));

    ll ans = 0;

    each(e, ds){
        each(u, c){
            if(e%u == 0){
                ans += coprime((P-1)/e);
                //cout << e << ' ' << coprime((P-1)/e) << '\n';
                break;
            }
        }
    }

    cout << ans << '\n';
}