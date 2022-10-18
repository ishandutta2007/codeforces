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
        if (n == 2) {
            cout << -1 << '\n';
            continue;
        }
        vector<pair<int, int>> ans;
        vector<int> b;
        function<void(int, int)> dfs = [&](int x, int y) {
            debug(x, y);
            if (x == 0) {
                return;
            }
            if (__builtin_popcount(x * y) == 1) {
                b.emplace_back(x * y);
                dfs(x - 1, y);
                return;
            }
            int k = 1;
            while (k < x) {
                k *= 2;
            }
            for (int i = x; i > k - i; i--) {
                b.emplace_back(k * y);
                ans.emplace_back(i * y, (k - i) * y);
            }
            b.emplace_back(k * y / 2);
            dfs(abs(x - (k - x)) / 2, y * 2);
            dfs(k - x - 1, y);
        };
        dfs(n, 1);
        sort(b.begin(), b.end());
        assert((int) b.size() == n);
        for (int i = 0; i < n - 1; i++) {
            if (b[i] == b[i + 1]) {
                ans.emplace_back(b[i], b[i + 1]);
                b[i + 1] += b[i];
                b[i] = 0;
                break;
            }
        }
        sort(b.begin(), b.end());
        for (int i = n - 1; i >= 1; i--) {
            while (b[i] < b[n - 1]) {
                ans.emplace_back(0, b[i]);
                ans.emplace_back(b[i], b[i]);
                b[i] *= 2;
            }
        }
        ans.emplace_back(0, b[n - 1]);
        b[0] = b[n - 1];
        assert(all_of(b.begin(), b.end(), [&](int x) { return x == b[0]; }));
        assert((int) ans.size() <= n * 20);
        cout << ans.size() << '\n';
        for (auto p : ans) {
            cout << p.first << " " << p.second << '\n';
        }
        debug(b[0]);
    }
    return 0;
}