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
        auto ok = [&](int i, int j) {
            for (int ni = i - 1; ni <= i + 1; ni++) {
                if (ni == -1 || ni == h) {
                    continue;
                }
                for (int nj = j - 1; nj <= j + 1; nj++) {
                    if (nj == -1 || nj == w) {
                        continue;
                    }
                    if (a[ni][nj] == 1) {
                        return false;
                    }
                }
            }
            return true;
        };
        for (int j = 0; j < w; j++) {
            if (ok(0, j)) {
                a[0][j] = 1;
            }
        }
        for (int i = 0; i < h; i++) {
            if (ok(i, w - 1)) {
                a[i][w - 1] = 1;
            }
        }
        for (int j = w - 1; j >= 0; j--) {
            if (ok(h - 1, j)) {
                a[h - 1][j] = 1;
            }
        }
        for (int i = h - 1; i >= 0; i--) {
            if (ok(i, 0)) {
                a[i][0] = 1;
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cout << a[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}