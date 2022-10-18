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
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.rbegin(), order.rend(), [&](int i, int j) { return abs(a[i]) < abs(a[j]); });
        vector<int> b(n);
        int c = 0;
        int j = order.back();
        order.pop_back();
        for (int i : order) {
            if ((c <= 0) == (a[i] > 0)) {
                c += a[i];
                b[i] = 1;
            } else {
                c -= a[i];
                b[i] = -1;
            }
        }
        if (c == 0) {
            c += a[order.back()] * b[order.back()];
            b[order.back()] *= 2;
        }
        int d = a[j];
        int x = -d;
        int y = c;
        b[j] = y;
        for (int i = 0; i < n; i++) {
            if (i != j) {
                b[i] *= x;
            }
        }
        c = 0;
        for (int i = 0; i < n; i++) {
            cout << b[i] << " ";
            c += a[i] * b[i];
        }
        cout << '\n';
        debug(c);
    }
    return 0;
}