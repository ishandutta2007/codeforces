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
        int n, a, b;
        cin >> n >> a >> b;
        if (a == 1) {
            if ((n - 1) % b == 0) {
                cout << "Yes" << '\n';
            } else {
                cout << "No" << '\n';
            }
        } else {
            long long c = 1;
            while (c <= n) {
                if ((n - c) % b == 0) {
                    c = -1;
                    break;
                }
                c *= a;
            }
            if (c == -1) {
                cout << "Yes" << '\n';
            } else {
                cout << "No" << '\n';
            }
        }
    }
    return 0;
}