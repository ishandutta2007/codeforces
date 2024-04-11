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
        int x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                x++;
            } else if (a[i] == 0) {
                y++;
            }
        }
        cout << (x * 1LL << y) << '\n';
    }
    return 0;
}