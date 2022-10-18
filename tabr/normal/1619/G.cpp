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
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> x(n), y(n), z(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i] >> z[i];
        }
        dsu uf(n);
        for (int loop = 0; loop < 2; loop++) {
            vector<int> order(n);
            iota(order.begin(), order.end(), 0);
            sort(order.begin(), order.end(), [&](int i, int j) { return (x[i] == x[j] ? y[i] < y[j] : x[i] < x[j]); });
            int beg = 0;
            while (beg < n) {
                int end = beg;
                while (end < n && x[order[beg]] == x[order[end]]) {
                    end++;
                }
                for (int i = beg; i + 1 < end; i++) {
                    if (y[order[i + 1]] - y[order[i]] <= k) {
                        uf.unite(order[i], order[i + 1]);
                    }
                }
                beg = end;
            }
            swap(x, y);
        }
        int inf = (int) 2e9;
        vector<int> c(n, inf);
        for (int i = 0; i < n; i++) {
            c[uf.get(i)] = min(c[uf.get(i)], z[i]);
        }
        sort(c.begin(), c.end());
        while (c.back() == inf) {
            c.pop_back();
        }
        int lo = -1;
        int hi = n + 10;
        while (hi - lo > 1) {
            int mid = (hi + lo) / 2;
            int e = 0;
            for (auto i : c) {
                if (i > mid) {
                    e++;
                }
            }
            if (e > mid + 1) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        cout << hi << '\n';
    }
    return 0;
}