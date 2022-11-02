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

struct Vert {
    Vi edges;
    Zp f{0}, g{0}, h{0}; // total, extended, containing
};

vector<Vert> G;

void compute(int v) {
    if (G[v].edges.empty()) {
        G[v].f = G[v].h = 1;
        return;
    }

    G[v].f = G[v].h = 1;
    each(e, G[v].edges) G[v].f *= G[e].f;

    each(e, G[v].edges) {
        G[v].g += G[v].f * (G[e].g + G[e].h) / G[e].f;
        G[v].h *= G[e].f + G[e].g + G[e].h;
    }

    G[v].h -= G[v].f + G[v].g;
    G[v].f += G[v].h;
}

void run() {
    int n; cin >> n;
    G.resize(n);

    rep(i, 1, n) {
        int k; cin >> k;
        G[k-1].edges.pb(i);
    }

    for (int i = n-1; i >= 0; i--) {
        compute(i);
    }

    cout << G[0].f.x << endl;
}