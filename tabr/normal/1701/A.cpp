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
        int a = 0;
        for (int i = 0; i < 4; i++) {
            int b;
            cin >> b;
            a += b;
        }
        if (a == 0) {
            cout << 0 << '\n';
        } else if (a == 4) {
            cout << 2 << '\n';
        } else {
            cout << 1 << '\n';
        }
    }
    return 0;
}