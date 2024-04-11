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
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    for (int i = 0; i < h; i++) {
        cin >> a[i];
    }
    vector<vector<int>> c(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        int cur = 0;
        for (int j = 1; j < w; j++) {
            if (a[i][j] == a[i][j - 1]) {
                cur++;
            } else {
                cur = 0;
            }
            c[i][j] = cur;
        }
        cur = 0;
        c[i][w - 1] = 0;
        for (int j = w - 2; j >= 0; j--) {
            if (a[i][j] == a[i][j + 1]) {
                cur++;
            } else {
                cur = 0;
            }
            c[i][j] = min(c[i][j], cur);
        }
    }
    vector<vector<int>> d(h, vector<int>(w));
    for (int j = 0; j < w; j++) {
        int cur = 0;
        for (int i = 1; i < h - 1; i++) {
            if (a[i][j] == a[i - 1][j]) {
                cur++;
            } else {
                cur = 0;
            }
            cur = min(cur, c[i][j]);
            d[i][j] = cur;
        }
        cur = 0;
        for (int i = h - 2; i >= 1; i--) {
            if (a[i][j] == a[i + 1][j]) {
                cur++;
            } else {
                cur = 0;
            }
            cur = min(cur, c[i][j]);
            d[i][j] = min(d[i][j], cur);
        }
    }
    ll ans = h * w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            ans += d[i][j];
        }
    }
    cout << ans << '\n';
    return 0;
}