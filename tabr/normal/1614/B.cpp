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
        }
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int x, int y) { return a[x] > a[y]; });
        vector<int> ans(n);
        long long b = 0;
        for (int i = 0; i < n; i++) {
            b += 1LL * a[order[i]] * ((i + 2) / 2);
            ans[order[i]] = (i + 2) / 2;
            if (i % 2 == 1) {
                ans[order[i]] *= -1;
            }
        }
        cout << b * 2 << '\n';
        cout << 0 << " ";
        for (int i : ans) {
            cout << i << " ";
        }
        cout << '\n';
    }
    return 0;
}