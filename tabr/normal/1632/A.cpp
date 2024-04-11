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
        string ans = "YES";
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                ans = "NO";
            }
        }
        for (int i = 0; i < n - 2; i++) {
            if (s[i] == s[i + 2]) {
                ans = "NO";
            }
        }
        cout << ans << '\n';
    }
    return 0;
}