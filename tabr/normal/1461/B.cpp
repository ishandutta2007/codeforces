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
        vector<string> s(h + 2);
        for (int i = 1; i <= h; i++) {
            cin >> s[i];
            s[i] = "." + s[i] + ".";
        }
        s[0] = s[h + 1] = string(w + 2, '.');
        vector<vector<int>> a(h + 2, vector<int>(w + 2));
        int ans = 0;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                if (s[i][j] == '*') {
                    a[i][j] = 1;
                    ans++;
                }
            }
        }
        while (true) {
            int add = 0;
            vector<vector<int>> b(h + 2, vector<int>(w + 2));
            for (int i = 1; i <= h; i++) {
                for (int j = 1; j <= w; j++) {
                    if (a[i][j] && a[i + 1][j - 1] && a[i + 1][j] && a[i + 1][j + 1]) {
                        b[i][j] = 1;
                        add++;
                    }
                }
            }
            if (add) {
                swap(a, b);
                ans += add;
                continue;
            }
            break;
        }
        cout << ans << '\n';
    }
    return 0;
}