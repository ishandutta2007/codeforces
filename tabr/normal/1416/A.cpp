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
        vector<vector<int>> x(n, vector<int>(1, -1));
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
            x[a[i]].emplace_back(i);
        }
        vector<int> ans(n, n);
        for (int i = 0; i < n; i++) {
            x[i].emplace_back(n);
            int b = 0;
            for (int j = 1; j < (int)x[i].size(); j++) {
                b = max(b, x[i][j] - x[i][j - 1] - 1);
            }
            if (b != n) {
                ans[b] = min(ans[b], i);
            }
        }
        for (int i = 0; i < n; i++) {
            if (i) {
                ans[i] = min(ans[i], ans[i - 1]);
            }
            cout << (ans[i] == n ? -1 : ans[i] + 1) << " ";
        }
        cout << '\n';
    }
    return 0;
}