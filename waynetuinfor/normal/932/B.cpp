#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int f[maxn], p[10][maxn];

int dfs(int now) {
    if (now < 10) return now;
    int to = 1;
    while (now) {
        if (now % 10 != 0) to *= (now % 10);
        now /= 10;
    }
    return dfs(to);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    for (int i = 1; i < maxn; ++i) f[i] = dfs(i);
    for (int i = 1; i < maxn; ++i) {
        for (int j = 0; j < 10; ++j) p[j][i] = p[j][i - 1];
        ++p[f[i]][i];
    }
    int q; cin >> q; while (q--) {
        int l, r, k; cin >> l >> r >> k;
        cout << p[k][r] - p[k][l - 1] << endl;
    }
    return 0;
}