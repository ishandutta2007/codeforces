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
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            b[i] = max(b[i], b[i + 1] - a[i + 1] + a[i]);
        }
        long long res = 1LL * b[0] * (b[0] + 1) / 2;
        long long pre = b[0];
        for (int i = 1; i < n; i++) {
            if (a[i] - a[i - 1] >= b[i]) {
                pre = b[i];
                res += pre * (pre + 1) / 2;
            } else {
                res -= pre * (pre + 1) / 2;
                pre += a[i] - a[i - 1];
                res += pre * (pre + 1) / 2;
            }
        }
        cout << res << '\n';
    }
    return 0;
}