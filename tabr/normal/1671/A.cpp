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
        string ans = "YES";
        for (int i = 0; i < n; i++) {
            int t = 0;
            if (i > 0 && s[i - 1] == s[i]) {
                t++;
            }
            if (i + 1 < n && s[i + 1] == s[i]) {
                t++;
            }
            if (t == 0) {
                ans = "NO";
            }
        }
        cout << ans << '\n';
    }
    return 0;
}