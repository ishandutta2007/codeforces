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
    int N, K; string S; cin >> N >> K >> S;

    vector<vector<mint>> dp(N+1, vector<mint>(K+1, 0));
    vector<mint> s(K+1, 0);
    dp[0][0] = 1;

    rep(i, N){
        rep(j, K+1){
            if(dp[i][j] == 0) continue;

            s[j] += dp[i][j];

            int L = i, R = N-1, M = (L+R)/2;

            rep2(ni, L, M-1){
                int nj = j+(ni-L+1)*(N-ni);
                if(nj <= K) dp[ni+1][nj] += dp[i][j]*('z'-S[ni]);
                else break;
            }
            rep3(ni, R, M){
                int nj = j+(ni-L+1)*(N-ni);
                if(nj <= K) dp[ni+1][nj] += dp[i][j]*('z'-S[ni]);
                else break;
            }
        }

        rep(j, K+1) dp[i+1][j] += s[j]*(S[i]-'a');
    }

    cout << s[K]+dp[N][K] << '\n';
}