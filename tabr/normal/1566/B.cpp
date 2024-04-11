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
        int ans = 0;
        char c = '1';
        for (int i = 0; i < n; i++) {
            if (c != s[i]) {
                c = s[i];
                if (s[i] == '0') {
                    ans++;
                }
            }
        }
        ans = min(ans, 2);
        cout << ans << '\n';
    }
    return 0;
}