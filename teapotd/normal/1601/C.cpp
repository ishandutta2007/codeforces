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

    /*void print() {
        Vi tmp(len);
        rep(i, 0, len) tmp[i] = query(i, i+1).vMin;
        deb(tmp);
    }*/
};

Vi compressVec(vector<int*>& vec) {
    sort(all(vec), [](int* l, int* r) { return *l < *r; });
    Vi old;
    each(e, vec) {
        if (old.empty() || old.back() != *e) old.pb(*e);
        *e = sz(old)-1;
    }
    return old;
}

ll countInversions(Vi perm, int lim) {
    ll ret = 0, cont = 1;
    Vi odd;
    while (cont) {
        odd.assign(lim+5, 0);
        cont = 0;
        rep(i, 0, sz(perm)) {
            if (perm[i] % 2) odd[perm[i]]++;
            else ret += odd[perm[i]+1];
            cont += perm[i] /= 2;
        }
    }
    return ret;
}

void solve() {
    int n, m; cin >> n >> m;
    Vi a(n), b(m);
    vector<int*> tmp;

    each(e, a) cin >> e, tmp.pb(&e);
    each(e, b) cin >> e, tmp.pb(&e);

    int mx = sz(compressVec(tmp));
    ll ans = countInversions(a, mx);

    Vi aSorted(n);
    iota(all(aSorted), 0);
    sort(all(aSorted), [&](int l, int r) { return a[l] < a[r]; });
    sort(all(b));

    SegTree tree(n+1);
    rep(i, 1, n+1) tree.update(i, n+1, 1);
    int j = 0, k = 0;

    //deb(a, b);
    //tree.print();

    each(e, b) {
        deb(e);
        while (j < n && a[aSorted[j]] <= e) {
            tree.update(aSorted[j]+1, n+1, -1);
            j++;
        }
        //tree.print();
        while (k < n && a[aSorted[k]] < e) {
            tree.update(0, aSorted[k]+1, 1);
            k++;
        }
        //tree.print();
        ans += tree.query(0, n+1).vMin;
        //tree.print();
    }

    cout << ans << '\n';
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}