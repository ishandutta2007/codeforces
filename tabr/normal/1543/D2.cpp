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
        auto ask = [&](int y) {
            cout << y << endl;
            int r;
            cin >> r;
            return r;
        };
        auto f = [&](int x, int y, int inv) {
            int res = 0;
            vector<int> t;
            while (x > 0 || y > 0) {
                int a = x % k;
                int b = y % k;
                if (inv) {
                    b = (k - b) % k;
                }
                t.emplace_back((a + b) % k);
                x /= k;
                y /= k;
            }
            reverse(t.begin(), t.end());
            for (int i : t) {
                res *= k;
                res += i;
            }
            return res;
        };
        vector<int> a(n);
        iota(a.begin(), a.end(), 0);
        if (ask(0)) {
            continue;
        }
        int b = 0;
        for (int i = 1; i < n; i++) {
            a[i] = f(b, a[i], i % 2);
            b = f(a[i], b, 1);
            if (ask(a[i])) {
                break;
            }
        }
    }
    return 0;
}