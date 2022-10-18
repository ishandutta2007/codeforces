#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
        int x;
        cin >> x;
        int n = s.size();
        string w(n, '1');
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (i >= x) {
                    w[i - x] = '0';
                }
                if (i + x < n) {
                    w[i + x] = '0';
                }
            }
        }
        string t(n, '0');
        for (int i = 0; i < n; i++) {
            if (w[i] == '1') {
                if (i >= x) {
                    t[i - x] = '1';
                }
                if (i + x < n) {
                    t[i + x] = '1';
                }
            }
        }
        if (s == t) {
            cout << w << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}