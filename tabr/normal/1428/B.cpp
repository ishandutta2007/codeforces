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
        string s;
        cin >> n >> s;
        int ans = 0;
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '-' || s[(i + 1) % n] == '-') {
                ans++;
            }
            if (s[i] == '<') {
                a = 1;
            }
            if (s[i] == '>') {
                b = 1;
            }
        }
        if (a == 0 || b == 0) {
            ans = n;
        }
        cout << ans << '\n';
    }
    return 0;
}