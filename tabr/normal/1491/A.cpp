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
    vector<int> b(2);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]]++;
    }
    while (q--) {
        int t, k;
        cin >> t >> k;
        if (t == 1) {
            k--;
            b[a[k]]--;
            a[k] ^= 1;
            b[a[k]]++;
        } else {
            if (k <= b[1]) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
    }
    return 0;
}