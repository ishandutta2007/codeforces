#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10, lg = 30;
int p[lg][maxn], d[maxn];

int lca(int a, int b) {
    if (d[a] > d[b]) swap(a, b);
    for (int i = 0; i < lg; ++i) {
        if ((d[b] - d[a]) >> i & 1) b = p[i][b];
    }
    if (a == b) return a;
    for (int i = lg - 1; i >= 0; --i) {
        if (p[i][a] != p[i][b]) {
            a = p[i][a];
            b = p[i][b];
        }
        if (a == b) return a;
    }
    return p[0][a];
}

int dist(int a, int b) {
    return d[a] + d[b] - 2 * d[lca(a, b)];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, fa; cin >> n >> fa;
    int a = 1, b = 2;
    p[0][1] = 0, p[0][2] = 1;
    d[1] = 0; d[2] = 1;
    cout << 1 << ' ';
    for (int i = 3; i <= n; ++i) {
        cin >> fa;
        p[0][i] = fa; d[i] = d[fa] + 1;
        for (int j = 1; ; ++j) {
            if ((1 << j) > d[i]) break;
            p[j][i] = p[j - 1][p[j - 1][i]];
        }
        if (dist(i, a) > dist(b, a)) b = i;
        else if (dist(i, b) > dist(a, b)) a = i;
        cout << dist(a, b) << ' ';
    }
    cout << endl;
    return 0;
}