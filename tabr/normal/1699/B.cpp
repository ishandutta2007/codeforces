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
        vector<vector<int>> a(h + 1, vector<int>(w + 1));
        for (int i = 0; i < h + 1; i++) {
            for (int j = 0; j < w + 1; j++) {
                a[i][j] = i / 2 % 2 == j / 2 % 2;
            }
        }
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cout << a[i][j] << " \n"[j == w];
            }
        }
    }
    return 0;
}