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
        int n;
        cin >> n;
        vector<vector<long long>> c(2 * n, vector<long long>(2 * n));
        for (int i = 0; i < 2 * n; i++) {
            for (int j = 0; j < 2 * n; j++) {
                cin >> c[i][j];
            }
        }
        long long ans = (long long) 1e18;
        for (int z = 0; z < 2; z++) {
            ans = min(ans, c[0][n]);
            ans = min(ans, c[0][2 * n - 1]);
            ans = min(ans, c[n - 1][n]);
            ans = min(ans, c[n - 1][2 * n - 1]);
            for (int i = 0; i < 2 * n; i++) {
                for (int j = i + 1; j < 2 * n; j++) {
                    swap(c[i][j], c[j][i]);
                }
            }
        }
        for (int i = n; i < 2 * n; i++) {
            for (int j = n; j < 2 * n; j++) {
                ans += c[i][j];
                c[i][j] = 0;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}