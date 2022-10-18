#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct dsu {
    vector<int> p;
    vector<int> sz;
    int n;

    dsu(int _n) : n(_n) {
        p = vector<int>(n);
        iota(p.begin(), p.end(), 0);
        sz = vector<int>(n, 1);
    }

    inline int get(int x) {
        if (p[x] == x) {
            return x;
        } else {
            return p[x] = get(p[x]);
        }
    }

    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) {
            return false;
        }
        p[x] = y;
        sz[y] += sz[x];
        return true;
    }

    inline bool same(int x, int y) {
        return (get(x) == get(y));
    }

    inline int size(int x) {
        return sz[get(x)];
    }

    inline bool root(int x) {
        return (x == get(x));
    }
};

long long solve(int n, int m, vector<tuple<int, int, int>> edges, int z) {
    for (int i = 0; i < m; i++) {
        get<0>(edges[i]) = abs(get<0>(edges[i]) - z);
    }
    sort(edges.begin(), edges.end());
    dsu uf(n);
    long long t = 0;
    for (auto [w, x, y] : edges) {
        if (uf.unite(x, y)) {
            t += w;
        }
    }
    return t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges(m);
    vector<int> ws(m);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--, y--;
        edges[i] = make_tuple(w, x, y);
        ws[i] = w;
    }
    sort(ws.begin(), ws.end());
    ws.resize(unique(ws.begin(), ws.end()) - ws.begin());
    int sz = (int) ws.size();
    for (int i = 0; i < sz; i++) {
        for (int j = i + 1; j < sz; j++) {
            ws.emplace_back((ws[j] + ws[i]) / 2);
            ws.emplace_back((ws[j] + ws[i] + 1) / 2);
        }
    }
    ws.emplace_back(0);
    ws.emplace_back((int) 1e8);
    sort(ws.begin(), ws.end());
    ws.resize(unique(ws.begin(), ws.end()) - ws.begin());
    vector<long long> a;
    for (int z : ws) {
        a.emplace_back(solve(n, m, edges, z));
    }
    debug(ws);
    debug(a);
    int pp, kk, aa, bb, cc;
    cin >> pp >> kk >> aa >> bb >> cc;
    int q = 0;
    long long ans = 0;
    for (int i = 0; i < kk; i++) {
        if (i < pp) {
            cin >> q;
        } else {
            q = (int) ((q * 1LL * aa + bb) % cc);
        }
        int id = (int) (lower_bound(ws.begin(), ws.end(), q) - ws.begin());
        long long res;
        if (ws[id] == q) {
            res = a[id];
        } else {
            res = a[id - 1];
            assert((a[id] - a[id - 1]) * (q - ws[id - 1]) % (ws[id] - ws[id - 1]) == 0);
            res += (a[id] - a[id - 1]) * (q - ws[id - 1]) / (ws[id] - ws[id - 1]);
        }
        // debug(q, res);
        ans ^= res;
    }
    cout << ans << '\n';
    return 0;
}