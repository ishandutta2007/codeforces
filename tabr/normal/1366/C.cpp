#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
        int h, w;
        cin >> h >> w;
        vector<vector<int>> a(h, vector<int>(w));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> a[i][j];
            }
        }
        int ans = 0;
        for (int d = 0; d < h + w - 2; d++) {
            if (d >= h + w - d - 2) {
                break;
            }
            vector<int> c(2);
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (i + j == d || i + j == (h + w - 2 - d)) {
                        c[a[i][j]]++;
                    }
                }
            }
            ans += min(c[0], c[1]);
        }
        cout << ans << '\n';
    }
    return 0;
}