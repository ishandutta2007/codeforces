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
        for (int i = n / 2 - 1; i >= 0; i--) {
            if (s[i] == s[n / 2]) {
                ans++;
            } else {
                break;
            }
        }
        for (int i = n / 2; i < n; i++) {
            if (s[i] == s[n / 2]) {
                ans++;
            } else {
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}