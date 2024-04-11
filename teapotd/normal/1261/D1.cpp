#define _USE_MATH_DEFINES////////////////////////////////////////
#include<bits/stdc++.h>//////////////////////////////////////////
#define deb(...)/////////////////////////////////////////////////
#define DBP(...)/////////////////////////////////////////////////
#ifdef LOC///////////////////////////////////////////////////////
#include"debuglib.h"/////////////////////////////////////////////
#endif///////////////////////////////////////////////////////////
#define x first//////////////////////////////////////////////////
#define y second/////////////////////////////////////////////////
#define pb push_back/////////////////////////////////////////////
#define mp make_pair/////////////////////////////////////////////
#define sz(x)int((x).size())/////////////////////////////////////
#define each(a,x)for(auto&a:(x))/////////////////////////////////
#define all(x)(x).begin(),(x).end()//////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)///////////////////////
using namespace std;using ll=long long;using Pii=pair<int,int>;//
using Vi=vector<int>;void run();int main(){cin.sync_with_stdio///
(0);cin.tie(0);cout<<fixed<<setprecision(18);run();return 0;}////
//-------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }

constexpr int MOD = 998244353;

ll modPow(ll a, ll e, ll m) { // a^e mod m
    ll t = 1 % m;
    while (e) {
        if (e % 2) t = t*a % m;
        e /= 2; a = a*a % m;
    }
    return t;
}

struct Zp {
    ll x; // Contained value, in range [0;MOD-1]
    Zp() : x(0) {}
    Zp(ll a) : x(a%MOD) { if (x < 0) x += MOD; }
    #define OP(c,d) Zp& operator c##=(Zp r) { \
            x = x d; return *this; } \
        Zp operator c(Zp r) const { \
            Zp t = *this; return t c##= r; }
    OP(+, +r.x - MOD*(x+r.x >= MOD));
    OP(-, -r.x + MOD*(x-r.x < 0));
    OP(*, *r.x % MOD);
    OP(/, *r.inv().x % MOD);
    Zp inv() const { return pow(MOD-2); }
    Zp pow(ll e) const{ return modPow(x,e,MOD); }
    void print() { cerr << x; } // For deb()
};

Zp buf[2005][4020];

Zp& dp(int n, int k) {
    return buf[n][k+2010];
}

void run() {
    int n, k; cin >> n >> k;
    Vi elems(n);
    each(e, elems) cin >> e;

    if (n == 1) {
        cout << 0 << '\n';
        return;
    }

    if (elems[0] == elems[1]) {
        dp(1, 0) = k;
    } else {
        dp(1, -1) = 1;
        dp(1, 1) = 1;
        dp(1, 0) = k-2;
    }

    rep(pref, 2, n+1) {
        rep(d, -n, n+1) {
            if (elems[pref-1] == elems[pref%n]) {
                dp(pref, d) += dp(pref-1, d)*k;
            } else {
                dp(pref, d-1) += dp(pref-1, d);
                dp(pref, d) += dp(pref-1, d)*(k-2);
                dp(pref, d+1) += dp(pref-1, d);
            }
        }
    }

    Zp ans = 0;
    rep(d, 1, n+1) {
        ans += dp(n, d);
    }
    cout << ans.x << '\n';
}