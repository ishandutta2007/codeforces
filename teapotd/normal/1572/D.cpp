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
    cout << flush; _Exit(0);
}

using flow_t = ll;
constexpr flow_t INF = 1e18;

struct MCMF {
    struct Edge {
        int dst, inv;
        flow_t flow, cap, cost;
    };

    vector<vector<Edge>> G;
    vector<flow_t> add;

    MCMF(int n = 0) : G(n) {}

    int addVert() { G.pb({}); return sz(G)-1; }

    int addEdge(int u, int v,
                flow_t cap, flow_t cost) {
        G[u].pb({ v, sz(G[v]), 0, cap, cost });
        G[v].pb({ u, sz(G[u])-1, 0, 0, -cost });
        return sz(G[u])-1;
    }

    bool maxFlow(int src, int dst, int wanted, flow_t& f, flow_t& c) {
        flow_t i, m, d;
        f = c = 0;
        each(v, G) each(e, v) e.flow = 0;
        vector<flow_t> pot(sz(G));

    nxt:
        Vi prev(sz(G), -1);
        vector<flow_t> dist(sz(G), INF);
        priority_queue<pair<flow_t, int>> Q;
        add.assign(sz(G), -1);
        Q.push({0, src});
        add[src] = INF;
        dist[src] = 0;

        while (!Q.empty() && f < wanted) {
            tie(d, i) = Q.top();
            Q.pop();
            if (d != -dist[i]) continue;
            m = add[i];

            if (i == dst) {
                f += m;
                c += m * (dist[i]-pot[src]+pot[i]);
                while (i != src) {
                    auto& e = G[i][prev[i]];
                    e.flow -= m;
                    G[i = e.dst][e.inv].flow += m;
                }
                rep(j, 0, sz(G))
                    pot[j] = min(pot[j]+dist[j], INF);
                goto nxt;
            }

            each(e, G[i]) if (e.flow < e.cap) {
                d = dist[i]+e.cost+pot[i]-pot[e.dst];
                if (d < dist[e.dst]) {
                    Q.push({-d, e.dst});
                    prev[e.dst] = e.inv;
                    add[e.dst] = min(m, e.cap-e.flow);
                    dist[e.dst] = d;
                }
            }
        }
        return 1;
    }
};

void run() {
    int n, k; cin >> n >> k;
    Vi weight(1<<n);

    constexpr ll MX = 2e6;
    each(w, weight) {
        cin >> w;
        w = MX - w;
    }

    vector<pair<int, Pii>> edges;

    rep(i, 0, 1<<n) if (__builtin_parity(i)) {
        rep(b, 0, n) {
            int j = i ^ (1<<b);
            edges.pb({ weight[i]+weight[j], {i, j} });
        }
    }

    constexpr int CUT = 2e4;
    if (sz(edges) > CUT) {
        nth_element(edges.begin(), edges.begin() + CUT, edges.end());
        edges.resize(CUT);
    }

    MCMF G(2);
    Vi id(1<<n, -1);

    each(e, edges) {
        int u = e.y.x, v = e.y.y;
        if (id[u] == -1) {
            id[u] = G.addVert();
            G.addEdge(0, id[u], 1, weight[u]);
        }
        if (id[v] == -1) {
            id[v] = G.addVert();
            G.addEdge(id[v], 1, 1, weight[v]);
        }
        G.addEdge(id[u], id[v], 1, 0);
    }

    ll f, c;
    G.maxFlow(0, 1, k, f, c);

    ll ans = MX*f*2 - c;
    cout << ans << '\n';
}