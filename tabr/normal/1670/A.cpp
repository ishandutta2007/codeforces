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
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < 0) {
                c++;
                a[i] = -a[i];
            }
        }
        for (int i = 0; i < c; i++) {
            a[i] = -a[i];
        }
        if (is_sorted(a.begin(), a.end())) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}