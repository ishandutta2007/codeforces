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
        if (x > y) {
            return 0;
        }
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
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<vector<int>> g(n);
        for (int i = 1; i < n; i++) {
            int j;
            cin >> j;
            j--;
            g[j].emplace_back(i);
        }
        vector<vector<tuple<int, int, int>>> que(n);
        for (int i = 0; i < q; i++) {
            int v, l, k;
            cin >> v >> l >> k;
            v--;
            que[v].emplace_back(l, k, i);
        }
        vector<int> b(n + 1);
        vector<unordered_set<int>> st(n + 10);
        fenwick<int> f(n + 10);
        for (int i = 1; i <= n; i++) {
            st[0].emplace(i);
        }
        f.add(0, n);
        vector<int> ans(q);
        auto dfs = [&](auto &&self, int v) -> void {
            st[b[a[v]]].erase(a[v]);
            f.add(b[a[v]], -1);
            b[a[v]]++;
            st[b[a[v]]].emplace(a[v]);
            f.add(b[a[v]], 1);
            for (int to : g[v]) {
                self(self, to);
            }
            for (auto [l, k, id] : que[v]) {
                int cnt = f.get(l, n + 2);
                if (cnt < k) {
                    ans[id] = -1;
                    continue;
                }
                int pos = f.lower_bound(k + f.get(0, l - 1));
                ans[id] = *st[pos].begin();
            }
            st[b[a[v]]].erase(a[v]);
            f.add(b[a[v]], -1);
            b[a[v]]--;
            st[b[a[v]]].emplace(a[v]);
            f.add(b[a[v]], 1);
        };
        dfs(dfs, 0);
        for (int i : ans) {
            cout << i << " ";
        }
        cout << '\n';
    }
    return 0;
}