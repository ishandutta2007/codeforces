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
        int n;
        cin >> n;
        vector<int> a(n);
        int b = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            b ^= a[i];
        }
        if (b == 0) {
            cout << "DRAW" << '\n';
            continue;
        }
        int c = 1;
        while (b >= c) {
            c *= 2;
        }
        c /= 2;
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] & c) {
                k++;
            }
        }
        if (k % 4 == 1) {
            cout << "WIN" << '\n';
        } else {
            if ((n - k) % 2 == 1) {
                cout << "WIN" << '\n';
            } else {
                cout << "LOSE" << '\n';
            }
        }
    }
    return 0;
}