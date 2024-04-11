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

using flow_t = int;
constexpr flow_t INF = 1e9+10;

struct MaxFlow {
    struct Edge {
        int to, inv;
        flow_t rem, cap;
    };

    vector<basic_string<Edge>> G;
    vector<flow_t> extra;
    Vi hei, arc, prv, nxt, act, bot;
    queue<int> Q;
    int n, high, cut, work;

    MaxFlow(int k = 0) : G(k) {}

    int addEdge(int u, int v,
                 flow_t cap, flow_t rcap = 0) {
        G[u].pb({ v, sz(G[v]), 0, cap });
        G[v].pb({ u, sz(G[u])-1, 0, rcap });
        return sz(G[u])-1;
    }

    void raise(int v, int h) {
        if (hei[v] < n)
            prv[nxt[prv[v]] = nxt[v]] = prv[v];
        if ((hei[v] = h) < n) {
            if (extra[v] > 0) {
                bot[v] = act[h], act[h] = v;
                high = max(high, h);
            }
            cut = max(cut, h);
            nxt[v] = nxt[prv[v] = h += n];
            prv[nxt[nxt[h] = v]] = v;
        }
    }

    void global(int t) {
        hei.assign(n, n);
        act.assign(n, -1);
        iota(all(prv), 0);
        iota(all(nxt), 0);
        hei[t] = high = cut = work = 0;
        for (Q.push(t); !Q.empty(); Q.pop()) {
            int v = Q.front();
            each(e, G[v])
                if (hei[e.to]==n && G[e.to][e.inv].rem)
                    Q.push(e.to), raise(e.to, hei[v]+1);
        }
    }

    void push(int v, Edge& e) {
        auto f = min(extra[v], e.rem);
        if (f > 0) {
            if (!extra[e.to]) {
                bot[e.to] = act[hei[e.to]];
                act[hei[e.to]] = e.to;
            }
            e.rem -= f; G[e.to][e.inv].rem += f;
            extra[v] -= f; extra[e.to] += f;
        }
    }

    void discharge(int v) {
        int h = n;

        auto go = [&](int a, int b) {
            rep(i, a, b) {
                auto& e = G[v][i];
                if (e.rem) {
                    if (hei[v] == hei[e.to]+1) {
                        push(v, e);
                        if (extra[v] <= 0)
                            return arc[v] = i, 0;
                    } else h = min(h, hei[e.to]+1);
                }
            }
            return 1;
        };

        if (go(arc[v], sz(G[v])) && go(0, arc[v])){
            int k = hei[v] + n;
            if (nxt[k] == prv[k]) {
                rep(j, k, cut+n+1)
                    while (nxt[j] < n) raise(nxt[j], n);
                cut = k-n-1;
            } else raise(v, h), work++;
        }
    }

    flow_t maxFlow(int src, int dst) {
        extra.assign(n = sz(G), 0);
        hei.assign(n, 0);
        arc.assign(n, 0);
        prv.resize(n*2);
        nxt.resize(n*2);
        act.resize(n);
        bot.resize(n);
        each(v, G) each(e, v) e.rem = e.cap;

        extra[dst] = -(extra[src] = INF);
        each(e, G[src]) push(src, e);
        global(dst);

        for (; high; high--)
            while (act[high] != -1) {
                int v = act[high];
                act[high] = bot[v];
                if (hei[v] == high) {
                    discharge(v);
                    if (work > 4*n) global(dst);
                }
            }

        return extra[dst] + INF;
    }
};

void run() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;

    MaxFlow flow(n);
    vector<Pii> edges;

    rep(i, 0, m) {
        int u, v, w; cin >> u >> v >> w;
        edges.pb({ u-1, flow.addEdge(u-1, v-1, w) });
    }

    Vi cuts(1<<k);

    rep(mask, 0, 1<<k) {
        rep(i, 0, k) {
            Pii e = edges[i];
            flow.G[e.x][e.y].cap = ((mask >> i) & 1 ? 0 : INF);
        }
        cuts[mask] = flow.maxFlow(0, n-1);
    }

    Vi weights(k), sums(1<<k);

    while (q--) {
        int ans = INF;
        each(w, weights) cin >> w;
        rep(mask, 1, 1<<k) sums[mask] = sums[mask & (mask-1)] + weights[__builtin_ctz(mask)];
        rep(mask, 0, 1<<k) ans = min(ans, cuts[mask] + sums[mask]);
        cout << ans << '\n';
    }
}