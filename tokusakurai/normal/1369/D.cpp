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
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

template<ll mod> struct Mod_Int{
    ll x;
    Mod_Int() {}
    Mod_Int(ll y) : x (y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    Mod_Int &operator += (const Mod_Int &p) {
        x = (x + p.x) % mod;
        return *this;
    }

    Mod_Int &operator -= (const Mod_Int &p) {
        x = (x + mod - p.x) % mod;
        return *this;
    }

    Mod_Int &operator *= (const Mod_Int &p) {
        x = (x * p.x) % mod;
        return *this;
    }

    Mod_Int &operator /= (const Mod_Int &p) {
        *this *= p.inverse();
        return *this;
    }

    Mod_Int &operator ++ () {return *this += Mod_Int(1);}

    Mod_Int operator ++ (int) {
        Mod_Int tmp = *this;
        ++*this;
        return tmp;
    }

    Mod_Int &operator -- () {return *this -= Mod_Int(1);}

    Mod_Int operator -- (int) {
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

    Mod_Int pow (ll n) const {
        Mod_Int now = *this, ret = 1;
        while(n > 0){
            if(n & 1) ret *= now;
            now *= now, n >>= 1;
        }
        return ret;
    }

    Mod_Int inverse () const {
        return pow(mod-2);
    }
};

using mint = Mod_Int<MOD>;
const int MAX_N = 1e6;
mint fac[MAX_N+1], ifac[MAX_N+1];

void init(){
    fac[0] = 1;
    rep2(i, 1, MAX_N){
        fac[i] = fac[i-1]*i;
    }
    ifac[MAX_N] = fac[MAX_N].inverse();
    rep3(i, MAX_N, 1){
        ifac[i-1] = ifac[i]*i;
    }
}

mint comb(int n, int k){
    return fac[n]*ifac[n-k]*ifac[k];
}

mint perm(int n, int k){
    return fac[n]*ifac[n-k];
}

int main(){
    int MAX = 1<<21;
    mint dp[MAX+1][2];
    fill(dp[0], dp[MAX+1], 0);
    rep2(i, 2, MAX){
        dp[i][0] = dp[i-2][1]*2+dp[i-1][1]+1;
        if(i%3 == 0) dp[i][1] = dp[i][0];
        elif(i%3 == 1) dp[i][1] = dp[i][0]+1;
        else dp[i][1] = dp[i][0]-1;
    }
    int T;
    cin >> T;
    rep(t, T){
        int N;
        cin >> N;
        N--;
        if(N%3 == 2) cout << (dp[N][0]*4).x << endl;
        else cout << (dp[N][1]*4).x << endl;
    }
}