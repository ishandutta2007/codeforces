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
        vector<vector<int>> b(h, vector<int>(w, 4));
        string ans = "YES";
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> a[i][j];
                if (i == 0 || i == h - 1) {
                    b[i][j]--;
                }
                if (j == 0 || j == w - 1) {
                    b[i][j]--;
                }
                if (a[i][j] > b[i][j]) {
                    ans = "NO";
                }
            }
        }
        if (ans == "NO") {
            cout << "NO" << '\n';
        } else {
            cout << ans << '\n';
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    cout << b[i][j] << " ";
                }
                cout << '\n';
            }
        }
    }
    return 0;
}