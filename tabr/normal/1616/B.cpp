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
        string ans = string(n + n, 'z');
        for (char c = s[0]; c >= 'a'; c--) {
            string t;
            t += s[0];
            if (c != s[0]) {
                for (int i = 1; i < n; i++) {
                    if (s[i - 1] < s[i]) {
                        break;
                    }
                    if (s[i] < c) {
                        break;
                    }
                    t += s[i];
                }
            }
            string u = t;
            reverse(u.begin(), u.end());
            t += u;
            ans = min(ans, t);
        }
        cout << ans << '\n';
    }
    return 0;
}