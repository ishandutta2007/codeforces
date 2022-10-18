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
        string s;
        cin >> s;
        string ans;
        vector<int> a(26);
        iota(a.begin(), a.end(), 0);
        vector<int> b(26);
        dsu uf(26);
        for (int i = 0; i < n; i++) {
            int j = s[i] - 'a';
            if (a[j] == j) {
                for (int k = 0; k < 26; k++) {
                    if (j == k || b[k] || uf.same(j, k)) {
                        continue;
                    }
                    b[k] = 1;
                    a[j] = k;
                    uf.unite(j, k);
                    break;
                }
                if (a[j] == j) {
                    for (int k = 0; k < 26; k++) {
                        if (!b[k]) {
                            a[j] = k;
                        }
                    }
                }
            }
            ans += (char) ('a' + a[j]);
        }
        cout << ans << '\n';
    }
    return 0;
}