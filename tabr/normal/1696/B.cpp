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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (a == vector<int>(n, 0)) {
            cout << 0 << '\n';
        } else {
            int l = 0;
            while (a[l] == 0) {
                l++;
            }
            int r = n - 1;
            while (a[r] == 0) {
                r--;
            }
            if (*min_element(a.begin() + l, a.begin() + r + 1) == 0) {
                cout << 2 << '\n';
            } else {
                cout << 1 << '\n';
            }
        }
    }
    return 0;
}