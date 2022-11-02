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

int n;
vector<Vi> G;
vector<Pii> ans;
int maxDeg;

#ifdef LOC
set<Pii> allEdges;
vector<set<int>> used;
vector<bool> seen;
int lastV = -1, lastK = -1;
#endif

void step(int v, int k) {
    ans.pb({v, k});
#ifdef LOC
    if (lastV == -1) {
        assert(v == 0);
        assert(k == 0);
    } else {
        if (v != lastV) {
            assert(k == lastK+1);
            assert(allEdges.count({v, lastV}));
        } else {
            assert(k < lastK);
        }
    }
    assert(used[v].insert(k).y);
    seen[v] = 1;
    lastV = v;
    lastK = k;
#endif
}

void dfs(int v, int p, int k) {
    int orig = k;
    int deg = sz(G[v]);

    each(e, G[v]) if (e != p) {
        if (k == maxDeg) {
            k = maxDeg-deg;
            step(v, k);
        }
        step(e, ++k);
        dfs(e, v, k);
    }

    if (p != -1) {
        if (k != orig-1) {
            k = orig-1;
            step(v, k);
        }
        step(p, ++k);
    }
}

void run() {
    cin >> n;
    G.resize(n);

    rep(i, 1, n) {
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].pb(v);
        G[v].pb(u);
#ifdef LOC
        allEdges.insert({u, v});
        allEdges.insert({v, u});
#endif
    }

#ifdef LOC
    seen.resize(n);
    used.resize(n);
#endif

    each(v, G) {
        maxDeg = max(maxDeg, sz(v));
    }

    step(0, 0);

    if (n == 1) {
    } else if (n == 2) {
        step(1, 1);
        step(1, 0);
        step(0, 1);
    } else {
        dfs(0, -1, 0);
    }

#ifdef LOC
    rep(i, 0, n) {
        assert(seen[i]);
        assert(*used[i].rbegin() >= 0);
        assert(*used[i].rbegin() <= maxDeg);
    }
#endif

    cout << sz(ans) << '\n';
    each(a, ans) {
        cout << a.x+1 << ' ' << a.y << '\n';
    }
}