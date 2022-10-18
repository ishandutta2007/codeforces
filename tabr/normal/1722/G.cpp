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
        vector<int> a(n);
        iota(a.begin(), a.end(), 0);
        if (n == 3) {
            a[0] = 2;
            a[1] = 1;
            a[2] = 3;
        } else if (n % 4 == 1) {
            a[n - 1] = 0;
            a[n - 1] |= 1 << 20;
            a[n - 2] |= 1 << 20;
        } else if (n % 4 == 2) {
            iota(a.begin(), a.end(), 2);
            for (int i = 0; i < 6; i++) {
                a[i] = i;
            }
            a[5] = 4;
            a[0] |= 1 << 20;
            a[5] |= 1 << 20;
        } else if (n % 4 == 3) {
            a[n - 1] = 1;
            a[n - 1] |= 1 << 20;
            a[n - 2] |= 1 << 20;
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}