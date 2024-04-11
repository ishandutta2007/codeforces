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
        vector<string> s(8);
        for (int i = 0; i < 8; i++) {
            cin >> s[i];
        }
        bool found = false;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                vector<string> t(8, string(8, '.'));
                for (int x = 0; x < 8; x++) {
                    for (int y = 0; y < 8; y++) {
                        if (i + j == x + y || i - j == x - y) {
                            t[x][y] = '#';
                        }
                    }
                }
                if (s == t) {
                    cout << i + 1 << " " << j + 1 << '\n';
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
    }
    return 0;
}