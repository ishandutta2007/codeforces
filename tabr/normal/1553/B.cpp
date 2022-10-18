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
        string t;
        cin >> t;
        string u = s;
        reverse(u.begin(), u.end());
        int n = (int) s.size();
        int m = (int) t.size();
        string ans = "NO";
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (j - i >= m || s[j] != t[j - i]) {
                    break;
                }
                int l = m - (j - i + 1);
                if (l < 0) {
                    continue;
                }
                if (l == 0 || t.substr(j - i + 1) == u.substr(n - j, l)) {
                    ans = "YES";
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}