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
        int s = accumulate(a.begin(), a.end(), 0);
        if (s == n) {
            cout << 0 << '\n';
        } else if (s < n) {
            cout << 1 << '\n';
        } else {
            cout << s - n << '\n';
        }
    }
    return 0;
}