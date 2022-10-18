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
        int q;
        cin >> q;
        string s;
        cin >> s;
        while (q--) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            string ans = "NO";
            for (int i = 0; i < l; i++) {
                if (s[i] == s[l]) {
                    ans = "YES";
                }
            }
            for (int i = r + 1; i < n; i++) {
                if (s[i] == s[r]) {
                    ans = "YES";
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}