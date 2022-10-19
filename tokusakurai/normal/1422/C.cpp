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
const int MOD = 1000000007;
//const int MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const double pi = acos(-1.0);
const double EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

template<int mod>
struct Mod_Int{
    ll x;

    Mod_Int() : x(0) {}

    Mod_Int(ll y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

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

    T second_stirling_number(ll n, int k){ //nk
        T ret = 0;
        rep(i, k+1){
            T tmp = comb(k, i)*T(k-i).pow(n);
            ret += ((i&1)? -tmp : tmp);
        }
        return ret*ifac(k);
    }
};

int main(){
    string S;
    cin >> S;
    int N = sz(S);
    combination<mint> c(N);
    mint dp[N+1], pw[N+1], pw2[N+1];
    mint ans = 0;
    dp[0] = 0, pw[0] = 1, pw2[0] = 0;
    mint t = mint(10).inverse(), now = 1;
    rep(i, N){
        mint x = S[N-i-1]-'0';
        ans += x*pw[i]*(dp[i]+c.comb(N-i, 2));
        now *= t;
        pw2[i+1] = pw2[i]+now;
        dp[i+1] = dp[i]+pw2[i+1];
        pw[i+1] = pw[i]*10;
    }
    cout << ans << endl;
}