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

vector<Vi> G;
Vi dist;
int sm, gr;

void dfs(int v, int p, int d) {
    dist[v] = max(dist[v], d);
    if (dist[v] < dist[sm]) sm = v;
    if (dist[v] > dist[gr]) gr = v;
    each(e, G[v]) if (e != p) {
        dfs(e, v, d+1);
    }
}

void check(int v) {
    sm = gr = v;
    dfs(v, -1, 0);
}

void run() {
    int n, m;
    cin >> n >> m;

    G.resize(n);
    rep(i, 0, m) {
        int u, v; cin >> u >> v;
        G[u-1].pb(v-1);
        G[v-1].pb(u-1);
    }

    dist.resize(n, -1);
    vector<Pii> pivots;
    int bound = 0;

    rep(v, 0, n) {
        if (dist[v] == -1) {
            check(v);
            check(gr);
            check(gr);
            pivots.pb({sm, dist[sm]});
            bound = max(bound, dist[gr]);
        }
    }

    Pii best = {INT_MAX, -1};

    rep(i, 0, sz(pivots)) {
        int m1 = -1, m2 = -1;
        rep(j, 0, sz(pivots)) {
            if (i != j) {
                int x = pivots[j].y;
                if (x >= m1) {
                    m2 = m1;
                    m1 = x;
                } else {
                    m2 = max(m2, x);
                }
            }
        }
        int x = pivots[i].y;
        int alt = max(bound, max(m1+x+1, m1+m2+2));
        best = min(best, mp(alt, i));
    }

    cout << best.x << '\n';

    rep(i, 0, sz(pivots)) {
        if (i != best.y) {
            cout << pivots[best.y].x+1 << ' ' << pivots[i].x+1 << '\n';
        }
    }
}