#include <bits/stdc++.h>
using namespace std;

const int N = 1000001;

map<pair<int, int>, pair<int, int>> parent_state[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> p(n);
        for (auto &i : p) cin >> i;

        fill(parent_state, parent_state + n + 1, map<pair<int, int>, pair<int, int>>());
        parent_state[0][{INT_MIN, INT_MIN}];

        for (int i = 0; i < n; ++i) {
            auto it = parent_state[i].begin();
            while (it != parent_state[i].end()) {
                auto cur = it++;
                auto [x, y] = cur->first;

                bool redundant = false;
                for (auto oth = parent_state[i].begin(); oth != cur; ++oth) {
                    auto [x_oth, y_oth] = oth->first;
                    redundant |= x >= x_oth && y >= y_oth;
                }

                if (redundant) {
                    parent_state[i].erase(cur);
                    continue;
                }

                for (auto p_nxt : {-p[i], p[i]}) {
                    if (p_nxt > x) {
                        parent_state[i + 1][{p_nxt, y}] = {x, y};
                    } else if (p_nxt > y) {
                        parent_state[i + 1][{x, p_nxt}] = {x, y};
                    }
                }
            }
        }

        if (parent_state[n].empty()) {
            cout << "NO\n";
            continue;
        }

        auto [x, y] = parent_state[n].begin()->first;
        for (int i = n - 1; i >= 0; --i) {
            auto [x_parent, y_parent] = parent_state[i + 1][{x, y}];
            p[i] = x != x_parent ? x : y;
            x = x_parent, y = y_parent;
        }

        cout << "YES\n";
        for (auto i : p) {
            cout << i << " ";
        }
        cout << "\n";
    }
}