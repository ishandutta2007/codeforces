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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
        }
        dsu uf(n);
        set<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && *st.rbegin() > a[i]) {
                int b = uf.get(a[i]);
                int c = *st.rbegin();
                if (b > c) {
                    swap(b, c);
                }
                uf.unite(b, c);
                st.erase(*st.rbegin());
            }
            st.emplace(uf.get(a[i]));
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (uf.root(i)) {
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}