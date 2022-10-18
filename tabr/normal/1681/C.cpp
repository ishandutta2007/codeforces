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
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int i, int j) {
            return make_pair(a[i], b[i]) < make_pair(a[j], b[j]);
        });
        bool ng = false;
        for (int i = 1; i < n; i++) {
            int x = order[i - 1];
            int y = order[i];
            if (b[x] > b[y]) {
                ng = true;
            }
        }
        if (ng) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> now(n);
        vector<int> pos(n);
        iota(now.begin(), now.end(), 0);
        iota(pos.begin(), pos.end(), 0);
        vector<pair<int, int>> ans;
        auto Swap = [&](int x, int y) {
            swap(pos[x], pos[y]);
            x = pos[x];
            y = pos[y];
            ans.emplace_back(x, y);
            swap(now[x], now[y]);
        };
        for (int i = 0; i < n; i++) {
            if (now[i] != order[i]) {
                Swap(now[i], order[i]);
            }
        }
        cout << ans.size() << '\n';
        for (auto [x, y] : ans) {
            cout << x + 1 << " " << y + 1 << '\n';
        }
    }
    return 0;
}