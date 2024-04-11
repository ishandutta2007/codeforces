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
        char c;
        cin >> c;
        string ans = "NO";
        for (int z = 0; z < 2; z++) {
            for (int i = 0; i < (int) s.size(); i += 2) {
                if (s[i] == c) {
                    ans = "YES";
                }
            }
            reverse(s.begin(), s.end());
        }
        cout << ans << '\n';
    }
    return 0;
}