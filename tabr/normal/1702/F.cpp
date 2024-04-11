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
            while (a[i] % 2 == 0) {
                a[i] /= 2;
            }
        }
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            while (b[i] % 2 == 0) {
                b[i] /= 2;
            }
        }
        swap(a, b);
        vector<multiset<int>> c(32), d(32);
        for (int i = 0; i < n; i++) {
            c[__builtin_popcount(a[i])].emplace(a[i]);
            d[__builtin_popcount(b[i])].emplace(b[i]);
        }
        string ans = "YES";
        for (int i = 31; i >= 0; i--) {
            for (int x : c[i]) {
                auto iter = d[i].find(x);
                if (iter != d[i].end()) {
                    d[i].erase(iter);
                } else if (i == 0) {
                    ans = "NO";
                    break;
                } else {
                    x /= 2;
                    while (x % 2 == 0) {
                        x /= 2;
                    }
                    c[i - 1].emplace(x);
                }
            }
            if (!d[i].empty()) {
                ans = "NO";
                break;
            }
            multiset<int>().swap(c[i]);
            multiset<int>().swap(d[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}