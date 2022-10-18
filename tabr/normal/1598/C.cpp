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
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        long long s = accumulate(a.begin(), a.end(), 0LL);
        sort(a.begin(), a.end());
        if ((s * 2) % n != 0) {
            cout << 0 << '\n';
            continue;
        }
        s *= 2;
        s /= n;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (int) (upper_bound(a.begin() + i + 1, a.end(), s - a[i]) - lower_bound(a.begin() + i + 1, a.end(), s - a[i]));
        }
        cout << ans << '\n';
    }
    return 0;
}