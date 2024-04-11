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
        int h, w;
        cin >> h >> w;
        vector<vector<int>> a(h, vector<int>(w));
        int b = (int) -2e9;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> a[i][j];
                b = max(b, a[i][j]);
            }
        }
        int ans = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (a[i][j] == b) {
                    ans = max(i + 1, h - i) * max(j + 1, w - j);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}