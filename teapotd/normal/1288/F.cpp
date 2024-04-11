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
#include <bits/extc++.h>

const ll INF = numeric_limits<ll>::max() / 4;
typedef vector<ll> VL;

// https://github.com/kth-competitive-programming/kactl/blob/master/content/graph/MinCostMaxFlow.h
struct MCMF {
    int N;
    vector<Vi> ed, red;
    vector<VL> cap, flow, cost;
    Vi seen;
    VL dist, pi;
    vector<Pii> par;

    MCMF(int n) :
        N(n), ed(N), red(N), cap(N, VL(N)), flow(cap), cost(cap),
        seen(N), dist(N), pi(N), par(N) {}

    void addEdge(int from, int to, ll cap_, ll cost_) {
        this->cap[from][to] = cap_;
        this->cost[from][to] = cost_;
        ed[from].push_back(to);
        red[to].push_back(from);
    }

    void path(int s) {
        fill(all(seen), 0);
        fill(all(dist), INF);
        dist[s] = 0; ll di;

        __gnu_pbds::priority_queue<pair<ll, int>> q;
        vector<decltype(q)::point_iterator> its(N);
        q.push({0, s});

        auto relax = [&](int i, ll cap_, ll cost_, int dir) {
            ll val = di - pi[i] + cost_;
            if (cap_ && val < dist[i]) {
                dist[i] = val;
                par[i] = {s, dir};
                if (its[i] == q.end()) its[i] = q.push({-dist[i], i});
                else q.modify(its[i], {-dist[i], i});
            }
        };

        while (!q.empty()) {
            s = q.top().second; q.pop();
            seen[s] = 1; di = dist[s] + pi[s];
            each(i, ed[s]) if (!seen[i])
                relax(i, cap[s][i] - flow[s][i], cost[s][i], 1);
            each(i, red[s]) if (!seen[i])
                relax(i, flow[i][s], -cost[i][s], 0);
        }
        rep(i,0,N) pi[i] = min(pi[i] + dist[i], INF);
    }

    pair<ll, ll> maxflow(int s, int t) {
        ll totflow = 0, totcost = 0;
        while (path(s), seen[t]) {
            ll fl = INF;
            for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p)
                fl = min(fl, r ? cap[p][x] - flow[p][x] : flow[x][p]);
            totflow += fl;
            for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p)
                if (r) flow[p][x] += fl;
                else flow[x][p] -= fl;
        }
        rep(i,0,N) rep(j,0,N) totcost += cost[i][j] * flow[i][j];
        return {totflow, totcost};
    }

    // If some costs can be negative, call this before maxflow:
    void setpi(int s) { // (otherwise, leave this out)
        fill(all(pi), INF); pi[s] = 0;
        int it = N, ch = 1; ll v;
        while (ch-- && it--)
            rep(i,0,N) if (pi[i] != INF)
                each(to, ed[i]) if (cap[i][to])
                    if ((v = pi[i] + cost[i][to]) < pi[to])
                        pi[to] = v, ch = 1;
        assert(it >= 0); // negative cost cycle
    }
};

void run() {
    int n1, n2, m, r, b;
    cin >> n1 >> n2 >> m >> r >> b;

    int src = n1+n2, dst = n1+n2+1;
    int src2 = dst+1, dst2 = dst+2;

    MCMF flow(dst2+1);
    vector<VL> demand(flow.N, VL(flow.N));

    string left, right;
    cin >> left >> right;

    rep(i, 0, n1) {
        if (left[i] == 'U') {
            flow.addEdge(src, i, INF, 0);
            flow.addEdge(i, dst, INF, 0);
        } else if (left[i] == 'R') {
            flow.addEdge(src, i, INF, 0);
            demand[src][i] += 1;
        } else if (left[i] == 'B') {
            flow.addEdge(i, dst, INF, 0);
            demand[i][dst] += 1;
        } else {
            assert(0);
        }
    }

    rep(i, 0, n2) {
        if (right[i] == 'U') {
            flow.addEdge(src, i+n1, INF, 0);
            flow.addEdge(i+n1, dst, INF, 0);
        } else if (right[i] == 'B') {
            flow.addEdge(src, i+n1, INF, 0);
            demand[src][i+n1] += 1;
        } else if (right[i] == 'R') {
            flow.addEdge(i+n1, dst, INF, 0);
            demand[i+n1][dst] += 1;
        } else {
            assert(0);
        }
    }

    map<Pii, Vi> edges;

    rep(i, 0, m) {
        int u, v; cin >> u >> v;
        u--; v--;
        edges[{u, v}].pb(i);
    }

    each(e, edges) {
        flow.addEdge(e.x.x, e.x.y+n1, sz(e.y), r);
        flow.addEdge(e.x.y+n1, e.x.x, sz(e.y), b);
    }

    VL din(flow.N), dout(flow.N);
    ll wanted = 0;

    rep(i, 0, flow.N) rep(j, 0, flow.N) {
        din[j] += demand[i][j];
        dout[i] += demand[i][j];
    }

    flow.addEdge(dst, src, INF, 0);

    rep(i, 0, n1+n2+2) {
        flow.addEdge(src2, i, din[i], 0);
        flow.addEdge(i, dst2, dout[i], 0);
        wanted += din[i];
    }

    ll totFlow, totCost;
    tie(totFlow, totCost) = flow.maxflow(src2, dst2);

    deb(totFlow, totCost, wanted);

    if (totFlow != wanted) {
        cout << "-1\n";
        return;
    }

    string ans(m, 'U');

    each(e, edges) {
        ll nr = flow.flow[e.x.x][e.x.y+n1];
        ll nb = flow.flow[e.x.y+n1][e.x.x];
        ll cut = min(nr, nb);
        nr -= cut;
        nb -= cut;

        char chr = (nr > 0 ? 'R' : 'B');
        rep(i, 0, nr+nb) {
            ans[e.y[i]] = chr;
        }
    }

    cout << totCost << '\n';
    cout << ans << '\n';
}