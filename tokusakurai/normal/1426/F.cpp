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

int main(){
    int N;
    string S;
    cin >> N >> S;
    mint dp0[N+1], dp1[N+1], dp2[N+1], dp3[N+1];
    fill(dp0, dp0+N+1, 0), fill(dp1, dp1+N+1, 0), fill(dp2, dp2+N+1, 0), fill(dp3, dp3+N+1, 0);
    dp0[0] = 1;
    rep(i, N){
        if(S[i] == 'a' || S[i] == '?') dp0[i+1] += dp0[i], dp1[i+1] += dp1[i]+dp0[i], dp2[i+1] += dp2[i], dp3[i+1] += dp3[i];
        if(S[i] == 'b' || S[i] == '?') dp0[i+1] += dp0[i], dp1[i+1] += dp1[i], dp2[i+1] += dp2[i]+dp1[i], dp3[i+1] += dp3[i];
        if(S[i] == 'c' || S[i] == '?') dp0[i+1] += dp0[i], dp1[i+1] += dp1[i], dp2[i+1] += dp2[i], dp3[i+1] += dp3[i]+dp2[i];
    }
    cout << dp3[N] << endl;

}