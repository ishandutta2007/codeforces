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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set<int> st;
    st.emplace(0);
    st.emplace(n);
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            st.emplace(i + 1);
        }
    }
    fenwick<long long> ft(n + 1);
    vector<long long> c(n + 1);
    auto f = [&](int x) {
        return 1LL * x * (x + 1) / 2;
    };
    auto add = [&](int x) {
        st.emplace(x);
        int y = *prev(st.find(x));
        ft.add(y, -c[y]);
        c[x] = f(*next(st.find(x)) - x);
        c[y] = f(x - y);
        ft.add(x, c[x]);
        ft.add(y, c[y]);
    };
    auto erase = [&](int x) {
        int y = *prev(st.find(x));
        ft.add(y, -c[y]);
        ft.add(x, -c[x]);
        c[x] = 0;
        c[y] = f(*next(st.find(x)) - y);
        ft.add(y, c[y]);
        st.erase(x);
    };
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            add(i + 1);
        }
    }
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            x--;
            if (x != 0) {
                if (a[x - 1] <= a[x] && a[x - 1] > y) {
                    add(x);
                } else if (a[x - 1] > a[x] && a[x - 1] <= y) {
                    erase(x);
                }
            }
            if (x != n - 1) {
                if (a[x] <= a[x + 1] && y > a[x + 1]) {
                    add(x + 1);
                } else if (a[x] > a[x + 1] && y <= a[x + 1]) {
                    erase(x + 1);
                }
            }
            a[x] = y;
        } else {
            x--, y--;
            long long ans = ft.get(x, y);
            int xx = *st.lower_bound(x);
            int yy = *prev(st.upper_bound(y));
            if (xx <= yy) {
                ans -= ft.get(yy, yy);
                ans += f(xx - x);
                ans += f(y - yy + 1);
            } else {
                ans += f(y - x + 1);
            }
            cout << ans << '\n';
        }
    }
    return 0;
}