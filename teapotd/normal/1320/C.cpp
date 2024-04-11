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

constexpr ll INF = 1e18;

struct SegTree {
    using T = ll;
    const T ID = 0;

    struct Agg {
        T vMax{-INF};
        void leaf() { }

        void merge(const Agg& r) {
            vMax = max(vMax, r.vMax);
        }

        bool apply(T& lazy, T& x, int) {
            lazy += x;
            vMax += x;
            return 1;
        }
    };

    vector<Agg> agg; // Aggregated data for nodes
    vector<T> lazy;  // Lazy tags for nodes
    int len{1};      // Number of leaves

    SegTree(int n = 0) {
        while (len < n) len *= 2;
        agg.resize(len*2);
        lazy.resize(len*2, ID);
        rep(i, 0, n) agg[len+i].leaf();
        for (int i = len; --i;) (agg[i] = agg[i*2]).merge(agg[i*2+1]);
    }

    void push(int i, int s) {
        if (lazy[i] != ID) {
            agg[i*2].apply(lazy[i*2], lazy[i], s/2);
            agg[i*2+1].apply(lazy[i*2+1],
                             lazy[i], s/2);
            lazy[i] = ID;
        }
    }

    T update(int vb, int ve, T val, int i = 1, int b = 0, int e = -1) {
        if (e < 0) e = len;
        if (vb >= e || b >= ve) return val;

        if (b >= vb && e <= ve &&
            agg[i].apply(lazy[i], val, e-b))
            return val;

        int m = (b+e) / 2;
        push(i, e-b);
        val = update(vb, ve, val, i*2, b, m);
        val = update(vb, ve, val, i*2+1, m, e);
        (agg[i] = agg[i*2]).merge(agg[i*2+1]);
        return val;
    }

    Agg query(int vb, int ve, int i = 1, int b = 0, int e = -1) {
        if (e < 0) e = len;
        if (vb >= e || b >= ve) return {};
        if (b >= vb && e <= ve) return agg[i];

        int m = (b+e) / 2;
        push(i, e-b);
        Agg t = query(vb, ve, i*2, b, m);
        t.merge(query(vb, ve, i*2+1, m, e));
        return t;
    }
};

void run() {
    int n, m, p; cin >> n >> m >> p;

    vector<Pii> hor;
    vector<ll> tmp(1e6+5, INF);

    rep(i, 0, n) {
        int x, y; cin >> x >> y;
        hor.pb({x, y});
    }

    rep(i, 0, m) {
        ll x, y; cin >> x >> y;
        tmp[x] = min(tmp[x], y);
    }

    vector<pair<Pii, int>> monsters(p);
    each(e, monsters) {
        cin >> e.x.x >> e.x.y >> e.y;
    }

    SegTree tree(sz(tmp));
    rep(i, 0, sz(tmp)) if (tmp[i] != INF) {
        tree.update(i, i+1, INF-tmp[i]);
    }

    sort(all(hor));
    sort(all(monsters));

    ll ans = INT64_MIN; //tree.query(0, sz(tmp)).vMax;
    int j = 0;

    each(e, hor) {
        while (j < p && monsters[j].x.x < e.x) {
            tree.update(monsters[j].x.y+1, sz(tmp), monsters[j].y);
            j++;
        }

        ll alt = tree.query(0, sz(tmp)).vMax;
        alt -= e.y;
        ans = max(ans, alt);
    }

    cout << ans << endl;
}