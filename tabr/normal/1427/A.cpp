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
        sort(a.begin(), a.end());
        int s = accumulate(a.begin(), a.end(), 0);
        if (s == 0) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
            if (s > 0) {
                reverse(a.begin(), a.end());
            }
            for (int i : a) {
                cout << i << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}