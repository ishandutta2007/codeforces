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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                continue;
            }
            for (int j = i + 1; j < n; j++) {
                if (s[j] == '1') {
                    continue;
                }
                int t = j - i - 1;
                if (t < 2) {
                    ans += 2 - t;
                }
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}