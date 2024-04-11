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

    Mod_Int inverse() const {
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
    int N; cin >> N;

    vector<int> c(26);
    rep(i, 26) cin >> c[i];

    int n = N/2, m = N-n;
    mint ans = mint(25).pow(N-2)*mint(26).pow(2);
    rep(i, 26){
        vector<mint> dp1(N+1, 0), dp2(N+1, 0);
        dp1[0] = 1;
        rep(j, N){
            vector<mint> tmp1(N+1, 0), tmp2(N+1, 0);
            rep(k, N){
                tmp2[k+1] += dp1[k];
                tmp1[k] += dp1[k]*24+dp2[k]*25;
                if(j == 0) tmp1[k] += dp1[k];
                if(j == n){
                    tmp1[k] += dp1[k];
                    tmp2[k+1] += dp2[k];
                }
            }
            swap(dp1, tmp1), swap(dp2, tmp2);
        }
        rep2(j, c[i]+1, N) ans -= dp1[j]+dp2[j];
    }

    vector<vector<mint>> dp1(N+1, vector<mint>(N+1, 0)), dp2(N+1, vector<mint>(N+1, 0)), dp3(N+1, vector<mint>(N+1, 0));
    dp1[0][0] = 1;
    rep(i, N){
        vector<vector<mint>> tmp1(N+1, vector<mint>(N+1, 0)), tmp2(N+1, vector<mint>(N+1, 0)), tmp3(N+1, vector<mint>(N+1, 0));
        rep(j, N) rep(k, N){
            tmp2[j+1][k] += dp1[j][k]+dp3[j][k];
            tmp3[j][k+1] += dp2[j][k]+dp1[j][k];
            tmp1[j][k] += dp1[j][k]*23+dp2[j][k]*24+dp3[j][k]*24;
            if(i == 0) tmp1[j][k] += dp1[j][k];
            if(i == n){
                tmp1[j][k] += dp1[j][k];
                tmp2[j+1][k] += dp2[j][k];
                tmp3[j][k+1] += dp3[j][k];
            }
        }
        swap(dp1, tmp1), swap(dp2, tmp2), swap(dp3, tmp3);
    }

    rep(i, 26) rep(j, i){
        rep2(k, c[i]+1, N){
            rep2(l, c[j]+1, N){
                ans += dp1[k][l]+dp2[k][l]+dp3[k][l];
            }
        }
    }

    cout << ans << '\n';
}