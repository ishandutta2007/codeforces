#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

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
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        int best = 1, l = 0, r = 0;
        map<int, vector<int>> at;
        for (int i = 0; i < n; i++) {
            at[x[i]].emplace_back(i);
        }
        fenwick<int> f(n);
        for (int i = 0; i < n; i++) {
            f.add(i, -1);
        }
        for (auto [key, val] : at) {
            for (int i : val) {
                f.add(i, 2);
            }
            int mn = (int) 1e9;
            int pos = n;
            for (int i : val) {
                int t = f.get(i);
                if (t < mn) {
                    mn = t;
                    pos = i;
                }
                if (t - mn + 1 > best) {
                    best = t - mn + 1;
                    l = pos;
                    r = i;
                }
            }
            for (int i : val) {
                f.add(i, -2);
            }
        }
        cout << x[l] << " " << l + 1 << " " << r + 1 << '\n';
    }
    return 0;
}