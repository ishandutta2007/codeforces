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

int n, cnt;
vector<Vi> T1, T2;
Vi pre, post;

struct Edge {
    int src, dst, curDst;
    bool operator<(const Edge& r) const {
        return pre[curDst] < pre[r.curDst];
    }
};

vector<Edge> par;
vector<set<Edge>> children;
Vi group;

int find(int i) {
    return group[i] == -1 ? i : group[i] = find(group[i]);
}

void dfs(int v, int p) {
    pre[v] = ++cnt;

    if (p != -1) {
        par[v] = {v, p, p};
    } else {
        par[v] = {-1, -1, -1};
    }

    each(e, T1[v]) if (e != p) {
        dfs(e, v);
        children[v].insert({v, e, e});
    }

    post[v] = ++cnt;
}

void contract(int v) {
    int p = par[v].curDst;
    assert(p != -1);
    assert(children[p].erase({-1, -1, v}));
    group[find(v)] = find(p);

    each(e, children[v]) {
        children[p].insert({e.src, e.dst, e.curDst});
        par[e.curDst].curDst = p;
    }
}

void solve(int v, int p) {
    each(e, T2[v]) if (e != p) solve(e, v);
    if (p == -1) return;

    Edge tmp;
    int x = find(v);

    if (pre[x] <= pre[p] && post[p] <= post[x]) {
        auto it = children[x].upper_bound({ -1, -1, p });
        assert(it != children[x].begin());
        it--;
        tmp = *it;
        assert(pre[tmp.dst] <= pre[p] && post[p] <= post[tmp.dst]);
        contract(tmp.curDst);
    } else {
        tmp = par[x];
        contract(x);
    }

    cout << tmp.src+1 << ' ' << tmp.dst+1 << ' ' << v+1 << ' ' << p+1 << '\n';
}

void load(vector<Vi>& G) {
    G.resize(n);
    rep(i, 1, n) {
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].pb(v);
        G[v].pb(u);
    }
}

void run() {
    cin >> n;
    load(T1);
    load(T2);

    pre.resize(n);
    post.resize(n);
    par.resize(n);
    children.resize(n);
    group.resize(n, -1);

    dfs(0, -1);
    cout << n-1 << '\n';
    solve(0, -1);
}