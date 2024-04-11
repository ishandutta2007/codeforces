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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }
    vector<int> a(w);
    for (int j = 0; j < w - 1; j++) {
        for (int i = 0; i < h - 1; i++) {
            if (s[i + 1][j] == 'X' && s[i][j + 1] == 'X') {
                a[j + 1] = 1;
            }
        }
        a[j + 1] += a[j];
    }
    int tt;
    cin >> tt;
    while (tt--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (a[y] - a[x]) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }
    }
    return 0;
}