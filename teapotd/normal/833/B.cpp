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

struct SegTree {
    using T = int;
    const T ID = 0;

    struct Agg {
        T vMax{INT_MIN};
        void leaf() { vMax = 0; }

        void merge(const Agg& r) {
            vMax = max(vMax, r.vMax);
        }

        bool apply(T& lazy, T& x, int) {
            lazy += x;
            vMax += x;
            return 1;
        }
    };

    vector<Agg> agg;
    vector<T> lazy;
    int len{1};

    SegTree(int n = 0) {
        while (len < n) len *= 2;
        agg.resize(len*2);
        lazy.resize(len*2, ID);
        rep(i, 0, n) agg[len+i].leaf();
        for (int i = len; --i;)
            (agg[i] = agg[i*2]).merge(agg[i*2+1]);
    }

    void push(int i, int s) {
        if (lazy[i] != ID) {
            agg[i*2].apply(lazy[i*2], lazy[i], s/2);
            agg[i*2+1].apply(lazy[i*2+1],
                             lazy[i], s/2);
            lazy[i] = ID;
        }
    }

    T update(int vb, int ve, T val, int i = 1,
             int b = 0, int e = -1) {
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

    Agg query(int vb, int ve, int i = 1,
              int b = 0, int e = -1) {
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
    int n, k; cin >> n >> k;
    Vi types(n);
    each(t, types) {
        cin >> t;
        t--;
    }

    Vi cur(n+1), prev(n+1);

    rep(layer, 0, k) {
        cur.swap(prev);
        SegTree tree(n+1);
        Vi last(n, 0);
        cur[0] = 0;

        rep(i, 1, n+1) {
            int e = types[i-1];
            tree.update(i-1, i, prev[i-1]);
            tree.update(last[e], i, 1);
            last[e] = i;
            cur[i] = tree.query(0, i).vMax;
        }
    }

    cout << cur[n] << '\n';
}