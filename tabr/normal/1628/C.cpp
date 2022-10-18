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
        vector<vector<int>> a(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        vector<vector<int>> b(n, vector<int>(n));
        vector<int> di = {1, 0, -1, 0};
        vector<int> dj = {0, 1, 0, -1};
        int ans = 0;
        auto flip = [&](int i, int j) {
            debug(i, j);
            ans ^= a[i][j];
            for (int dir = 0; dir < 4; dir++) {
                int ni = i + di[dir];
                int nj = j + dj[dir];
                if (min(ni, nj) >= 0 && max(ni, nj) < n) {
                    b[ni][nj] ^= 1;
                }
            }
        };
        for (int i = 0; i < n; i++) {
            flip(0, i);
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n; j++) {
                if (!b[i][j]) {
                    flip(i + 1, j);
                }
            }
        }
        debug(b.back());
        cout << ans << '\n';
    }
    return 0;
}