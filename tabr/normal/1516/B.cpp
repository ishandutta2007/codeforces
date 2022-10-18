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
        vector<int> a(n);
        int c = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            c ^= a[i];
        }
        string ans = "NO";
        int b = 0;
        if (c == 0) {
            ans = "YES";
        }
        b = 0;
        for (int i = 0; i < n; i++) {
            b ^= a[i];
            int d = 0;
            for (int j = i + 1; j < n - 1; j++) {
                d ^= a[j];
                if (b == d && d == c) {
                    ans = "YES";
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}