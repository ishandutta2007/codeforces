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
        vector<string> s(h);
        for (int i = 0; i < h; i++) {
            cin >> s[i];
        }
        for (int i = 0; i < h; i += 3) {
            for (int j = 0; j < w; j++) {
                s[i][j] = 'X';
            }
            if (i == h - 1 || i == h - 2) {
                break;
            } else if (i == h - 3) {
                for (int j = 0; j < w; j++) {
                    if (s[i + 2][j] == 'X') {
                        s[i + 1][j] = 'X';
                    }
                }
                break;
            }
            for (int j = 0; j < w; j++) {
                if (s[i + 1][j] == 'X' || s[i + 2][j] == 'X') {
                    s[i + 1][j] = s[i + 2][j] = 'X';
                    break;
                } else if (j == w - 1) {
                    s[i + 1][w - 1] = s[i + 2][w - 1] = 'X';
                }
            }
        }
        for (int i = 0; i < h; i++) {
            cout << s[i] << '\n';
        }
    }
    return 0;
}