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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> b = a;
        sort(b.begin(), b.end());
        for (int i = 0; i < n; i++) {
            a[i] = (int) (lower_bound(b.begin(), b.end(), a[i]) - b.begin());
        }
        int t = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] - a[i - 1] != 1) {
                t++;
            }
        }
        if (t <= k) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }
    return 0;
}