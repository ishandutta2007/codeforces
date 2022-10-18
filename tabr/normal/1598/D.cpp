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
        int n;
        cin >> n;
        vector<pair<int, int>> p(n);
        vector<int> x(n), y(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i].first >> p[i].second;
            p[i].first--, p[i].second--;
            x[p[i].first]++;
            y[p[i].second]++;
        }
        long long ans = 1LL * n * (n - 1) * (n - 2) / 6;
        for (int i = 0; i < n; i++) {
            ans -= 1LL * (x[p[i].first] - 1) * (y[p[i].second] - 1);
        }
        cout << ans << '\n';
    }
    return 0;
}