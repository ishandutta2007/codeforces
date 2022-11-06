#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("avx,tune=native")
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-function"
#include <bits/stdc++.h>
using namespace std;

const int maxn = 500, maxm = 1e4 + 5;

struct djset {
    int p[maxn], c;
    void init(int n) { for (int i = 0; i < n; ++i) p[i] = i; c = n; }
    void init(int n, const djset &rhs) { for (int i = 0; i < n; ++i) p[i] = rhs.p[i]; c = rhs.c; }
    int find(int u) { return u == p[u] ? u : p[u] = find(p[u]); }
    void merge(int u, int v) { if (find(u) != find(v)) p[find(u)] = find(v), --c; }
} djs[2][maxm];

int a[2][maxm];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    djs[0][0].init(n);
    for (int i = 1; i <= m; ++i) {
        cin >> a[0][i] >> a[1][i]; --a[0][i]; --a[1][i];
        djs[0][i].init(n, djs[0][i - 1]);
        djs[0][i].merge(a[0][i], a[1][i]);
    }
    djs[1][m + 1].init(n);
    for (int i = m; i >= 1; --i) {
        djs[1][i].init(n, djs[1][i + 1]);
        djs[1][i].merge(a[0][i], a[1][i]);
    }
    int q; cin >> q; while (q--) {
        int l, r; cin >> l >> r;
        djset nd; nd.init(n, djs[0][l - 1]);
        for (int i = 0; i < n; ++i) nd.merge(i, djs[1][r + 1].find(i));
        cout << nd.c << endl;
    }
    return 0;
}