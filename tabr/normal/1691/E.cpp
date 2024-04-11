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
        vector<tuple<int, int, int, int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> get<2>(a[i]) >> get<1>(a[i]) >> get<0>(a[i]);
            get<3>(a[i]) = i;
        }
        sort(a.begin(), a.end());
        dsu uf(n);
        vector<stack<pair<int, int>>> s(2);
        s[0].emplace(-1, -1);
        s[1].emplace(-1, -1);
        for (int i = 0; i < n; i++) {
            auto [r, l, c, id] = a[i];
            auto t = s[c ^ 1].top();
            while (!s[c ^ 1].empty() && s[c ^ 1].top().second >= l) {
                uf.unite(id, s[c ^ 1].top().first);
                s[c ^ 1].pop();
            }
            if (s[c ^ 1].top() != t) {
                s[c ^ 1].emplace(t);
            }
            s[c].emplace(id, r);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += uf.root(i);
        }
        cout << ans << '\n';
    }
    return 0;
}