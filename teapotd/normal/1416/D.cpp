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

struct FAU {
    Vi G;
    FAU(int n = 0) : G(n, -1) {}
    int size(int i) { return -G[find(i)]; }
    int find(int i) { return G[i] < 0 ? i : G[i] = find(G[i]); }
    bool join(int i, int j) {
        i = find(i); j = find(j);
        if (i == j) return 0;
        if (G[i] > G[j]) swap(i, j);
        G[i] += G[j]; G[j] = i;
        return 1;
    }
};

Vi vals;
vector<Vi> G;
vector<Pii> edges;
vector<bool> on;

Vi comp, flag;
vector<Vi> verts;
int cnt;

void sortVerts(Vi& vec) {
    sort(all(vec), [&](int l, int r) { return vals[l] < vals[r]; });
}

int popVal(int c) {
    while (!verts[c].empty()) {
        int v = verts[c].back();
        verts[c].pop_back();
        if (comp[v] == c) {
            int ret = vals[v];
            vals[v] = 0;
            return ret;
        }
    }
    return 0;
}

int dst(int v, int e) {
    if (!on[e]) return -1;
    return edges[e].x == v ? edges[e].y : edges[e].x;
}

void dfs(int v, int p, int c) {
    comp[v] = c;
    verts[c].pb(v);
    each(e, G[v]) {
        int u = dst(v, e);
        if (u != p) dfs(u, v, c);
    }
}

void cut(int cut1, int cut2) {
    queue<int> q1, q2;
    Vi vec1, vec2;

    cnt++;
    flag[cut1] = cnt;
    flag[cut2] = cnt;
    q1.push(cut1);
    q2.push(cut2);

    while (true) {
        if (q1.empty()) {
            break;
        }
        if (q2.empty()) {
            q2.swap(q1);
            vec1.swap(vec2);
            break;
        }

        {
            int v = q1.front();
            q1.pop();
            vec1.pb(v);

            rep(i, 0, sz(G[v])) {
                int& e = G[v][i];
                int u = dst(v, e);

                if (u == -1) {
                    e = G[v].back();
                    G[v].pop_back();
                    i--;
                    continue;
                }

                if (flag[u] != cnt) {
                    q1.push(u);
                    flag[u] = cnt;
                }
            }
        }

        {
            int v = q2.front();
            q2.pop();
            vec2.pb(v);

            rep(i, 0, sz(G[v])) {
                int& e = G[v][i];
                int u = dst(v, e);

                if (u == -1) {
                    e = G[v].back();
                    G[v].pop_back();
                    i--;
                    continue;
                }

                if (flag[u] != cnt) {
                    q2.push(u);
                    flag[u] = cnt;
                }
            }
        }
    }

    verts.pb(move(vec1));
    each(v, verts.back()) {
        comp[v] = sz(verts)-1;
    }
    sortVerts(verts.back());
}

void run() {
    int n, m, q; cin >> n >> m >> q;
    vals.resize(n);
    each(v, vals) cin >> v;

    edges.resize(m);
    each(e, edges) {
        cin >> e.x >> e.y;
        e.x--; e.y--;
    }

    vector<Pii> queries(q);
    vector<bool> used(m);

    each(e, queries) {
        cin >> e.x >> e.y;
        e.y--;
        if (e.x == 2) {
            used[e.y] = 1;
        }
    }

    rep(i, 0, m) {
        if (!used[i]) {
            queries.pb({ 2, i });
        }
    }

    FAU fau(n);
    q = sz(queries);
    on.resize(m);
    G.resize(n);

    for (int i = q-1; i >= 0; i--) {
        auto& e = queries[i];
        if (e.x == 2) {
            if (fau.join(edges[e.y].x, edges[e.y].y)) {
                on[e.y] = 1;
                G[edges[e.y].x].pb(e.y);
                G[edges[e.y].y].pb(e.y);
            }
        }
    }

    comp.resize(n, -1);

    rep(i, 0, n) {
        if (comp[i] == -1) {
            verts.emplace_back();
            dfs(i, -1, sz(verts)-1);
            sortVerts(verts.back());
        }
    }

    flag.resize(n, 0);
    cnt = 1;

    each(e, queries) {
        if (e.x == 1) {
            cout << popVal(comp[e.y]) << '\n';
        } else {
            if (on[e.y]) {
                on[e.y] = 0;
                cut(edges[e.y].x, edges[e.y].y);
            }
        }
    }
}