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
        for (int i = n - 1; i >= 0; i--) {
            int ok = 0;
            for (int j = i; j >= 0; j--) {
                if (a[j] % (j + 2) != 0) {
                    a.erase(a.begin() + j);
                    ok = 1;
                    break;
                }
            }
            if (ok == 0) {
                cout << "NO" << '\n';
                break;
            } else if (i == 0) {
                cout << "YES" << '\n';
            }
        }
    }
    return 0;
}