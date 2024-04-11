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
        int cnt = 0;
        for (int i = 0; i < h; i++) {
            cnt += (int) count(s[i].begin(), s[i].end(), '1');
        }
        if (cnt == h * w) {
            cnt -= 2;
        } else {
            int t = 1;
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w - 1; j++) {
                    if (s[i][j] == '0' && s[i][j + 1] == '0') {
                        t = 0;
                    }
                }
            }
            for (int i = 0; i < h - 1; i++) {
                for (int j = 0; j < w; j++) {
                    if (s[i][j] == '0' && s[i + 1][j] == '0') {
                        t = 0;
                    }
                }
            }
            for (int i = 0; i < h - 1; i++) {
                for (int j = 0; j < w - 1; j++) {
                    if (s[i][j] == '0' && s[i + 1][j + 1] == '0') {
                        t = 0;
                    }
                }
            }
            for (int i = 0; i < h - 1; i++) {
                for (int j = 0; j < w - 1; j++) {
                    if (s[i][j + 1] == '0' && s[i + 1][j] == '0') {
                        t = 0;
                    }
                }
            }
            cnt -= t;
        }
        cout << cnt << '\n';
    }
    return 0;
}