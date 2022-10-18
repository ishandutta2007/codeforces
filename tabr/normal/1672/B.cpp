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
        if (s.back() != 'B') {
            cout << "NO" << '\n';
            continue;
        }
        int n = (int) s.size();
        int a = 0;
        string ans = "YES";
        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') {
                a++;
            } else {
                a--;
                if (a < 0) {
                    ans = "NO";
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}