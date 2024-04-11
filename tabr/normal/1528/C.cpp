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
        vector<vector<int>> a(n), b(n);
        for (int i = 0; i < n - 1; i++) {
            int x;
            cin >> x;
            x--;
            a[x].emplace_back(i + 1);
        }
        for (int i = 0; i < n - 1; i++) {
            int x;
            cin >> x;
            x--;
            b[x].emplace_back(i + 1);
        }
        vector<int> order;  // b
        vector<int> beg(n), end(n);
        {
            auto dfs = [&](auto &&self, int v) -> void {
                beg[v] = (int) order.size();
                order.emplace_back(v);
                for (int to : b[v]) {
                    self(self, to);
                }
                end[v] = (int) order.size();
            };
            dfs(dfs, 0);
        }
        // debug(order);
        // debug(beg);
        // debug(end);
        int ans = 0;
        int cur = 0;
        set<pair<int, int>> st;
        st.emplace(n + 2, n + 2);
        st.emplace(-2, -2);
        auto dfs = [&](auto &&self, int v) -> void {
            pair<int, int> die(-1, -1);
            int add = 0;
            if ((*st.lower_bound({beg[v], end[v]})).first >= end[v]) {
                add = 1;
                if ((*prev(st.upper_bound({beg[v], end[v]}))).second >= end[v]) {
                    die = *prev(st.upper_bound({beg[v], end[v]}));
                    st.erase(die);
                } else {
                    cur++;
                }
                st.emplace(beg[v], end[v]);
            }
            ans = max(ans, cur);
            for (int to : a[v]) {
                self(self, to);
            }
            if (add) {
                st.erase({beg[v], end[v]});
                if (die.first == -1) {
                    cur--;
                }
            }
            if (die.first != -1) {
                st.emplace(die);
            }
        };
        dfs(dfs, 0);
        cout << ans << '\n';
    }
    return 0;
}