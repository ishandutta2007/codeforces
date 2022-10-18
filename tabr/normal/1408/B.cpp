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
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
        int b = (int)a.size();
        if (k == 1) {
            if (b == 1) {
                cout << 1 << '\n';
            } else {
                cout << -1 << '\n';
            }
        } else {
            if (b <= k) {
                cout << 1 << '\n';
            } else {
                b -= k;
                cout << (b + k - 2) / (k - 1) + 1 << '\n';
            }
        }
    }
    return 0;
}