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
        vector<vector<tuple<int, int, int>>> a(n);
        vector<int> z;
        for (int i = 0; i < n; i++) {
            int l, r, c;
            cin >> l >> r >> c;
            c--;
            a[c].emplace_back(l, r, i);
            z.emplace_back(l);
            z.emplace_back(r);
        }
        sort(z.begin(), z.end());
        z.resize(unique(z.begin(), z.end()) - z.begin());
        fenwick<int> f((int) z.size() + 2);
        multiset<int> st;
        for (int i = 0; i < n; i++) {
            for (auto [l, r, id] : a[i]) {
                st.emplace(l);
                st.emplace(r);
                l = (int) (lower_bound(z.begin(), z.end(), l) - z.begin());
                r = (int) (lower_bound(z.begin(), z.end(), r) - z.begin());
                f.add(l, 1);
                f.add(r + 1, -1);
            }
        }
        vector<int> ans(n);
        st.emplace((int) 2e9);
        st.emplace((int) -1e9);
        for (int i = 0; i < n; i++) {
            for (auto [l, r, id] : a[i]) {
                st.erase(st.find(l));
                st.erase(st.find(r));
                l = (int) (lower_bound(z.begin(), z.end(), l) - z.begin());
                r = (int) (lower_bound(z.begin(), z.end(), r) - z.begin());
                f.add(l, -1);
                f.add(r + 1, 1);
            }
            for (auto [l, r, id] : a[i]) {
                int ll = (int) (lower_bound(z.begin(), z.end(), l) - z.begin());
                int rr = (int) (lower_bound(z.begin(), z.end(), r) - z.begin());
                if (f.get(ll) != 0 || f.get(rr) != 0) {
                    continue;
                }
                debug(id);
                if (*st.lower_bound(l) <= r) {
                    continue;
                }
                ans[id] = (int) 2e9;
                ans[id] = min(ans[id], *st.lower_bound(r) - r);
                ans[id] = min(ans[id], l - *prev(st.upper_bound(l)));
            }
            for (auto [l, r, id] : a[i]) {
                st.emplace(l);
                st.emplace(r);
                l = (int) (lower_bound(z.begin(), z.end(), l) - z.begin());
                r = (int) (lower_bound(z.begin(), z.end(), r) - z.begin());
                f.add(l, 1);
                f.add(r + 1, -1);
            }
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}