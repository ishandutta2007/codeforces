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
        vector<int> b(30);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 30; j++) {
                if (a[i] & (1 << j)) {
                    b[j]++;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            int ok = 1;
            for (int j = 0; j < 30; j++) {
                if (b[j] % i != 0) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                cout << i << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}