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
        int s;
        cin >> s;
        int ans = 0;
        int t = 0;
        for (int i = 1; t + i < s; i += 2) {
            t += i;
            ans++;
        }
        if (t != s) {
            ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}