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
        int n = (int) s.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                continue;
            }
            if (i % 2 == 1) {
                s[i] ^= '0' ^ '1';
            }
        }
        vector<vector<int>> a(n + 1, vector<int>(2, n));
        for (int i = n - 1; i >= 0; i--) {
            a[i] = a[i + 1];
            if (s[i] == '?') {
                continue;
            } else {
                a[i][s[i] - '0'] = i;
            }
        }
        for (int i = 0; i < n; i++) {
            ans += max(a[i][0], a[i][1]) - i;
        }
        cout << ans << '\n';
    }
    return 0;
}