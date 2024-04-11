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

mint solve(vector<ll> a, ll K){
    int N = sz(a);
    if(N <= 1) return 0;

    vector<ll> S1(N+1, 0), S2(N+1, 0);
    rep3(i, N-1, 0) S1[i] = S1[i+1]+a[i];
    S2[N-1] = a[N-1];
    rep3(i, N-2, 0) S2[i] = S2[i+2]+a[i];
    /*
    rep(i, N) cout << a[i] << ' '; cout << '\n';
    rep(i, N) cout << S1[i] << ' '; cout << '\n';
    rep(i, N) cout << S2[i] << ' '; cout << '\n';
    */
    vector<ll> P1, P2;
    rep(i, N){
        if(i&1) P1.eb(S2[i]-S1[i]);
        else P2.eb(S2[i]-S1[i]);
    }

    mint ans = 0;

    rep2(i, 1, N-1){
        ll R = K-S2[i];
        if(i&1){
            int p = upper_bound(all(P1), -R)-begin(P1);
            ans += max(0, p-i/2);
        }
        else{
            int p = upper_bound(all(P2), -R)-begin(P2);
            ans += max(0, p-i/2);
        }
    }

    //cout << K << ' ' << ans << '\n';

    return ans;
}

int main(){
    int T; cin >> T;

    while(T--){
        int N; cin >> N;

        vector<ll> a(N);
        rep(i, N) cin >> a[i];
        ll S = accumulate(all(a), 0LL);
        S = S/2+1;

        if(N == 1) {cout << "1\n"; continue;}

        mint ans = 0;

        rep(i, 2) rep(j, 2){
            int L = i, R = N-j;
            ll K = S-a[0]*i;
            ans += solve(vector<ll>(begin(a)+L, begin(a)+R), K);
        }

        vector<ll> s(N+1, 0);
        rep(i, N) s[i+1] = s[i]+a[i];

        rep(i, N+1) if(s[i] >= S) ans++;

        cout << ans << '\n';
    }
}