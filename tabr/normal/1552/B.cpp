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
        vector<vector<int>> a(n, vector<int>(5));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> a[i][j];
            }
        }
        vector<int> b(n);
        iota(b.begin(), b.end(), 0);
        sort(b.begin(), b.end(), [&](int x, int y) {
            int c = 0;
            for (int i = 0; i < 5; i++) {
                if (a[x][i] < a[y][i]) {
                    c++;
                }
            }
            return c >= 3;
        });
        int ans = b[0];
        for (int i = 0; i < n; i++) {
            if (i == ans) {
                continue;
            }
            int c = 0;
            for (int j = 0; j < 5; j++) {
                if (a[ans][j] < a[i][j]) {
                    c++;
                }
            }
            if (c < 3) {
                ans = -2;
                break;
            }
        }
        cout << ans + 1 << '\n';
    }
    return 0;
}