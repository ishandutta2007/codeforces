#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

// editorial

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
        if (n % 2 == 1) {
            cout << -1 << '\n';
            continue;
        }
        vector<pair<int, int>> ans1;
        vector<int> ans2;
        auto rev = [&](int i, int k) {
            for (int j = k - 1; j >= i; j--) {
                ans1.emplace_back(i + k - 1 - j, a[j]);
            }
            ans2.emplace_back((k - i) * 2);
            reverse(a.begin() + i, a.begin() + k);
        };
        bool ng = false;
        for (int i = n - 1; i >= 0; i -= 2) {
            for (int j = i - 1; j >= 0; j--) {
                if (a[i] == a[j]) {
                    rev(j + 1, i + 1);
                    rev(j, i + 1);
                    break;
                }
                if (j == 0) {
                    ng = true;
                    break;
                }
            }
            ans2.emplace_back(2);
        }
        if (ng) {
            cout << -1 << '\n';
            continue;
        }
        debug(a);
        reverse(ans2.begin(), ans2.end());
        cout << ans1.size() << '\n';
        for (auto [x, y] : ans1) {
            cout << x << " " << y << '\n';
        }
        cout << ans2.size() << '\n';
        for (int i = 0; i < (int) ans2.size(); i++) {
            cout << ans2[i] << " \n"[i == (int) ans2.size() - 1];
        }
    }
    return 0;
}