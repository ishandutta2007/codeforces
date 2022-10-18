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
        int n, q;
        cin >> n >> q;
        vector<vector<long long>> a(1010, vector<long long>(1010));
        for (int i = 0; i < n; i++) {
            int h, w;
            cin >> h >> w;
            a[h][w] += h * w;
        }
        for (int i = 0; i < 1005; i++) {
            for (int j = 0; j < 1005; j++) {
                a[i + 1][j] += a[i][j];
            }
        }
        for (int i = 0; i < 1005; i++) {
            for (int j = 0; j < 1005; j++) {
                a[i][j + 1] += a[i][j];
            }
        }
        for (int i = 0; i < q; i++) {
            int h1, w1, h2, w2;
            cin >> h1 >> w1 >> h2 >> w2;
            h2--, w2--;
            cout << a[h2][w2] - a[h2][w1] - a[h1][w2] + a[h1][w1] << '\n';
        }
    }
    return 0;
}