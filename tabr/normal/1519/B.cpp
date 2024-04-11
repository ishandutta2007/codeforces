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
        int h, w, k;
        cin >> h >> w >> k;
        vector<vector<int>> a(h, vector<int>(w));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (i != h - 1) {
                    a[i + 1][j] = a[i][j] + j + 1;
                }
                if (j != w - 1) {
                    a[i][j + 1] = a[i][j] + i + 1;
                }
            }
        }
        if (k == a[h - 1][w - 1]) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}