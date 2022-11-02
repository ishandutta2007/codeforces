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

constexpr int MOD = 1e9+7;

ll modPow(ll a, ll e, ll m) {
    ll t = 1 % m;
    while (e) {
        if (e % 2) t = t*a % m;
        e /= 2; a = a*a % m;
    }
    return t;
}

struct Zp {
    ll x;
    Zp() {}
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

vector<Vi> G;
vector<ll> beauty;
Zp ans = 0;

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void dfs(int v, int p, int d, const vector<pair<ll, int>>& g) {
    vector<pair<ll, int>> ng;

    each(e, g) {
        ll f = gcd(e.x, beauty[v]);
        if (ng.empty() || ng.back().x != f) {
            ng.pb({f, e.y});
        }
    }

    if (ng.empty() || ng.back().x != beauty[v]) {
        ng.pb({beauty[v], d});
    }

    rep(i, 0, sz(ng)) {
        int end = (i+1 < sz(ng) ? ng[i+1].y : d+1);
        ans += Zp(ng[i].x) * (end-ng[i].y);
    }

    each(e, G[v]) if (e != p) {
        dfs(e, v, d+1, ng);
    }
}

void run() {
    int n; cin >> n;
    G.resize(n);
    beauty.resize(n);
    each(b, beauty) cin >> b;

    rep(i, 1, n) {
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    vector<pair<ll, int>> g;
    dfs(0, -1, 0, g);
    cout << ans.x << endl;
}