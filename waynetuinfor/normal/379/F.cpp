#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int dep[maxn], p[22][maxn];

int lca(int a, int b) {
    if (dep[a] > dep[b]) swap(a, b);
    for (int i = 0; i < 22; ++i) {
        if ((dep[b] - dep[a]) >> i & 1) b = p[i][b];
    }
    if (a == b) return a;
    for (int i = 21; i >= 0; --i) {
        if (p[i][a] != p[i][b]) {
            a = p[i][a];
            b = p[i][b];
        }
        if (a == b) return a;
    }
    return p[0][a];
}

int dis(int a, int b) {
    return dep[a] + dep[b] - 2 * dep[lca(a, b)];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    p[0][1] = 0;
    p[0][2] = 1; p[0][3] = 1; p[0][4] = 1;
    dep[1] = 0; dep[2] = dep[3] = dep[4] = 1;
    int a = 2, b = 3;
    int n = 4;
    int cur = 2;
    int q; cin >> q; while (q--) {
        int v; cin >> v;
        for (int i = 1; i <= 2; ++i) {
            dep[n + i] = dep[v] + 1;
            p[0][n + i] = v;
            for (int k = 1; k < 22; ++k) {
                if ((1 << k) > dep[n + i]) break;
                p[k][n + i] = p[k - 1][p[k - 1][n + i]];
            }
            int aa = dis(n + i, a), bb = dis(n + i, b);
            if (aa > cur) cur = aa, b = n + i;
            else if (bb > cur) cur = bb, a = n + i;
        }
        n += 2;
        cout << cur << endl;
    }
    return 0;
}