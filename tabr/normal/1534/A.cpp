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
        int r = -1;
        for (int i = 0; i < h; i++) {
            cin >> s[i];
            for (int j = 0; j < w; j++) {
                if (s[i][j] == 'R') {
                    if (r == -1) {
                        r = (i + j) % 2;
                    } else if (r != (i + j) % 2) {
                        r = -2;
                    }
                } else if (s[i][j] == 'W') {
                    if (r == -1) {
                        r = (i + j + 1) % 2;
                    } else if (r == (i + j) % 2) {
                        r = -2;
                    }
                }
            }
        }
        if (r == -2) {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        if (r == -1) {
            r = 0;
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if ((i + j) % 2 == r) {
                    s[i][j] = 'R';
                } else {
                    s[i][j] = 'W';
                }
            }
            cout << s[i] << '\n';
        }
    }
    return 0;
}