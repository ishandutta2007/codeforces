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
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        vector<tuple<int, int, int>> c;
        for (int i = 0; i < n; i++) {
            c.emplace_back(a[i], 0, i);
            c.emplace_back(b[i], 1, i);
        }
        sort(c.begin(), c.end());
        queue<int> que;
        vector<int> ans(n);
        for (auto [i, j, k] : c) {
            if (j == 0) {
                if (que.empty()) {
                    ans[k] -= i;
                }
                que.emplace(k);
            } else {
                ans[que.front()] += i;
                que.pop();
                if (!que.empty()) {
                    ans[que.front()] -= i;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}