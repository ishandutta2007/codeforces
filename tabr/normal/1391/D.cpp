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
    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < w; j++) {
            a[i][j] = s[j] - '0';
        }
    }
    if (h > w) {
        vector<vector<int>> b(w, vector<int>(h));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                b[j][i] = a[i][j];
            }
        }
        swap(a, b);
        swap(h, w);
    }
    if (h == 1) {
        cout << 0 << '\n';
    } else if (h == 2) {
        int x = 0;
        for (int j = 0; j < w; j++) {
            if ((a[0][j] + a[1][j]) % 2 == j % 2) {
                x++;
            }
        }
        cout << min(x, w - x) << '\n';
    } else if (h == 3) {
        vector<int> b(w);
        vector<int> c(4);
        for (int j = 0; j < w; j++) {
            if ((a[0][j] + a[1][j]) % 2 == 1) {
                b[j] += 2;
            }
            if ((a[1][j] + a[2][j]) % 2 == 1) {
                b[j]++;
            }
            if (j % 2 == 1) {
                b[j] ^= 3;
            }
        }
        debug(b);
        for (int j = 0; j < w; j++) {
            for (int k = 0; k < 4; k++) {
                if (k != b[j]) {
                    c[k]++;
                }
            }
        }
        cout << *min_element(c.begin(), c.end()) << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}