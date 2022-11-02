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
    T ID = 0;

    struct Agg {
        T vMin{INT_MAX};
        void leaf() { vMin = 0; }
        void merge(const Agg& r) { vMin = min(vMin, r.vMin); }
        bool apply(T& lazy, T& x, int) {
            lazy += x;
            vMin += x;
            return 1;
        }
    };

    // Root node is 1, left is i*2, right i*2+1
    vector<Agg> agg; // Aggregated data for nodes
    vector<T> lazy;  // Lazy tags for nodes
    int len{1};      // Number of leaves

    // Initialize tree for n elements; time: O(n)
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

    // Modify interval [vb;ve) with val; O(lg n)
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

    // Query interval [vb;ve); time: O(lg n)
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

struct Seg {
    int b, e, w;
    bool operator<(const Seg& r) const { return w < r.w; }
};

void run() {
    int n, m; cin >> n >> m;
    vector<Seg> segs(n);
    m--;

    each(s, segs) {
        cin >> s.b >> s.e >> s.w;
        s.b--; s.e--;
    }

    sort(all(segs));

    SegTree tree(m);
    int j = 0;
    int ans = 1e9;

    rep(i, 0, n) {
        while (tree.query(0, m).vMin == 0) {
            if (j == n) goto kek;
            tree.update(segs[j].b, segs[j].e, 1);
            j++;
        }
        ans = min(ans, segs[j-1].w - segs[i].w);
        tree.update(segs[i].b, segs[i].e, -1);
    }

kek:
    cout << ans << '\n';
}