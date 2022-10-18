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
        string s;
        cin >> s;
        ll u = 0, l = 0, r = 0, d = 0, x = 0, y = 0;
        int tu = 0, tl = 0, tr = 0, td = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == 'W') {
                y++;
                if (y > u) {
                    u = y;
                    tu = i;
                }
            } else if (s[i] == 'S') {
                y--;
                if (y < d) {
                    d = y;
                    td = i;
                }
            } else if (s[i] == 'D') {
                x++;
                if (x > r) {
                    r = x;
                    tr = i;
                }
            } else {
                x--;
                if (x < l) {
                    l = x;
                    tl = i;
                }
            }
        }
        ll ans = (r - l + 1) * (u - d + 1);
        auto calc = [&](int t, char v) {
            u = d = r = l = x = y = 0;
            for (int i = 0; i < n; i++) {
                if (i == t) {
                    if (v == 'W') {
                        y++;
                        if (y > u) {
                            u = y;
                        }
                    } else if (v == 'S') {
                        y--;
                        if (y < d) {
                            d = y;
                        }
                    } else if (v == 'D') {
                        x++;
                        if (x > r) {
                            r = x;
                        }
                    } else {
                        x--;
                        if (x < l) {
                            l = x;
                        }
                    }
                }
                if (s[i] == 'W') {
                    y++;
                    if (y > u) {
                        u = y;
                    }
                } else if (s[i] == 'S') {
                    y--;
                    if (y < d) {
                        d = y;
                    }
                } else if (s[i] == 'D') {
                    x++;
                    if (x > r) {
                        r = x;
                    }
                } else {
                    x--;
                    if (x < l) {
                        l = x;
                    }
                }
            }
            ans = min(ans, (r - l + 1) * (u - d + 1));
            return;
        };
        debug(tu, td, tr, tl);
        calc(tu, 'S');
        calc(td, 'W');
        calc(tr, 'A');
        calc(tl, 'D');
        cout << ans << '\n';
    }
    return 0;
}