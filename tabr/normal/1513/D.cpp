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
        int p;
        cin >> p;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        dsu uf(n);
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int i, int j) { return a[i] < a[j]; });
        long long ans = 0;
        for (int i : order) {
            if (p < a[i]) {
                break;
            }
            int j = i;
            while (j && a[j - 1] % a[i] == 0) {
                j--;
                if (!uf.unite(i, j)) {
                    break;
                }
                ans += a[i];
            }
            int k = i;
            while (k < n - 1 && a[k + 1] % a[i] == 0) {
                k++;
                if (!uf.unite(i, k)) {
                    break;
                }
                ans += a[i];
            }
        }
        ans -= p;
        for (int i = 0; i < n; i++) {
            if (i == uf.get(i)) {
                ans += p;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}