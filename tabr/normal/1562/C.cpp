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
        int ok = 0;
        for (int i = n / 2; i < n; i++) {
            if (s[i] == '0') {
                cout << 1 << " " << i + 1 << " " << 1 << " " << i << '\n';
                ok = 1;
                break;
            }
        }
        if (ok) {
            continue;
        }
        for (int i = 0; i < n / 2; i++) {
            if (s[i] == '0') {
                cout << i + 1 << " " << n << " " << i + 2 << " " << n << '\n';
                ok = 1;
                break;
            }
        }
        if (ok) {
            continue;
        }
        cout << 1 << " " << n / 2 * 2 << " " << 1 << " " << n / 2 << '\n';
    }
    return 0;
}