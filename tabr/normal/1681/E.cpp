#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct segtree {
    using T = vector<vector<long long>>;

    T e() {
        vector<vector<long long>> a(2, vector<long long>(2, (long long) 1e18));
        a[0][0] = a[1][1] = 0;
        return a;
    }

    T op(T x, T y) {
        vector<vector<long long>> z(2, vector<long long>(2, (long long) 1e18));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    z[i][k] = min(z[i][k], x[i][j] + y[j][k]);
                }
            }
        }
        return z;
    }

    int n;
    int size;
    vector<T> node;

    segtree() : segtree(0) {}
    segtree(int _n) {
        build(vector<T>(_n, e()));
    }
    segtree(const vector<T> &v) {
        build(v);
    }

    void build(const vector<T> &v) {
        n = (int) v.size();
        if (n <= 1) {
            size = n;
        } else {
            size = 1 << (32 - __builtin_clz(n - 1));
        }
        node.resize(2 * size, e());
        for (int i = 0; i < n; i++) {
            node[i + size] = v[i];
        }
        for (int i = size - 1; i > 0; i--) {
            node[i] = op(node[2 * i], node[2 * i + 1]);
        }
    }

    void set(int p, T v) {
        assert(0 <= p && p < n);
        p += size;
        node[p] = v;  // update
        // node[p] += v;  // add
        while (p > 1) {
            p >>= 1;
            node[p] = op(node[2 * p], node[2 * p + 1]);
        }
    }

    T get(int l, int r) {
        assert(0 <= l && l <= r && r <= n);
        T vl = e();
        T vr = e();
        l += size;
        r += size;
        while (l < r) {
            if (l & 1) {
                vl = op(vl, node[l++]);
            }
            if (r & 1) {
                vr = op(node[--r], vr);
            }
            l >>= 1;
            r >>= 1;
        }
        return op(vl, vr);
    }

    T get(int p) {
        assert(0 <= p && p < n);
        return node[p + size];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> d(n - 1, vector<int>(4));
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> d[i][j];
            d[i][j]--;
        }
    }
    auto Dist = [&](int x1, int y1, int x2, int y2) {
        debug(x1, y1, x2, y2);
        assert(max(x1, y1) == max(x2, y2));
        return abs(x1 - x2) + abs(y1 - y2);
    };
    vector<vector<vector<long long>>> a(n - 2, vector<vector<long long>>(2, vector<long long>(2)));
    for (int k = 0; k + 1 < n - 1; k++) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                a[k][i][j] = 1 + Dist(d[k][i * 2] + (i == 0), d[k][i * 2 + 1] + (i == 1), d[k + 1][2 * j], d[k + 1][2 * j + 1]);
            }
        }
    }
    segtree seg(a);
    int q;
    cin >> q;
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        int z1 = max(x1, y1);
        int z2 = max(x2, y2);
        if (z1 > z2) {
            swap(x1, x2);
            swap(y1, y2);
            swap(z1, z2);
        }
        debug(x1, y1, x2, y2, z1, z2);
        if (z1 == z2) {
            cout << Dist(x1, y1, x2, y2) << '\n';
        } else {
            auto b = seg.get(z1, z2 - 1);
            long long ans = (long long) 1e18;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    ans = min(ans, 1 + b[i][j] + Dist(x1, y1, d[z1][i * 2], d[z1][i * 2 + 1]) + Dist(x2, y2, d[z2 - 1][j * 2] + (j == 0), d[z2 - 1][j * 2 + 1] + (j == 1)));
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}