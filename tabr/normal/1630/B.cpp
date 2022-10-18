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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        auto b = a;
        sort(b.begin(), b.end());
        int t = (n + k + 1) / 2;
        int x = -1;
        int y = (int) 1e9;
        for (int i = 0; i + t - 1 < n; i++) {
            int p = b[i];
            int q = b[i + t - 1];
            if (y - x > q - p) {
                x = p;
                y = q;
            }
        }
        cout << x << " " << y << '\n';
        for (int i = 0; i < n; i++) {
            if (x <= a[i] && a[i] <= y) {
                a[i] = 1;
            } else {
                a[i] = -1;
            }
        }
        debug(x, y);
        debug(a);
        vector<int> pref(n + 1);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + a[i];
        }
        assert(pref[n] >= k);
        vector<int> c(k + 1, -1);
        int id = 0;
        for (int i = 0; i <= n; i++) {
            if (id < k && pref[i] == id) {
                c[id] = i;
                id++;
            }
        }
        c[k] = n;
        for (int i = 0; i < k; i++) {
            cout << c[i] + 1 << " " << c[i + 1] << '\n';
        }
    }
    return 0;
}