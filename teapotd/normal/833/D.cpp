#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#ifdef LOC
#include "debuglib.h"
#else
#define deb(...)
#define DBP(...)
#endif
using namespace std;
using   ll         = long long;
using   Vi         = vector<int>;
using   Pii        = pair<int, int>;
#define pb           push_back
#define mp           make_pair
#define x            first
#define y            second
#define rep(i, b, e) for (int i = (b); i < (e); i++)
#define each(a, x)   for (auto& a : (x))
#define all(x)       (x).begin(), (x).end()
#define sz(x)        int((x).size())

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }
void run();

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(18);
    run();
    return 0;
}

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
    Zp() : x(0) {}
    Zp(ll a) : x(a%MOD) { if (x < 0) x += MOD; }
    #define OP(c,d) Zp& operator c##=(Zp r) { x = x d; return *this; } Zp operator c(Zp r) const { Zp t = *this; return t c##= r; }
    OP(+, +r.x - MOD*(x+r.x >= MOD));
    OP(-, -r.x + MOD*(x-r.x < 0));
    OP(*, *r.x % MOD);
    OP(/, *r.inv().x % MOD);
    Zp inv() const { return pow(MOD-2); }
    Zp pow(ll e) const{ return modPow(x,e,MOD); }
    void print() { cerr << x; }
};

struct Edge {
    int dst, col;
    Zp val;
};

vector<vector<Edge>> G;
Vi par, siz;
Zp ans = 1;
vector<pair<int, Zp>> paths;

int kek(int v, int p) {
    siz[v] = 1;
    each(e, G[v]) if (e.dst != p) {
        siz[v] += kek(e.dst, v);
        ans *= e.val.pow(ll(siz[e.dst]) * ll(sz(G) - siz[e.dst]));
    }
    return siz[v];
}

int dfs(int v, int p) {
    siz[v] = 1;
    each(e, G[v]) if (e.dst != p && par[e.dst] == -2)
        siz[v] += dfs(e.dst, v);
    return siz[v];
}

void collect(int v, int p, Zp mul, int diff) {
    paths.pb({ diff, mul });
    each(e, G[v]) if (e.dst != p && par[e.dst] == -2) {
        collect(e.dst, v, mul*e.val, diff + (e.col ? 1 : -2));
    }
}

void process(int v, int pp, Zp mul, int diff, int sign) {
    paths.clear();
    collect(v, pp, mul, diff);

    sort(all(paths), [&](auto l, auto r) { return l.x < r.x; });

    int j = sz(paths)-1;
    Zp xd = 1;

    each(p, paths) {
        while (j >= 0 && paths[j].x+p.x > 0) {
            xd *= paths[j].y;
            j--;
        }
        if (sign == 1) {
            ans /= xd * p.y;
        } else {
            ans *= xd * p.y;
        }
    }
}

int decomp(int v, int d) {
    int p = -1, s = dfs(v, -1);
    bool ok = 1;
    while (ok) {
        ok = 0;
        each(e, G[v]) {
            if (e.dst != p && par[e.dst] == -2 && siz[e.dst] > s/2) {
                p = v; v = e.dst; ok = 1;
                break;
            }
        }
    }

    process(v, -1, 1, 0, 1);
    each(e, G[v]) if (par[e.dst] == -2) {
        process(e.dst, v, e.val, (e.col ? 1 : -2), -1);
    }

    par[v] = -1;

    each(e, G[v]) if (par[e.dst] == -2) {
        int j = decomp(e.dst, d+1);
        par[j] = v;
    }
    return v;
}

void solve() {
    par.assign(sz(G), -2);
    decomp(0, -1);
}

void run() {
    int n; cin >> n;
    G.resize(n);
    siz.resize(n);

    rep(i, 1, n) {
        int u, v, x, c; cin >> u >> v >> x >> c;
        u--; v--;
        G[u].pb({v, c, x});
        G[v].pb({u, c, x});
    }

    kek(0, -1);
    solve();
    each(v, G) each(e, v) e.col ^= 1;
    solve();

    cout << ans.x << '\n';
}