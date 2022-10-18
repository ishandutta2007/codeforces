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
        vector<vector<int>> g(n);
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            g[x].emplace_back(y);
            g[y].emplace_back(x);
        }
        vector<vector<int>> ans;
        vector<pair<int, int>> tail(n, {-1, -1});
        function<void(int, int)> dfs = [&](int v, int p) {
            vector<int> a, b;
            for (int to : g[v]) {
                if (to == p) {
                    continue;
                }
                dfs(to, v);
                if (tail[to].second == -1) {
                    a.emplace_back(to);
                } else {
                    b.emplace_back(to);
                }
            }
            debug(v, a, b);
            if (a.empty() && b.empty()) {
                tail[v].first = v;
            } else {
                if (a.empty()) {
                    ans.push_back({v, b.back(), v, tail[b.back()].first});
                    tail[v].first = tail[b.back()].second;
                    b.pop_back();
                } else {
                    for (int to : a) {
                        if (tail[v].first == -1) {
                            tail[v].first = tail[to].first;
                        } else if (tail[v].second == -1) {
                            tail[v].second = tail[to].first;
                        } else {
                            ans.push_back({v, to, tail[v].first, to});
                            tail[v].first = tail[to].first;
                        }
                    }
                }
                for (int to : b) {
                    ans.push_back({v, to, tail[v].first, tail[to].first});
                    tail[v].first = tail[to].second;
                }
            }
            debug(tail[v]);
        };
        dfs(0, -1);
        cout << ans.size() << '\n';
        for (auto v : ans) {
            for (int i : v) {
                cout << i + 1 << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}