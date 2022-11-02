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

constexpr ll INF = 1e18;

struct Edge {
    int id, dst;
    ll w;
};

struct Vert {
    vector<Edge> E, next;
    ll dist{INF};
    int par{-1}, parE{-1};
};

vector<Vert> G;
Vi edges;

void dfs(int i) {
    each(e, G[i].next) {
        edges.pb(e.id);
        dfs(e.dst);
    }
}

void run() {
    int n, m, k; cin >> n >> m >> k;
    G.resize(n);

    rep(i, 0, m) {
        int a, b, w; cin >> a >> b >> w;
        G[a-1].E.pb({ i, b-1, w });
        G[b-1].E.pb({ i, a-1, w });
    }

    priority_queue<pair<ll, int>> que;
    que.push({ 0, 0 });
    G[0].dist = 0;

    while (!que.empty()) {
        ll dist = -que.top().x;
        int v = que.top().y;
        que.pop();

        if (dist != G[v].dist) continue;

        each(e, G[v].E) {
            ll alt = dist+e.w;
            if (alt < G[e.dst].dist) {
                G[e.dst].dist = alt;
                G[e.dst].par = v;
                G[e.dst].parE = e.id;
                que.push({ -alt, e.dst });
            }
        }
    }

    rep(i, 0, sz(G)) {
        auto& v = G[i];
        if (v.par != -1) {
            G[v.par].next.pb({ v.parE, i, 0 });
        }
    }

    dfs(0);

    int ret = min(k, sz(edges));
    cout << ret << '\n';

    rep(i, 0, ret) cout << edges[i]+1 << ' ';
    cout << endl;
}