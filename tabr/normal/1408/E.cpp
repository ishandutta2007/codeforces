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
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        sz.assign(n, 1);
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
        if (sz[x] > sz[y]) {
            swap(x, y);
        }
        p[x] = y;
        sz[y] += sz[x];
        return true;
    }
    inline bool same(int x, int y) {
        return (get(x) == get(y));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    vector<long long> a(m), b(n);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<pair<int, int>> c;
    for (int i = 0; i < m; i++) {
        int s;
        cin >> s;
        for (int j = 0; j < s; j++) {
            int k;
            cin >> k;
            k--;
            c.emplace_back(i, k);
        }
    }
    sort(c.begin(), c.end(), [&](auto i, auto j) {
        return a[i.first] + b[i.second] > a[j.first] + b[j.second];
    });
    long long ans = 0;
    dsu uf(m);
    vector<vector<int>> d(n);
    for (auto p : c) {
        long long t = 0;
        for (int x : d[p.second]) {
            if (uf.same(x, p.first)) {
                t = a[p.first] + b[p.second];
                break;
            }
        }
        if (!t) {
            for (int x : d[p.second]) {
                uf.unite(x, p.first);
            }
            d[p.second] = {p.first};
        } else {
            ans += t;
        }
    }
    cout << ans << '\n';
    return 0;
}