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
        int n, k, l;
        cin >> n >> k >> l;
        vector<int> d(n);
        for (int i = 0; i < n; i++) {
            cin >> d[i];
            d[i] = l - d[i];
        }
        if (*min_element(d.begin(), d.end()) < 0) {
            cout << "No" << '\n';
            continue;
        }
        int a = 0, b = 2 * k - 1;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (d[i] >= k) {
                a = 0, b = 2 * k - 1;
                continue;
            }
            int x = (int)((-1LL * d[i]) % (2 * k) + 2 * k) % (2 * k);
            int y = (int)((1LL * d[i]) % (2 * k) + 2 * k) % (2 * k);
            if (x == 0) {
                if (a > b || b == 2 * k - 1) {
                    a = b = 0;
                } else {
                    ok = false;
                    break;
                }
            } else if (a <= b) {
                if (y <= a && b + 1 < x) {
                    ok = false;
                    break;
                } else if (b + 1 >= x) {
                    if (x <= a) {
                        a++;
                        a %= 2 * k;
                    } else {
                        a = x;
                    }
                    b = y;
                } else {
                    a++;
                    b = y;
                }
            } else {
                if (b + 1 >= x) {
                    a = x;
                } else {
                    a = max(x, a + 1) % (2 * k);
                }
                b = y;
            }
        }
        cout << (ok ? "Yes" : "No") << '\n';
    }
    return 0;
}