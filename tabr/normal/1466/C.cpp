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
        int n = (int)s.size();
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (s[i - 1] == s[i]) {
                s[i] = '.';
                ans++;
            } else if (i > 1 && s[i - 2] == s[i]) {
                s[i] = '.';
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}