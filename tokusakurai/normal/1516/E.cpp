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

int main(){
    int N, K; cin >> N >> K;

    vector<vector<mint>> P(2*K+1, vector<mint>(2*K+1, 1));
    rep(i, 2*K+1){
        rep(j, 2*K){
            P[i][j+1] = P[i][j]*mint(N-i-j);
        }
    }

    vector<mint> fac(K+2, 1), ifac(K+2, 1);
    rep(i, K+1){
        fac[i+1] = fac[i]*mint(i+1);
        ifac[i+1] = ifac[i]/mint(i+1);
    }

    vector<vector<vector<mint>>> dp(K+1, vector<vector<mint>>(K+1, vector<mint>(K+1, 0)));
    dp[0][0][0] = 1;

    rep(i, K){
        rep(j, K+1){
            rep(k, K+1){
                if(dp[i][j][k] == 0) continue;

                mint pw = 1;

                rep(l, K+1){
                    int ni = i+1, nj = j+(i+1)*l, nk = k+l;
                    if(nj > K || nk > K || j+k+(i+2)*l > 2*K) break;
                    
                    dp[ni][nj][nk] += dp[i][j][k] * P[j+k][(i+2)*l] * ifac[l] * pw;

                    pw *= fac[i+1]*ifac[i+2];
                }
            }
        }
    }

    vector<mint> S(K+1, 0);

    rep(j, K+1){
        rep(k, K+1){
            S[j] += dp[K][j][k];
        }
    }

    rep2(i, 2, K) S[i] += S[i-2];

    rep2(i, 1, K) cout << S[i] << (i == K? '\n' : ' ');
}