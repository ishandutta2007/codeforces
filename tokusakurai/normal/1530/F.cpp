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
const int MOD = 31607;
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
        x = (int) (x * p.x % mod);
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
    int N; cin >> N;

    mint iv = mint(10000).inverse();
    vector<vector<mint>> P(N, vector<mint>(N)), Q(N, vector<mint>(N));

    rep(i, N){
        rep(j, N){
            cin >> P[i][j];
            P[i][j] *= iv;
            Q[i][j] = P[i][j].inverse();
        }
    }

    vector<mint> S(N, 1);
    rep(i, N){
        rep(j, N){
            S[i] *= P[i][j];
        }
    }

    vector<vector<mint>> memo(N, vector<mint>(1<<N, 1));
    rep(i, 1<<N){
        if(i == 0){
            rep(j, N){
                rep(k, N) memo[j][i] *= P[k][j];
            }
            continue;
        }
        int t = __builtin_ctz(i);
        rep(j, N){
            memo[j][i] = memo[j][i&~(1<<t)]*Q[t][j];
        }
    }

    vector<mint> R(N); //
    vector<mint> dp(N+1, 0);
    mint ans = 0;

    rep(i, 1<<N){
        mint A = 1;
        rep(j, N){
            if((i>>j)&1){
                A *= S[j];
            }
        }

        rep(j, 4){
            mint B = A;
            rep(k, N){
                R[k] = memo[k][i];
                if(j&1){
                    if(!((i>>k)&1)){
                        R[k] *= Q[k][k];
                        B *= P[k][k];
                    }
                }
                if(j&2){
                    if(!((i>>(N-1-k))&1)){
                        if(k != N-1-k || !(j&1)){
                            R[k] *= Q[N-1-k][k];
                            B *= P[N-1-k][k];
                        }
                    }
                }
            }

            fill(all(dp), 0);
            dp[0] = 1;
            rep(k, N){
                dp[k+1] += dp[k];
                dp[k+1] -= dp[k]*R[k];
            }

            if((__builtin_popcount(i)+__builtin_popcount(j))%2 == 1){
                ans -= dp[N]*B;
            }
            else{
                ans += dp[N]*B;
            }
        }
    }

    cout << mint(1)-ans << '\n';
}