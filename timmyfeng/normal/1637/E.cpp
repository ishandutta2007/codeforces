#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;

        map<int, int> count_a;
        for (int i = 0; i < n; ++i) {
            int a; cin >> a;
            ++count_a[a];
        }

        set<pair<int, int>> bans;
        for (int i = 0; i < m; ++i) {
            int x, y; cin >> x >> y;
            bans.insert({x, y}), bans.insert({y, x});
        }

        map<int, int> max_a, link;
        for (auto [a, c] : count_a) {
            link[a] = max_a[c];
            max_a[c] = a;
        }

        long long ans = 0;
        for (auto [count_x, x] : max_a) {
            for (auto [count_y, y] : max_a) {
                if (count_x > count_y) continue;

                set<array<int, 3>> greatest;
                greatest.insert({x + y, x, y});

                while (!greatest.empty()) {
                    auto [sum, u, v] = *greatest.rbegin();
                    greatest.erase(--greatest.end());

                    if (u == 0 || v == 0) continue;

                    if (u != v && !bans.contains({u, v})) {
                        ans = max(ans, (long long) sum * (count_x + count_y));
                        break;
                    }

                    greatest.insert({link[u] + v, link[u], v});
                    greatest.insert({u + link[v], u, link[v]});
                }
            }
        }

        cout << ans << "\n";
    }
}