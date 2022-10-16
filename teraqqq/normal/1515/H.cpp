#include <iostream>
#include <cassert>
#include <bitset>

#define F first
#define S second

using namespace std;
using pi = pair<int, int>;

const int N = 2e5+7;
const int Q = 1e5+7;
const int W = 20;
const int V = 16e6;
const int NIL = 0;

bool leaf[V];
int n, vc = 1, w[V], c[V], g[2][V];
pi lazy[V];
const pi neutral { (1<<W)-1, 0 };

pi compose(pi a, pi b) { return { a.F & b.F, (b.S & a.F) ^ a.S }; }
pi shift(pi x) { return {(x.F>>1)|(1<<(W-1)), x.S>>1}; }
int unite(int, int);

// O(1)
void push(int v) {
    if (lazy[v] == neutral || leaf[v]) return;
    if (g[0][v]) lazy[g[0][v]] = compose(shift(lazy[v]), lazy[g[0][v]]);
    if (g[1][v]) lazy[g[1][v]] = compose(shift(lazy[v]), lazy[g[1][v]]);

    if (lazy[v].F & 1) {
        if (lazy[v].S & 1) swap(g[0][v], g[1][v]);
    } else {
        assert(!g[0][v] || !g[1][v]);
        if (lazy[v].S & 1) g[1][v] = unite(g[1][v], g[0][v]), g[0][v] = NIL;
        else               g[0][v] = unite(g[1][v], g[0][v]), g[1][v] = NIL;
    }

    lazy[v] = neutral;
}

// O(1)
void calc(int v) {
    if (leaf[v]) {
        c[v] = 1;
        w[v] = 0;
    } else {
        c[v] = c[g[0][v]] + c[g[1][v]];
        w[v] = (w[g[0][v]] | w[g[1][v]]) << 1;
        if (g[0][v] && g[1][v]) w[v]++;
    }
}

// O('deleted' + W)
int unite(int a, int b) {
    if (!a || !b) return max(a, b);

    push(a), push(b);
    g[0][a] = unite(g[0][a], g[0][b]);
    g[1][a] = unite(g[1][a], g[1][b]);
    calc(a);
    return a;
}

// O(W)
int bamboo(int x) {
    const int root = vc++;
    int cur = root;
    c[cur] = 1;
    for (int i = W; i--; ) {
        g[(x >> i) & 1][cur] = vc;
        cur = vc++;
        c[cur] = 1;
    }

    leaf[cur] = 1;

    return root;
}

// O(W)
int cut(int& v, int vl, int vr, int l, int r) {
    if (r <= vl || vr <= l || !v) return NIL;
    if (l <= vl && vr <= r) {
        int x = v; v = NIL;
        return x;
    }

    const int vm = (vl + vr) / 2; push(v);
    int res = vc++;
    g[0][res] = cut(g[0][v], vl, vm, l, r);
    g[1][res] = cut(g[1][v], vm, vr, l, r);
    calc(res); calc(v);
    if (!c[v]) v = 0;
    if (!c[res]) res = 0;
    return res;
}

// O(W)
int rev(int x) {
    int y = 0;
    for (int i = W; i--; x >>= 1) {
        if (x & 1) y |= 1 << i;
    }
    return y;
}

void tour(int v, int vl, int vr) {
    if (!v) return;

    if (vl + 1 == vr) {
        cout << vl << ' ';
    } else {
        int vm = (vl + vr) / 2; push(v);
        tour(g[0][v], vl, vm);
        tour(g[1][v], vm, vr);
    }
}

// O(W)
void tree_or(int v, int vl, int vr, int val) {
    if (!v || (val & w[v]) == 0) {
        if (v) lazy[v] = compose(pi{ ((1<<W)-1) ^ val, val }, lazy[v]);
    } else {
        int vm = (vl + vr) / 2;
        push(v);
        tree_or(g[0][v], vl, vm, val >> 1);
        tree_or(g[1][v], vm, vr, val >> 1);
        if (val & 1) g[1][v] = unite(g[1][v], g[0][v]), g[0][v] = NIL;
        calc(v);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    fill(lazy, lazy+V, neutral);

    int root = 0;
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        root = unite(root, bamboo(x));
    }

    for (int i = 0; i < q; ++i) {
        int t, l, r, val; cin >> t >> l >> r; ++r;
        if (t != 4) cin >> val, val = rev(val);
        
        const int u = cut(root, 0, 1 << W, l, r);

        if (t == 1) {
            if (u) {
                lazy[u].S ^= (1 <<  W) - 1;
                tree_or(u, 0, 1 << W, ((1 << W) - 1) ^ val);
                lazy[u].S ^= (1 <<  W) - 1;
            }
        } else if (t == 2) {
            if (u) {
                tree_or(u, 0, 1 << W, val);
            }
        } else if (t == 3) {
            if (u) lazy[u].S ^= val;
        } else {
            cout << c[u] << '\n';
        }

        root = unite(root, u);
    }
}