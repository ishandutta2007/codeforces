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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(q);
    int c = n;
    for (int i = 0; i < q; i++) {
        cin >> b[i];
        if (b[i] < 0) {
            c--;
        } else {
            c++;
        }
    }
    if (c == 0) {
        cout << 0 << '\n';
        return 0;
    }
    int lo = 0, hi = n;
    while (hi - lo > 1) {
        int mid = (hi + lo) / 2;
        int small = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] <= mid) {
                small++;
            }
        }
        for (int i = 0; i < q; i++) {
            if (b[i] > 0) {
                if (b[i] <= mid) {
                    small++;
                }
            } else {
                if (-b[i] <= small) {
                    small--;
                }
            }
        }
        if (small) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << hi << '\n';
    return 0;
}