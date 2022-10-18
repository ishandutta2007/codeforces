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
        int n, m;
        cin >> n >> m;
        vector<int> x(m), w(m);
        for (int i = 0; i < m; i++) {
            cin >> x[i] >> w[i];
        }
        vector<int> order(m);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int i, int j) {
            return w[i] < w[j];
        });
        int ans = 0;
        vector<int> t;
        for (int i = 0; i < 2 * n; i++) {
            ans += w[order[i]];
            t.emplace_back(order[i]);
        }
        sort(t.begin(), t.end(), [&](int i, int j) {
            return x[i] < x[j];
        });
        cout << ans << '\n';
        for (int i = 0; i < n; i++) {
            cout << t[i] + 1 << " " << t[2 * n - 1 - i] + 1 << '\n';
        }
    }
    return 0;
}