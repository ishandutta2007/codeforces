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
        vector<int> b(7);
        for (int i = 0; i < 7; i++) {
            cin >> b[i];
        }
        cout << b[0] << " " << b[1] << " ";
        if (b[0] + b[1] == b[2]) {
            cout << b[3] << '\n';
        } else {
            cout << b[2] << '\n';
        }
    }
    return 0;
}