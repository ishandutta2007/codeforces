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
        string s;
        cin >> s;
        int ans = 10;
        for (int mask = 0; mask < (1 << 10); mask++) {
            int ok = 1;
            for (int i = 0; i < 10; i++) {
                if (mask & (1 << i)) {
                    if (s[i] == '0') {
                        ok = 0;
                    }
                } else {
                    if (s[i] == '1') {
                        ok = 0;
                    }
                }
            }
            if (!ok) {
                continue;
            }
            int a = 0, b = 0;
            for (int i = 0; i < 10; i++) {
                if (mask & (1 << i)) {
                    if (i % 2 == 0) {
                        a++;
                    } else {
                        b++;
                    }
                }
                if (a + (9 - i) / 2 < b || b + (10 - i) / 2 < a) {
                    ans = min(ans, i + 1);
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}