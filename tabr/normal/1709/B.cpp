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
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<long long> b(n);
    for (int i = 0; i < n - 1; i++) {
        b[i + 1] = b[i] + max(a[i] - a[i + 1], 0LL);
    }
    vector<long long> c(n);
    for (int i = 0; i < n - 1; i++) {
        c[i + 1] = c[i] + max(a[i + 1] - a[i], 0LL);
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if (l < r) {
            cout << b[r] - b[l] << '\n';
        } else {
            cout << c[l] - c[r] << '\n';
        }
    }
    return 0;
}