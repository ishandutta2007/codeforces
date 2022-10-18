#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<int> x(m), y(m), z(m);
        vector<vector<int>> d(n, vector<int>(n, (int) 1e9));
        for (int i = 0; i < m; i++) {
            cin >> x[i] >> y[i] >> z[i];
            x[i]--;
            y[i]--;
            d[x[i]][y[i]] = d[y[i]][x[i]] = 1;
        }
        for (int i = 0; i < n; i++) {
            d[i][i] = 0;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        long long ans = (long long) 1e18;
        for (int i = 0; i < m; i++) {
            int f = min(d[x[i]][0] + d[y[i]][n - 1], d[y[i]][0] + d[x[i]][n - 1]);
            for (int j = 0; j < n; j++) {
                f = min(f, d[x[i]][j] + 1 + d[j][n - 1] + d[j][0]);
                f = min(f, d[y[i]][j] + 1 + d[j][n - 1] + d[j][0]);
            }
            f++;
            ans = min(ans, f * 1LL * z[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}