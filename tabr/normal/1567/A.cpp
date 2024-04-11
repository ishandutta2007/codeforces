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
        for (int i = 0; i < n; i++) {
            if (s[i] == 'U' || s[i] == 'D') {
                s[i] ^= 'U' ^ 'D';
            }
            cout << s[i];
        }
        cout << '\n';
    }
    return 0;
}