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

struct Fenwick {
    using T = int;
    T f(T a, T b)  { return a+b; }

    vector<T> s;
    Fenwick(int n = 0) : s(n, 0) {}

    void modify(int i, T v) {
        for (; i < sz(s); i |= i+1) s[i]=f(s[i],v);
    }

    T query(int i) {
        T v = 0;
        for (; i > 0; i &= i-1) v = f(v, s[i-1]);
        return v;
    }
};

constexpr int INF = 1e9;

Fenwick taken;
Vi tAdd, tMin;
int len;

void add(int vb, int ve, int val, int i = 1, int b = 0, int e = len) {
    if (b >= ve || vb >= e) return;
    if (b >= vb && e <= ve) {
        tAdd[i] += val;
        tMin[i] += val;
        return;
    }
    int m = (b+e) / 2;
    add(vb, ve, val, i*2, b, m);
    add(vb, ve, val, i*2+1, m, e);
    tMin[i] = min(tMin[i*2], tMin[i*2+1]) + tAdd[i];
}

int getZero() {
    if (tMin[1] > 0) return -1;
    int i = 1;
    while (i < len) {
        if (tMin[i*2] < tMin[i*2+1]) {
            i *= 2;
        } else {
            i = i*2+1;
        }
    }
    return i-len;
}

void checkZeroes() {
    while (true) {
        int i = getZero();
        if (i == -1) break;
        taken.modify(i, 1);
        add(i, i+1, INF);
        add(i+1, len, -1);
    }
}

void run() {
    int n, q; cin >> n >> q;
    Vi elems(n);

    rep(i, 0, n) {
        int k; cin >> k;
        k = i+1 - k;
        if (k < 0) k = INF;
        elems[i] = k;
    }

    for (len = 1; len < n; len *= 2);
    tAdd.resize(len*2);
    tMin.resize(len*2);
    taken = {n};

    rep(i, 0, len) {
        tAdd[i+len] = tMin[i+len] = INF;
    }

    for (int i = len-1; i > 0; i--) {
        tMin[i] = min(tMin[i*2], tMin[i*2+1]) + tAdd[i];
    }

    vector<Pii> queries(q);
    each(e, queries) cin >> e.x >> e.y;

    Vi ans(q);
    vector<Vi> gr(n);
    rep(i, 0, q) gr[queries[i].x].pb(i);

    for (int i = n-1; i >= 0; i--) {
        add(i, i+1, -INF+elems[i]);
        checkZeroes();
        each(e, gr[i]) {
            ans[e] = taken.query(n - queries[e].y);
        }
    }

    each(a, ans) {
        cout << a << '\n';
    }
}