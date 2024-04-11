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

template<int mod>
struct Combination{
    using T = Mod_Int<mod>;
    vector<T> _fac, _ifac;

    Combination(int n){
        _fac.resize(n+1), _ifac.resize(n+1);
        _fac[0] = 1;
        for(int i = 1; i <= n; i++) _fac[i] = _fac[i-1]*i;
        _ifac[n] = _fac[n].inverse();
        for(int i = n; i >= 1; i--) _ifac[i-1] = _ifac[i]*i;
    }

    T fac(int k) const {return _fac[k];}

    T ifac(int k) const {return _ifac[k];}

    T comb(int n, int k) const{
        if(k < 0 || n < k) return 0;
        return fac(n)*ifac(n-k)*ifac(k);
    }

    T comb2(int x, int y) const {return comb(x+y, x);}

    T perm(int n, int k) const{
        if(k < 0 || n < k) return 0;
        return fac(n)*ifac(n-k);
    }

    T second_stirling_number(int n, int k) const{ //nk1
        T ret = 0;
        for(int i = 0; i <= k; i++){
            T tmp = comb(k, i)*T(i).pow(n);
            ret += ((k-i)&1)? -tmp : tmp;
        }
        return ret*ifac(k);
    }

    T bell_number(int n, int k) const{ //nk
        if(n == 0) return 1;
        k = min(k, n);
        vector<T> pref(k+1);
        pref[0] = 1;
        for(int i = 1; i <= k; i++){
            if(i&1) pref[i] = pref[i-1]-ifac(i);
            else pref[i] = pref[i-1]+ifac(i);   
        }
        T ret = 0;
        for(int i = 1; i <= k; i++){
            ret += T(i).pow(n)*ifac(i)*pref[k-i];
        }
        return ret;
    }
};

using comb = Combination<MOD>;

int main(){
    int K; cin >> K; K++;

    vector<vector<vector<mint>>> dp(31, vector<vector<mint>>(31, vector<mint>(2, 0)));
    comb C(30);

    dp[30][0][1] = 1;

    rep3(i, 29, 0){
        int t = (K>>i)&1;
        rep2(j, 0, 30){
            rep(k, 2){
                if(dp[i+1][j][k] == 0) continue;
                rep(l, 2){
                    if(t == 0 & k == 1 & l == 1) continue;
                    int ni = i, nj = j, nk = (k == 1 && t == l? 1 : 0);

                    if(l&1){
                        dp[ni][nj+1][nk] += dp[i+1][j][k];
                    }

                    rep2(m, 0, j){
                        if((m&1) != l) continue;
                        dp[ni][nj][nk] += dp[i+1][j][k]*C.comb(j, m);
                    }
                }
            }
        }
    }

    mint ans = 0;
    rep(j, 31){
        ans += dp[0][j][0];
    }

    cout << ans << '\n';
}