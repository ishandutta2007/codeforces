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
    int n;
    cin >> n;
    for (int k = 1; k <= 12; k++) {
        if (k * k < n) {
            continue;
        }
        for (int i = 1; i <= k; i++) {
            int d = 2 * k - 1;
            d += (i - 1) * (i - 1);
            if (d > n) {
                break;
            }
            if ((n - d) % 2 == 1) {
                continue;
            }
            int p = (n - d) / 2;
            if (p > (i - 1) * (k - i)) {
                continue;
            }
            vector<string> s(k, string(k, '.'));
            for (int j = 0; j < k; j++) {
                s[j][0] = s[0][j] = 'o';
            }
            for (int x = 0; x < i; x++) {
                for (int y = 0; y < i; y++) {
                    s[x][y] = 'o';
                }
            }
            while (p--) {
                int ok = 0;
                for (int x = 0; x < k; x++) {
                    for (int y = 0; y < k; y++) {
                        if (s[x][y] == '.') {
                            s[x][y] = s[y][x] = 'o';
                            ok = 1;
                            break;
                        }
                    }
                    if (ok) {
                        break;
                    }
                }
            }
            cout << k << '\n';
            for (int j = k - 1; j >= 0; j--) {
                cout << s[j] << '\n';
            }
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}