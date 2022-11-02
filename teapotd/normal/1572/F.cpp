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
    cout << flush; _Exit(0);
}

struct SegTree {
    using T = int;
    T ID = 0;

    struct Agg {
        T sum{0};
        void leaf() { sum = 1; }
        void merge(const Agg& r) { sum += r.sum; }
        bool apply(T& lazy, T& x, int size) {
            lazy += x;
            sum += x*size;
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
        for (int i = len; --i;) (agg[i] = agg[i*2]).merge(agg[i*2+1]);
    }

    void push(int i, int s) {
        if (lazy[i] != ID) {
            agg[i*2].apply(lazy[i*2], lazy[i], s/2);
            agg[i*2+1].apply(lazy[i*2+1], lazy[i], s/2);
            lazy[i] = ID;
        }
    }

    T update(int vb, int ve, T val, int i = 1, int b = 0, int e = -1) {
        if (e < 0) e = len;
        if (vb >= e || b >= ve) return val;
        if (b >= vb && e <= ve && agg[i].apply(lazy[i], val, e-b)) return val;
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

SegTree ans;
Vi tMax1, tCnt1, tMax2;
int len;

void push(int i) {
    if (i < len) {
        rep(j, 0, 2) {
            tMax1[i*2+j] = min(tMax1[i*2+j], tMax1[i]);
        }
    }
}

void update(int i) {
    tMax1[i] = tMax1[i*2];
    tCnt1[i] = tCnt1[i*2];
    tMax2[i] = tMax2[i*2];
    if (tMax1[i*2+1] > tMax1[i]) {
        tMax2[i] = tMax1[i];
        tMax1[i] = tMax1[i*2+1];
        tCnt1[i] = tCnt1[i*2+1];
    } else if (tMax1[i*2+1] == tMax1[i]) {
        tCnt1[i] += tCnt1[i*2+1];
    } else if (tMax1[i*2+1] > tMax2[i]) {
        tMax2[i] = tMax1[i*2+1];
    }
    tMax2[i] = max(tMax2[i], tMax2[i*2+1]);
}

void applySet(int pos, int val, int i = 1, int b = 0, int e = len) {
    if (i >= len) {
        ans.update(pos+1, tMax1[i], -1);
        ans.update(pos+1, val, 1);
        tMax1[i] = val;
        return;
    }

    int m = (b+e) / 2;
    push(i);
    if (pos < m) {
        applySet(pos, val, i*2, b, m);
    } else {
        applySet(pos, val, i*2+1, m, e);
    }
    update(i);
}

void applyMin(int vb, int ve, int val, int i = 1, int b = 0, int e = len) {
    if (vb >= e || b >= ve || tMax1[i] <= val) return;

    if (b >= vb && e <= ve && (tMax2[i] == -1 || tMax2[i] < val)) {
        ans.update(ve, tMax1[i], -tCnt1[i]);
        ans.update(ve, val, tCnt1[i]);
        tMax1[i] = val;
        return;
    }

    int m = (b+e) / 2;
    push(i);
    applyMin(vb, ve, val, i*2, b, m);
    applyMin(vb, ve, val, i*2+1, m, e);
    update(i);
}

void run() {
    int n, q; cin >> n >> q;
    ans = {n};
    len = ans.len;

    tMax1.resize(len*2);
    tCnt1.resize(len*2);
    tMax2.resize(len*2, -1);

    rep(i, 0, n) tCnt1[len+i] = 1;
    for (int i = len-1; i > 0; i--) tCnt1[i] = tCnt1[i*2] + tCnt1[i*2+1];

    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;

        if (t == 1) {
            a--;
            applySet(a, b);
            applyMin(0, a, a);
        } else {
            cout << ans.query(a-1, b).sum << '\n';
        }
    }
}