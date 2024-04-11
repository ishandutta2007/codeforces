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

int main(){
    int N; ll M; cin >> N >> M;

    vector<ll> fac(N+1, 1);
    rep(i, N) fac[i+1] = fac[i]*(i+1)%M;

    vector<ll> ifac(N+1, 1);
    ifac[N] = modpow(fac[N], M-2, M);
    rep3(i, N-1, 0) ifac[i] = ifac[i+1]*(i+1)%M;

    vector<vector<ll>> comb(N+1, vector<ll>(N+1));
    rep(i, N+1){
        rep(j, N-i+1){
            comb[i][j] = ifac[i]*ifac[j]%M;
            comb[i][j] *= fac[i+j], comb[i][j] %= M;
        }
    }

    vector<vector<ll>> dp1(N+1, vector<ll>(N+1, 0)), dp2(N+1, vector<ll>(N+1, 0));
    dp1[1][0] = 1;

    rep2(i, 1, N-1){
        rep(j, i){
            rep(k, i+1){
                if(k <= j){
                    dp1[i+1][k] += dp1[i][j];
                    dp1[i+1][k] %= M;
                }
                else{
                    dp2[i+1][k] += dp1[i][j]+dp2[i][j];
                    dp2[i+1][k] %= M;
                }
            }
        }
    }

    vector<ll> s(N+1, 0);
    rep(i, N+1){
        rep(j, N+1){
            s[i] += dp1[i][j]+dp2[i][j];
            s[i] %= M;
        }
    }

    //rep(i, N+1) cout << s[i] << ' '; cout << '\n';

    vector<vector<ll>> dp3(N+1, vector<ll>(N+1, 0));
    dp3[1][1] = 1;

    rep2(i, 1, N-1){
        rep2(j, 1, i-1){
            rep2(k, 0, i-j){
                ll tmp = s[j]*dp3[i-j][k]%M;
                tmp *= comb[j][k], tmp %= M;
                dp3[i+1][j+k] += tmp;
                dp3[i+1][j+k] %= M;
            }
        }
        dp3[i+1][i+1] += s[i+1];
    }

    cout << accumulate(all(dp3[N]), 0LL)%M << '\n';
}