#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, mod = 1e9 + 7;

struct dsu {
    int p[maxn << 1], sz[maxn << 1];
    void init() {
        for (int i = 0; i < maxn << 1; ++i) {
            p[i] = i; sz[i] = 1;
        }
    }
    int find(int x) {
        if (x == p[x]) return x;
        return p[x] = find(p[x]);
    }
    void merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return;
        if (sz[x] > sz[y]) swap(x, y);
        p[x] = y; sz[y] += sz[x];
    }
} dsu;

bool v[maxn << 1];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    dsu.init();
    for (int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        if (c == 1) {
            if (dsu.find(a << 1) == dsu.find(b << 1 | 1)) return cout << "0" << endl, 0;
            if (dsu.find(b << 1) == dsu.find(a << 1 | 1)) return cout << "0" << endl, 0;
            dsu.merge(a << 1, b << 1); dsu.merge(a << 1 | 1, b << 1 | 1); 
        } else {
            if (dsu.find(a << 1) == dsu.find(b << 1)) return cout << "0" << endl, 0;
            if (dsu.find(a << 1 | 1) == dsu.find(b << 1 | 1)) return cout << "0" << endl, 0;
            dsu.merge(a << 1, b << 1 | 1); dsu.merge(a << 1 | 1, b << 1);
        }
    }
    int cc = 0;
    for (int i = 1; i <= 2 * n; ++i) {
        if (!v[dsu.find(i)]) ++cc, v[dsu.find(i)] = true;
    }
    cc = cc / 2 - 1;
    int ans = 1;
    while (cc--) {
        ans = ans * 1ll * 2 % mod;
    }
    cout << ans << endl;
    return 0;
}