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
    const int m = (int) 2e5 + 10;
    vector<vector<int>> a(20, vector<int>(m));
    for (int i = 0; i < 20; i++) {
        for (int j = 1; j < m; j++) {
            a[i][j] = a[i][j - 1];
            if (j & (1 << i)) {
                a[i][j]++;
            }
        }
    }
    int tt;
    cin >> tt;
    while (tt--) {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for (int i = 0; i < 20; i++) {
            ans = max(ans, a[i][r] - a[i][l - 1]);
        }
        ans = r - l + 1 - ans;
        cout << ans << '\n';
    }
    return 0;
}