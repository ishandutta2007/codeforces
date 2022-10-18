#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> up(21, vector<int>(500001));
    rep(i, 0, n) {
        int l, r;
        cin >> l >> r;
        up[0][l] = max(up[0][l], r);
    }
    rep(i, 1, 500001) {
        up[0][i] = max({up[0][i], up[0][i - 1], i});
    }
    rep(j, 0, 20) rep(i, 0, 500001) {
        up[j + 1][i] = up[j][up[j][i]];
    }

    while (m--) {
        int x, y;
        cin >> x >> y;
        int ans = 0;
        for (int j = 19; j >= 0; j--) {
            if (up[j][x] < y) {
                x = up[j][x];
                ans += 1 << j;
            }
        }
        if (up[0][x] >= y)
            cout << ans + 1 << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}