#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10;

struct Dsu {
    int par[maxn];
    void init() {
        for (int i = 0; i < maxn; ++i) par[i] = i;
    }
    int find(int x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }
    bool merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        par[x] = y;
        return true;
    }
} dsu;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    if (m != n - 1) return cout << "no" << endl, 0;
    dsu.init();
    while (m--) {
        int a, b; cin >> a >> b;
        if (!dsu.merge(a, b)) return cout << "no" << endl, 0;
    }
    cout << "yes" << endl;
    return 0;
}