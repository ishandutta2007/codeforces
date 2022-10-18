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
    // 24:00
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        s.resize(unique(s.begin(), s.end()) - s.begin());
        sort(s.begin(), s.end());
        string ans = "YES";
        for (int i = 0; i + 1 < (int)s.size(); i++) {
            if (s[i] == s[i + 1]) {
                ans = "NO";
            }
        }
        cout << ans << '\n';
    }
    return 0;
}