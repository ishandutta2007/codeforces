#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int f(int x) {
    int res = 0;
    while (x > 0) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

int g(int x, int k) {
    int res = 0;
    for (int i = x; i <= x + k; i++) {
        res += f(i);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        int k;
        cin >> k;
        if (n < k * (k - 1) / 2) {
            cout << -1 << '\n';
            continue;
        }
        ll res = 1e18;
        for (int i = 0; i < 10 - k; i++) {
            ll s = 0, t = 0;
            for (int j = i; j <= i + k; j++) {
                s += j;
            }
            s = n - s;
            if (s < 0 || s % (k + 1) != 0) {
                continue;
            }
            s /= k + 1;
            t = s % 9;
            for (int j = 0; j < s / 9; j++) {
                t *= 10;
                t += 9;
            }
            if (k || i) {
                t *= 10;
                t += i;
            }
            res = min(res, t);
        }
        for (int i = 10 - k; i < 10; i++) {
            ll s = n;
            for (int j = i; j <= i + k; j++) {
                s -= j % 10;
            }
            int a = 10 - i;
            int b = k + 1 - a;
            s -= b;
            int l = 0;
            while (s >= 0) {
                if (s % (k + 1) != 0) {
                    l++;
                    s -= 9 * a;
                    continue;
                }
                ll t = s / (k + 1);
                if (t > 8) {
                    t -= 8;
                    ll u = t % 9;
                    for (int j = 0; j <t/9; j++){
                        u *= 10;
                        u += 9;
                    }
                    u *= 10;
                    u += 8;
                    swap(t, u);
                }
                for (int j = 0; j < l; j++) {
                    t *= 10;
                    t += 9;
                }
                t *= 10;
                t += i;
                res = min(res, t);
                s -= 9 * a;
                l++;
            }
        }
        if (res == 1e18) {
            res = -1;
        }
        cout << res << '\n';
    }
    return 0;
}