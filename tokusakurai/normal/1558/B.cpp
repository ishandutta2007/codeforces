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

struct Runtime_Mod_Int{
    int x;

    Runtime_Mod_Int() : x(0) {}

    Runtime_Mod_Int(long long y){
        x = y % get_mod();
        if(x < 0) x += get_mod();
    }

    static inline int &get_mod(){
        static int mod = 0;
        return mod;
    }

    static void set_mod(int md){
        get_mod() = md;
    }

    Runtime_Mod_Int &operator += (const Runtime_Mod_Int &p){
        if((x += p.x) >= get_mod()) x -= get_mod();
        return *this;
    }

    Runtime_Mod_Int &operator -= (const Runtime_Mod_Int &p){
        if((x += get_mod() - p.x) >= get_mod()) x -= get_mod();
        return *this;
    }

    Runtime_Mod_Int &operator *= (const Runtime_Mod_Int &p){
        x = (int) (1LL * x * p.x % get_mod());
        return *this;
    }

    Runtime_Mod_Int &operator /= (const Runtime_Mod_Int &p){
        *this *= p.inverse();
        return *this;
    }

    Runtime_Mod_Int &operator ++ () {return *this += Runtime_Mod_Int(1);}

    Runtime_Mod_Int operator ++ (int){
        Runtime_Mod_Int tmp = *this;
        ++*this;
        return tmp;
    }

    Runtime_Mod_Int &operator -- () {return *this -= Runtime_Mod_Int(1);}

    Runtime_Mod_Int operator -- (int){
        Runtime_Mod_Int tmp = *this;
        --*this;
        return tmp;
    }

    Runtime_Mod_Int operator - () const {return Runtime_Mod_Int(-x);}

    Runtime_Mod_Int operator + (const Runtime_Mod_Int &p) const {return Runtime_Mod_Int(*this) += p;}

    Runtime_Mod_Int operator - (const Runtime_Mod_Int &p) const {return Runtime_Mod_Int(*this) -= p;}

    Runtime_Mod_Int operator * (const Runtime_Mod_Int &p) const {return Runtime_Mod_Int(*this) *= p;}

    Runtime_Mod_Int operator / (const Runtime_Mod_Int &p) const {return Runtime_Mod_Int(*this) /= p;}

    bool operator == (const Runtime_Mod_Int &p) const {return x == p.x;}

    bool operator != (const Runtime_Mod_Int &p) const {return x != p.x;}

    Runtime_Mod_Int inverse() const {
        assert(*this != Runtime_Mod_Int(0));
        return pow(get_mod()-2);
    }

    Runtime_Mod_Int pow(long long k) const{
        Runtime_Mod_Int now = *this, ret = 1;
        for(; k > 0; k >>= 1, now *= now){
            if(k&1) ret *= now;
        }
        return ret;
    }

    friend ostream &operator << (ostream &os, const Runtime_Mod_Int &p){
        return os << p.x;
    }

    friend istream &operator >> (istream &is, Runtime_Mod_Int &p){
        long long a;
        is >> a;
        p = Runtime_Mod_Int(a);
        return is;
    }
};

using mint = Runtime_Mod_Int;

int main(){
    int N, M; cin >> N >> M;

    mint::set_mod(M);

    vector<mint> dp(N+1, 0), S(N+2, 0);
    dp[N] = 1, S[N] = 1;

    rep3(i, N-1, 1){
        for(int j = 2; i*j <= N; j++){
            int L = i*j, R = (i+1)*j;
            chmin(R, N+1);
            dp[i] += S[L]-S[R];
        }
        dp[i] += S[i+1];
        S[i] = S[i+1]+dp[i];
    }

    //each(e, dp) cout << e << ' '; cout << '\n';
    //each(e, S) cout << e << ' '; cout << '\n';

    cout << dp[1] << '\n';
}