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
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                c++;
            }
        }
        if (c % 2 == 1 && c != 1) {
            cout << "ALICE" << '\n';
        } else {
            cout << "BOB" << '\n';
        }
    }
    return 0;
}