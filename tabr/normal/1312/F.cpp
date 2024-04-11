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
    int mx = 10000;
    auto mex = [&](int a, int b, int c) {
        int res = 0;
        while (res == a || res == b || res == c) {
            res++;
        }
        return res;
    };
    while (tt--) {
        int n, x, y, z;
        cin >> n >> x >> y >> z;
        vector<vector<int>> gn(mx, vector<int>(3));
        for (int i = 1; i < mx; i++) {
            gn[i][0] = mex(gn[max(0, i - x)][0], gn[max(0, i - y)][1], gn[max(0, i - z)][2]);
            gn[i][1] = mex(gn[max(0, i - x)][0], gn[max(0, i - z)][2], -1);
            gn[i][2] = mex(gn[max(0, i - x)][0], gn[max(0, i - y)][1], -1);
        }
        ll r = 1;
        while (true) {
            bool ok = true;
            for (int i = 1; i < 10; i++) {
                for (int j = 0; j < r; j++) {
                    if (gn[100 + j] != gn[100 + j + r * i]) {
                        ok = false;
                        break;
                    }
                }
            }
            if (ok) {
                break;
            }
            r++;
        }
        auto calc = [&](ll s, int t) {
            if (s < 100) {
                return gn[s][t];
            }
            s %= r;
            for (int i = 0; i < r; i++) {
                if (s == (101 + i) % r) {
                    return gn[101 + i][t];
                }
            }
            return -1;
        };
        int gall = 0;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            gall ^= calc(a[i], 0);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int g = gall ^ calc(a[i], 0);
            if (g == calc(max(a[i] - x, 0LL), 0)) {
                ans++;
            }
            if (g == calc(max(a[i] - y, 0LL), 1)) {
                ans++;
            }
            if (g == calc(max(a[i] - z, 0LL), 2)) {
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}