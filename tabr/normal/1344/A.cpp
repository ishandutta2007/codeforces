#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = a[i] % n;
            if (b[i] < 0) {
                b[i] += n;
            }
            b[i] += i;
            b[i] %= n;
        }
        sort(b.begin(), b.end());
        bool ok = true;
        for (int i = 0; i < n - 1; i++) {
            if (b[i] == b[i + 1]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}