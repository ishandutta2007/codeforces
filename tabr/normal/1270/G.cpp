#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = i - a[i];
        }
        debug(b);
        vector<int> order;
        vector<int> was(n);
        function<void(int)> dfs = [&](int v) {
            if (!was[b[v]]) {
                order.emplace_back(b[v]);
                was[b[v]] = 1;
                dfs(b[v]);
            } else {
                vector<int> ans;
                int id = order.size() - 1;
                while (order[id] != b[v]) {
                    ans.emplace_back(order[id--]);
                }
                ans.emplace_back(order[id]);
                cout << ans.size() << '\n';
                for (int i : ans) {
                    cout << i + 1 << " ";
                }
                cout << '\n';
                return;
            }
        };
        order.emplace_back(0);
        was[0] = 1;
        dfs(0);
    }
    return 0;
}