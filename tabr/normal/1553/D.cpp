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
        string s, t;
        cin >> s >> t;
        int n = (int) s.size(), m = (int) t.size();
        int k = 0;
        for (int i = 0; i < n; i++) {
            if ((m - k) % 2 == (n - i) % 2 && k < m && s[i] == t[k]) {
                k++;
            }
        }
        if (k == m) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}