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
    int H, W; cin >> H >> W;

    vector<string> S(H);
    rep(i, H) cin >> S[i];

    vector<int> yoko, tate;

    rep(i, H){
        int ptr = 0;
        
        while(ptr < W){
            if(S[i][ptr] == '*') {ptr++; continue;}

            int j = 0;
            while(ptr+j < W && S[i][ptr+j] == 'o') j++;

            yoko.eb(j), ptr += j;
        }
    }
    rep(j, W){
        int ptr = 0;

        while(ptr < H){
            if(S[ptr][j] == '*') {ptr++; continue;}

            int i = 0;
            while(ptr+i < H && S[ptr+i][j] == 'o') i++;

            tate.eb(i), ptr += i;
        }
    }

    int N = 300000;

    vector<vector<mint>> dp1(N+1, vector<mint>(2, 0)), dp2(N+1, vector<mint>(2, 0));
    dp2[0][0] = 1;

    rep(i, N){
        dp1[i+1][0] += dp1[i][0]+dp1[i][1];
        dp2[i+1][0] += dp2[i][0]+dp2[i][1];

        dp1[i+1][1] += dp1[i][0];
        dp2[i+1][1] += dp2[i][0];

        dp1[i+1][0] += dp1[i][1]+dp2[i][1];
        dp2[i+1][0] += dp2[i][1];
    }

    int s = accumulate(all(yoko), 0);

    vector<mint> pw(N+1, 1);
    rep(i, N) pw[i+1] = pw[i]*2;

    mint x = 0, y = 0;

    //each(e, yoko) cout << e << ' '; cout << '\n';
    //each(e, tate) cout << e << ' '; cout << '\n';

    each(e, yoko) x += (dp1[e][0]+dp1[e][1])*pw[s-e];
    each(e, tate) y += (dp1[e][0]+dp1[e][1])*pw[s-e];

    cout << x+y << '\n';
}