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
        int m;
        cin >> m;
        vector<vector<int>> a(2, vector<int>(m));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        int ans = (int) 2e9;
        int x = 0, y = accumulate(a[0].begin(), a[0].end(), 0);
        for (int i = 0; i < m; i++) {
            y -= a[0][i];
            ans = min(ans, max(x, y));
            x += a[1][i];
        }
        cout << ans << '\n';
    }
    return 0;
}