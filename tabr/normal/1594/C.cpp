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
        char c;
        cin >> c;
        string s;
        cin >> s;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            if (s[i] != c) {
                a[i] = 1;
            }
        }
        if (a == vector<int>(n)) {
            cout << 0 << '\n';
            continue;
        }
        int ok = -1;
        for (int i = 1; i <= n; i++) {
            int ng = 0;
            for (int j = i; j <= n; j += i) {
                if (a[j - 1] == 1) {
                    ng = 1;
                    break;
                }
            }
            if (!ng) {
                ok = i;
                break;
            }
        }
        if (ok != -1) {
            cout << 1 << '\n';
            cout << ok << '\n';
        } else {
            cout << 2 << '\n';
            cout << n - 1 << " " << n << '\n';
        }
    }
    return 0;
}