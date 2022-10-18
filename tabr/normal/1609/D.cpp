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

template <typename T>
struct fenwick {
    int n;
    vector<T> node;

    fenwick(int _n) : n(_n) {
        node.resize(n);
    }

    void add(int x, T v) {
        while (x < n) {
            node[x] += v;
            x |= (x + 1);
        }
    }

    T get(int x) {  // [0, x]
        T v = 0;
        while (x >= 0) {
            v += node[x];
            x = (x & (x + 1)) - 1;
        }
        return v;
    }

    T get(int x, int y) {  // [x, y]
        return (get(y) - (x ? get(x - 1) : 0));
    }

    int lower_bound(T v) {
        int x = 0;
        int h = 1;
        while (n >= (h << 1)) {
            h <<= 1;
        }
        for (int k = h; k > 0; k >>= 1) {
            if (x + k <= n && node[x + k - 1] < v) {
                v -= node[x + k - 1];
                x += k;
            }
        }
        return x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, d;
    cin >> n >> d;
    int ans = 0;
    dsu uf(n);
    fenwick<int> cnt(n + 10);
    fenwick<int> sum(n + 10);
    cnt.add(1, n);
    sum.add(1, n);
    int k = 1;
    for (int i = 0; i < d; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (uf.same(x, y)) {
            k++;
        } else {
            int p = uf.sz[uf.get(x)];
            int q = uf.sz[uf.get(y)];
            cnt.add(p, -1);
            cnt.add(q, -1);
            sum.add(p, -p);
            sum.add(q, -q);
            uf.unite(x, y);
            p = uf.sz[uf.get(x)];
            cnt.add(p, 1);
            sum.add(p, p);
        }
        if (cnt.get(0, n + 1) < k) {
            ans = n;
        } else {
            int lo = 0;
            int hi = n + 1;
            while (hi - lo > 1) {
                int mid = (hi + lo) / 2;
                if (cnt.get(mid, n + 1) < k) {
                    hi = mid;
                } else {
                    lo = mid;
                }
            }
            debug(lo, k, cnt.get(lo + 1, n + 1));
            int t = sum.get(lo + 1, n + 1) + (k - cnt.get(lo + 1, n + 1)) * lo;
            ans = max(ans, t);
        }
        cout << ans - 1 << '\n';
    }
    return 0;
}