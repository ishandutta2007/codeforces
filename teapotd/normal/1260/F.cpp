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

struct CentroidTree {
    vector<Vi> child, ind, dists, subtree, neigh, dir;
    Vi par, depth, size;
    int root;

    vector<Zp> cnt, sum;
    vector<vector<Zp>> sCnt, sSum;

    CentroidTree() {}

    CentroidTree(vector<Vi>& G)
            : child(sz(G)), ind(sz(G)), dists(sz(G)),
              subtree(sz(G)), neigh(sz(G)),
              dir(sz(G)), par(sz(G), -2),
              depth(sz(G)), size(sz(G)) {
        cnt.resize(sz(G));
        sum.resize(sz(G));
        sCnt.resize(sz(G));
        sSum.resize(sz(G));
        root = decomp(G, 0, 0);
    }

    int dfs(vector<Vi>& G, int v, int p) {
        size[v] = 1;
        each(e, G[v]) if (e != p && par[e] == -2)
            size[v] += dfs(G, e, v);
        return size[v];
    }

    void layer(vector<Vi>& G, int v, int p, int c, int d) {
        ind[v].pb(sz(subtree[c]));
        subtree[c].pb(v);
        dists[c].pb(d);
        dir[c].pb(sz(neigh[c])-1);
        each(e, G[v]) if (e != p && par[e] == -2) {
            if (v == c) {
                neigh[c].pb(e);
                sCnt[c].pb(0);
                sSum[c].pb(0);
            }
            layer(G, e, v, c, d+1);
        }
    }

    int decomp(vector<Vi>& G, int v, int d) {
        int p = -1, s = dfs(G, v, -1);
        bool ok = 1;
        while (ok) {
            ok = 0;
            each(e, G[v]) {
                if (e != p && par[e] == -2 && size[e] > s/2) {
                    p = v; v = e; ok = 1;
                    break;
                }
            }
        }

        par[v] = -1;
        size[v] = s;
        depth[v] = d;
        layer(G, v, -1, v, 0);

        each(e, G[v]) if (par[e] == -2) {
            int j = decomp(G, e, d+1);
            child[v].pb(j);
            par[j] = v;
        }
        return v;
    }

    void add(int v, Zp c) {
        cnt[v] += c;

        int p = v, d = depth[v];

        while (true) {
            p = par[p];
            d--;
            if (p == -1) break;

            int sub = dir[p][ind[v][d]];
            int dis = dists[p][ind[v][d]];

            sum[p] += c*dis;
            cnt[p] += c;
            sSum[p][sub] += c*dis;
            sCnt[p][sub] += c;
        }

        deb("a", v, c);
    }

    Zp query(int v) {
        Zp ret = sum[v];
        int p = v, d = depth[v];
        deb(ret);

        while (true) {
            p = par[p];
            d--;
            if (p == -1) break;

            int sub = dir[p][ind[v][d]];
            int dis = dists[p][ind[v][d]];

            Zp s = sum[p] - sSum[p][sub];
            Zp c = cnt[p] - sCnt[p][sub];
            ret += c*dis + s;

            deb(ret, c, s, p, v);
        }

        deb("q", v, ret);
        return ret;
    }
};

void run() {
    int n; cin >> n;
    vector<Pii> ranges(n);
    vector<Vi> G(n);

    each(r, ranges) {
        cin >> r.x >> r.y;
        r.x--;
    }

    rep(i, 1, n) {
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].pb(v);
        G[v].pb(u);
    }

    CentroidTree cen(G);
    vector<vector<Pii>> events(1e5+5);
    Zp total = 1;

#ifdef LOC
    events.resize(5);
#endif

    rep(i, 0, n) {
        auto& r = ranges[i];
        events[r.x].pb({i, 1});
        events[r.y].pb({i, -1});
        total *= r.y-r.x;
    }

    Zp ans = 0, cur = 0;

    each(vec, events) {
        each(e, vec) {
            auto& r = ranges[e.x];
            cur += cen.query(e.x) * e.y / (r.y-r.x);
            cen.add(e.x, total * e.y / (r.y-r.x));
            deb(cur);
        }
        ans += cur;
        deb(ans, cur);
    }

    cout << ans.x << '\n';
}