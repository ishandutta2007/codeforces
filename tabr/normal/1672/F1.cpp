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
        vector<int> cnt(n + 1);
        vector<vector<int>> b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            b[cnt[a[i]]].emplace_back(i);
            cnt[a[i]]++;
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            if (b[i].empty()) {
                break;
            }
            sort(b[i].begin(), b[i].end(), [&](int x, int y) {
                return a[x] < a[y];
            });
            int sz = (int) b[i].size();
            b[i].emplace_back(b[i][0]);
            for (int j = 0; j < sz; j++) {
                res[b[i][j + 1]] = a[b[i][j]];
            }
        }
        for (int i = 0; i < n; i++) {
            cout << res[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}