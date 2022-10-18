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
        if (n % 2 == 0) {
            cout << n / 2 << " " << n / 2 - 1 << " " << 1 << '\n';
        } else {
            int k = n / 2;
            for (int i = 1;; i++) {
                if (__gcd(k + i, k - i) == 1) {
                    cout << k + i << " " << k - i << " " << 1 << '\n';
                    break;
                }
            }
        }
    }
    return 0;
}