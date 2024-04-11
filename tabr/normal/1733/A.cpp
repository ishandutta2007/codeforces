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
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<long long> b(k);
        for (int i = 0; i < n; i++) {
            b[i % k] = max(b[i % k], a[i]);
        }
        cout << accumulate(b.begin(), b.end(), 0LL) << '\n';
    }
    return 0;
}