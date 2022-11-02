#define _USE_MATH_DEFINES/////////////////////////////////////////////////////
#include <bits/stdc++.h>//////////////////////////////////////////////////////
#ifdef LOC////////////////////////////////////////////////////////////////////
#include "debuglib.h"/////////////////////////////////////////////////////////
#else/////////////////////////////////////////////////////////////////////////
#define deb(...)//////////////////////////////////////////////////////////////
#define DBP(...)//////////////////////////////////////////////////////////////
#endif////////////////////////////////////////////////////////////////////////
#define x first///////////////////////////////////////////////////////////////
#define y second//////////////////////////////////////////////////////////////
#define mp make_pair//////////////////////////////////////////////////////////
#define pb push_back//////////////////////////////////////////////////////////
#define sz(x)int((x).size())//////////////////////////////////////////////////
#define each(a,x)for(auto&a:(x))///////////////// by teapotd /////////////////
#define all(x)(x).begin(),(x).end()///////////////////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)////////////////////////////////////
using namespace std;using namespace rel_ops;using ll=int64_t;using Pii=pair///
<int,int>;using ull=uint64_t;using Vi=vector<int>;void run();int main(){cin.//
sync_with_stdio(0);cin.tie(0);cout<<fixed<<setprecision(10);run();return 0;}//
//--------------------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }
int cmp(double a, double b, double eps=1e-9) { return (a>b+eps) - (a+eps<b); }

constexpr ll MOD = 1e9+7;

struct Zp {
    ll x;
    Zp(ll a = 0) {
        if (a < 0) a = a%MOD + MOD;
        else if (a >= MOD*2) a %= MOD;
        else if (a >= MOD) a -= MOD;
        x = a;
    }

    Zp operator+(Zp r) const{ return x+r.x; }
    Zp operator-(Zp r) const{ return x-r.x+MOD; }
    Zp operator*(Zp r) const{ return x*r.x; }
    Zp operator/(Zp r) const{return x*r.inv().x;}
    Zp operator-()     const{ return MOD-x; }
    Zp inv() const { return pow(MOD-2); }

    Zp pow(ll e) const {
        Zp t = 1, m = *this;
        while (e) {
            if (e & 1) t = t*m;
            e >>= 1; m = m*m;
        }
        return t;
    }

    #define OP(c) Zp& operator c##=(Zp r){ \
        return *this=*this c r; }
    OP(+)OP(-)OP(*)OP(/)
    void print() { cerr << x; }
};

// ---

vector<Zp> fact;

Zp newton(int n, int k) {
    if (k > n) return 0;
    return fact[n] / (fact[k] * fact[n-k]);
}

void initNewton(int n) {
    fact.resize(n+1);
    fact[0] = 1;
    rep(i, 1, n+1) fact[i] = fact[i-1] * i;
}

void run() {
    int n, m = 0; cin >> n;
    Vi elems(n);

    each(e, elems) {
        cin >> e;
        m = max(m, e);
    }

    Vi divs(m+1);
    vector<Zp> dp(m+1);
    initNewton(n);

    each(e, elems) divs[e] = 1;

    rep(i, 1, m+1) for (int j = i*2; j <= m; j += i) {
        divs[i] += divs[j];
    }

    rep(i, 1, 15) {
        for (int j = m; j > 0; j--) {
            dp[j] = newton(divs[j], i);
            for (int k = j*2; k <= m; k += j) {
                dp[j] -= dp[k];
            }
        }

        if (dp[1].x != 0) {
            cout << i << endl;
            return;
        }
    }

    cout << -1 << endl;
}