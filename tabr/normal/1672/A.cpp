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
        int s = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            s += a - 1;
        }
        if (s % 2 == 1) {
            cout << "errorgorn" << '\n';
        } else {
            cout << "maomao90" << '\n';
        }
    }
    return 0;
}