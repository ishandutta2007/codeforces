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

struct SegTree {
    vector<ll> tAdd, tMax;
    int len;

    SegTree(int n) {
        for (len = 1; len < n; len *= 2);
        tAdd.resize(len*2);
        tMax.resize(len*2);
    }

    ll getMax() const {
        return tMax[1];
    }

    void add(int vb, int ve, ll val, int i = 1, int b = 0, int e = -1) {
        if (e < 0) e = len;
        if (b >= ve || vb >= e) return;

        if (b >= vb && e <= ve) {
            tAdd[i] += val;
            tMax[i] += val;
            return;
        }

        int m = (b+e) / 2;
        add(vb, ve, val, i*2, b, m);
        add(vb, ve, val, i*2+1, m, e);
        tMax[i] = max(tMax[i*2], tMax[i*2+1]) + tAdd[i];
    }
};

struct Entry {
    int center, subtree, pre, post;
};

vector<vector<Pii>> G;
vector<ll> weights;

Vi siz;
vector<bool> enabled;
int pre;

multiset<ll> cands;
vector<multiset<ll>> centers;
vector<Pii> subtreeRange;
vector<SegTree> subtrees;
vector<vector<Entry>> entries;

ll bestPath(const multiset<ll>& s) {
    if (s.empty()) return 0;
    if (sz(s) == 1) return *s.begin();
    return *s.rbegin() + *next(s.rbegin());
}

ll diam() {
    if (cands.empty()) return 0;
    return *cands.rbegin();
}

void dfsSize(int v, int p) {
    siz[v] = 1;
    each(e, G[v]) if (e.x != p && enabled[e.x]) {
        dfsSize(e.x, v);
        siz[v] += siz[e.x];
    }
}

void dfs(int v, int p, int eid) {
    int begin = pre++;
    each(e, G[v]) if (e.x != p && enabled[e.x]) {
        dfs(e.x, v, e.y);
    }
    entries[eid].pb({ sz(centers)-1, sz(subtrees), begin, pre });
}

void decomp(int v) {
    dfsSize(v, -1);
    int p = -1, s = siz[v];
    bool ok = 1;

    while (ok) {
        ok = 0;
        each(e, G[v]) if (e.x != p && enabled[e.x] && siz[e.x] > s/2) {
            p = v; v = e.x;
            ok = 1;
            break;
        }
    }

    centers.emplace_back();
    subtreeRange.pb({sz(subtrees), 0});

    each(e, G[v]) if (enabled[e.x]) {
        pre = 0;
        dfs(e.x, v, e.y);
        subtrees.emplace_back(pre);
    }

    subtreeRange.back().y = sz(subtrees);

    enabled[v] = 0;
    each(e, G[v]) if (enabled[e.x]) decomp(e.x);
}

void run() {
    int n, q;
    ll w;
    cin >> n >> q >> w;
    G.resize(n);
    weights.resize(n-1);

    rep(i, 0, n-1) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--; b--;
        G[a].pb({b, i});
        G[b].pb({a, i});
        weights[i] = c;
    }

    siz.resize(n);
    enabled.resize(n, 1);
    entries.resize(n-1);
    decomp(0);

    rep(i, 0, n-1) {
        each(e, entries[i]) {
            subtrees[e.subtree].add(e.pre, e.post, weights[i]);
        }
    }

    rep(i, 0, sz(centers)) {
        rep(j, subtreeRange[i].x, subtreeRange[i].y) {
            centers[i].insert(subtrees[j].getMax());
        }
        cands.insert(bestPath(centers[i]));
    }

    ll last = 0;
    deb(diam());

    rep(i, 0, q) {
        ll d, nw;
        cin >> d >> nw;
        d = (d+last) % (n-1);
        nw = (nw+last) % w;

        ll diff = nw-weights[d];
        weights[d] = nw;

        each(e, entries[d]) {
            auto& cen = centers[e.center];
            auto& sub = subtrees[e.subtree];
            cands.erase(cands.find(bestPath(cen)));
            cen.erase(cen.find(sub.getMax()));
            sub.add(e.pre, e.post, diff);
            cen.insert(sub.getMax());
            cands.insert(bestPath(cen));
        }

        last = diam();
        cout << last << '\n';
    }
}