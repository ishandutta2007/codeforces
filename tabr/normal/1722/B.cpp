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
        string t;
        cin >> t;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'G') {
                s[i] = 'B';
            }
            if (t[i] == 'G') {
                t[i] = 'B';
            }
        }
        if (s == t) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}