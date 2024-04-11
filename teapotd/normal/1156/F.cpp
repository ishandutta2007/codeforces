#define _USE_MATH_DEFINES
#include<bits/stdc++.h>//////////////////////////////////////////
#define deb(...)/////////////////////////////////////////////////
#define DBP(...)/////////////////////////////////////////////////
#ifdef LOC///////////////////////////////////////////////////////
#include"debuglib.h"/////////////////////////////////////////////
#endif///////////////////////////////////////////////////////////
#define x first//////////////////////////////////////////////////
#define y second/////////////////////////////////////////////////
#define pb push_back/////////////////////////////////////////////
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
    #define OP(c) Zp& operator c##=(Zp r){ return *this=*this c r; }
    OP(+)OP(-)OP(*)OP(/)
    void print() { cerr << x; }
};

int n;
Vi elems, cnt;
Zp f[5001][5001];
Zp fact[5001];

void run() {
    cin >> n;
    elems.resize(n);
    cnt.resize(n+1);

    each(e, elems) {
        cin >> e;
        cnt[e]++;
    }

    fact[0] = 1;
    rep(i, 1, n+1) fact[i] = fact[i-1]*i;

    rep(k, 0, n+1) f[0][k] = 1;

    rep(i, 1, n+1) {
        rep(k, 1, n+1) {
            f[i][k] = f[i-1][k-1]*cnt[k] + f[i][k-1];
        }
    }

    Zp ans = 0;

    rep(k, 1, n+1) {
        rep(i, 0, n-1) {
            ans += f[i][k-1] * cnt[k] * (cnt[k]-1) * fact[n-i-2];
        }
    }

    cout << (ans/fact[n]).x << endl;
}