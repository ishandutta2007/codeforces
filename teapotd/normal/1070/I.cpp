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

typedef ll Flow;
struct Edge {
    int dest, back;
    Flow f, c;
};

struct PushRelabel {
    vector<vector<Edge>> g;
    vector<Flow> ec;
    vector<Edge*> cur;
    vector<Vi> hs; Vi H;
    PushRelabel(int n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}
    void add_edge(int s, int t, Flow cap, Flow rcap=0) {
        if (s == t) return;
        Edge a = {t, sz(g[t]), 0, cap};
        Edge b = {s, sz(g[s]), 0, rcap};
        g[s].push_back(a);
        g[t].push_back(b);
    }
    void add_flow(Edge& e, Flow f) {
        Edge &back = g[e.dest][e.back];
        if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
        e.f += f; e.c -= f; ec[e.dest] += f;
        back.f -= f; back.c += f; ec[back.dest] -= f;
    }
    Flow maxflow(int s, int t) {
        int v = sz(g); H[s] = v; ec[t] = 1;
        Vi co(2*v); co[0] = v-1;
        rep(i,0,v) cur[i] = g[i].data();
        each(e, g[s]) add_flow(e, e.c);
        for (int hi = 0;;) {
            while (hs[hi].empty()) if (!hi--) return -ec[s];
            int u = hs[hi].back(); hs[hi].pop_back();
            while (ec[u] > 0)  // discharge u
                if (cur[u] == g[u].data() + sz(g[u])) {
                    H[u] = 1e9;
                    each(e, g[u]) if (e.c && H[u] > H[e.dest]+1)
                        H[u] = H[e.dest]+1, cur[u] = &e;
                    if (++co[H[u]], !--co[hi] && hi < v)
                        rep(i,0,v) if (hi < H[i] && H[i] < v)
                            --co[H[i]], H[i] = v + 1;
                    hi = H[u];
                } else if (cur[u]->c && H[u] == H[cur[u]->dest]+1)
                    add_flow(*cur[u], min(ec[u], cur[u]->c));
                else ++cur[u];
        }
    }
};

void nope(int m) {
    rep(i, 0, m) cout << "0 ";
    cout << '\n';
}

void handle() {
    int n, m, k; cin >> n >> m >> k;
    Vi degs(n);
    vector<Pii> edges(m);

    each(e, edges) {
        cin >> e.x >> e.y;
        e.x--; e.y--;
        degs[e.x]++;
        degs[e.y]++;
    }

    each(d, degs) {
        if (d > k*2) {
            nope(m);
            return;
        }
    }

    PushRelabel flow(n+m+2);

    rep(i, 0, m) {
        flow.add_edge(0, 2+i, 1);
        flow.add_edge(2+i, 2+m+edges[i].x, 1);
        flow.add_edge(2+i, 2+m+edges[i].y, 1);
    }

    rep(i, 0, n) {
        flow.add_edge(2+m+i, 1, 2*k - degs[i]);
    }

    if (flow.maxflow(0, 1) != m) {
        nope(m);
        return;
    }

    Vi toPair(n);
    Vi ans(m);
    iota(all(ans), 1);

    rep(i, 0, m) {
        each(e, flow.g[2+i]) if (e.f == 0) {
            int v = e.dest-m-2;

            if (toPair[v]) {
                ans[i] = toPair[v];
                toPair[v] = 0;
            } else {
                toPair[v] = ans[i];
            }
            break;
        }
    }

    each(a, ans) cout << a << ' ';
    cout << '\n';
}

void run() {
    int t; cin >> t;
    while (t--) handle();
}