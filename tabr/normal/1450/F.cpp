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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
            b[a[i]]++;
        }
        if (*max_element(b.begin(), b.end()) > (n + 1) / 2) {
            cout << -1 << '\n';
            continue;
        }
        vector<pair<int, int>> p;
        int lst = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1]) {
                p.emplace_back(a[lst], a[i - 1]);
                lst = i;
            }
        }
        p.emplace_back(a[lst], a[n - 1]);
        b = vector<int>(n);
        for (auto q : p) {
            b[q.first]++;
            b[q.second]++;
        }
        int k = (int)p.size();
        int mx = *max_element(b.begin(), b.end());
        if (mx <= k + 1) {
            cout << k - 1 << '\n';
            continue;
        } else {
            cout << mx - 2 << '\n';
        }
    }
    return 0;
}