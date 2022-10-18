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
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> d(n - 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long s = 0;
    for (int i = 0; i < n - 1; i++) {
        d[i] = a[i + 1] - a[i];
        s += max(d[i], 0LL);
    }
    int tt;
    cin >> tt;
    for (int qq = 0; qq <= tt; qq++) {
        long long b = (a[0] - s) / 2;
        cout << max(b + s, a[0] - b) << '\n';
        if (qq == tt) {
            break;
        }
        int l, r, x;
        cin >> l >> r >> x;
        l--, r--;
        if (l != 0) {
            s -= max(d[l - 1], 0LL);
            d[l - 1] += x;
            s += max(d[l - 1], 0LL);
        } else {
            a[0] += x;
        }
        if (r != n - 1) {
            s -= max(d[r], 0LL);
            d[r] -= x;
            s += max(d[r], 0LL);
        }
    }
    return 0;
}