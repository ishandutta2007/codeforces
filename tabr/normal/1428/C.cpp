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
        int ans = n;
        int a = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') {
                a++;
            } else {
                if (a) {
                    a--;
                    ans -= 2;
                } else {
                    a++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}