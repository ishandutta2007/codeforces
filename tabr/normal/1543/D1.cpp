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
        auto ask = [&](int y) {
            cout << y << endl;
            int r;
            cin >> r;
            return r;
        };
        vector<int> a(n);
        iota(a.begin(), a.end(), 0);
        if (ask(0)) {
            continue;
        }
        int b = 0;
        for (int i = 1; i < n; i++) {
            a[i] ^= b;
            b ^= a[i];
            if (ask(a[i])) {
                break;
            }
        }
    }
    return 0;
}