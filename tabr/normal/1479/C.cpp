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
    int l, r;
    cin >> l >> r;
    int d = r - l + 1;
    int n = 0;
    int a = 1;
    while (a * 3 <= d && a * 3 + n < r) {
        a *= 3;
        n++;
    }
    cout << "YES" << '\n';
    if (n == 0) {
        cout << d + 1 << " " << 2 * d - 1 << '\n';
        for (int i = 2; i <= d + 1; i++) {
            cout << 1 << " " << i << " " << l << '\n';
            if (i != d + 1) {
                cout << i << " " << d + 1 << " " << d + 1 - i << '\n';
            }
        }
        return 0;
    }
    vector<tuple<int, int, int>> ans;
    int m = 2 * (n + 1) + 2;
    ans.emplace_back(m - 2, m, 1);
    ans.emplace_back(m - 1, m, 1);
    ans.emplace_back(1, 2, 2);
    ans.emplace_back(1, 3, 1);
    ans.emplace_back(2, 3, 1);
    a = 1;
    for (int i = 1; i < n; i++) {
        a *= 3;
        for (int j = 2 * i; j <= 2 * i + 1; j++) {
            ans.emplace_back(j, 2 * i + 3, 1);
            ans.emplace_back(j, 2 * i + 2, a + 1);
        }
        ans.emplace_back(2 * i + 2, 2 * i + 3, a);
    }
    a *= 3;
    for (int i = n; i >= 0; i--) {
        int x = i;
        int y = a + i - 1;
        int j = 2 * i;
        debug(i, a);
        debug(x, y);
        debug(l, r);
        if (y + 2 <= r && l <= x + r - y) {
            if (j) {
                ans.emplace_back(j, m - 2, r - y - 1);
            }
            ans.emplace_back(j + 1, m - 2, r - y - 1);
            r = x + r - y - 1;
        }
        if (y + 2 <= r && l <= x + r - y) {
            if (j) {
                ans.emplace_back(j, m - 1, r - y - 1);
            }
            ans.emplace_back(j + 1, m - 1, r - y - 1);
            r = x + r - y - 1;
        }
        if (y + 1 <= r && l <= x + r - y) {
            if (j) {
                ans.emplace_back(j, m, r - y);
            }
            ans.emplace_back(j + 1, m, r - y);
            r = x + r - y - 1;
        }
        a /= 3;
    }
    debug(l, r);
    assert(r < l);
    cout << m << " " << ans.size() << '\n';
    for (auto v : ans) {
        cout << get<0>(v) << " " << get<1>(v) << " " << get<2>(v) << '\n';
    }
    return 0;
}