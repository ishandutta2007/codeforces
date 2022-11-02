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
    cout << fixed << setprecision(12);
    run();
    cout << flush; _Exit(0);
}

struct RollbackFAU {
    struct Entry { int x, y, z; };
    Vi G, col;
    vector<Entry> his;

    RollbackFAU(int n = 0) : G(n, -1), col(n, 0) {}

    pair<int, bool> find(int i) {
        if (G[i] < 0) return {i, col[i]};
        auto t = find(G[i]);
        return {t.x, t.y^col[i]};
    }

    int time() { return sz(his); }

    void rollback(int t) {
        for (int i = time(); t < i--;) {
            G[his[i].x] = his[i].y;
            col[his[i].x] = his[i].z;
        }
        his.resize(t);
    }

    bool join(int i, int j) {
        int c1, c2;
        tie(i, c1) = find(i);
        tie(j, c2) = find(j);
        if (i == j) return 0;

        his.pb({i, G[i], col[i]});
        his.pb({j, G[j], col[j]});
        if (c1 == c2) col[i] ^= 1;

        if (G[i] > G[j]) swap(i, j);
        G[i] += G[j]; G[j] = i;
        col[j] ^= col[i];
        return 1;
    }
};

struct Edge { int u, v, c; };
struct Query { int u, v, c, end; };

vector<Query> queries;
vector<vector<Edge>> tree;
vector<RollbackFAU> dsu;
map<Pii, int> col;
int len;

void insert(int vb, int ve, Edge val, int i = 1, int b = 0, int e = len) {
    if (vb >= e || b >= ve) return;
    if (b >= vb && e <= ve) return tree[i].pb(val);
    int m = (b+e) / 2;
    insert(vb, ve, val, i*2, b, m);
    insert(vb, ve, val, i*2+1, m, e);
}

void handle(int i) {
    if (i >= sz(queries)) return;
    auto& q = queries[i];
    int& c = col[{q.u, q.v}];
    if (c == q.c || dsu[q.c].find(q.u) != dsu[q.c].find(q.v)) {
        c = q.c;
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    if (c != -1) insert(i+1, q.end+1, {q.u, q.v, c});
}

void solve(int j) {
    Vi time(sz(dsu));
    rep(i, 0, sz(dsu)) time[i] = dsu[i].time();
    each(e, tree[j]) dsu[e.c].join(e.u, e.v);
    if (j >= len) {
        handle(j-len);
    } else {
        solve(j*2);
        solve(j*2+1);
    }
    rep(i, 0, sz(dsu)) dsu[i].rollback(time[i]);
}

void run() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;

    vector<Pii> edges(m);
    each(e, edges) cin >> e.x >> e.y, e.x--, e.y--;

    map<Pii, int> last;
    queries.resize(q);

    rep(i, 0, q) {
        int j, c; cin >> j >> c;
        j--; c--;
        auto& e = edges[j];

        if (last.count(e)) queries[last[e]].end = i;
        else col[e] = -1;
        last[e] = i;
        queries[i] = {e.x, e.y, c, q-1};
    }

    for (len = 1; len < q; len *= 2);
    tree.resize(len*2);
    dsu.resize(k, {n});

    solve(1);
}