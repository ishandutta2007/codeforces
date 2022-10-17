#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--) {
        int n, d12, d23, d13;
        cin >> n >> d12 >> d23 >> d13;
        if (d12 + d23 < d13 || d13 + d23 < d12 || d12 + d13 < d23) {
            cout << "NO\n";
            continue;
        }
        int lca_h = (d12 + d13 - d23);
        if (lca_h % 2 != 0) {
            cout << "NO\n";
            continue;
        }
        lca_h /= 2;
        if (lca_h + (d12 - lca_h) + (d13 - lca_h) > n - 1) {
            cout << "NO\n";
            continue;
        }
        //cerr << "LCA " << lca_h << '\n';
        if (d12 < d13) {
            vector<int> path_to_2 = {1};
            int nxt_i = 0;
            for (int i = 0; i + 1 < d12; i++) {
                path_to_2.push_back(i + 4);
                nxt_i = i + 1;
            }
            path_to_2.push_back(2);
            vector<pair<int, int>> edges;
            for (int i = 0; i + 1 < path_to_2.size(); i++) {
                edges.push_back({path_to_2[i], path_to_2[i + 1]});
            }
            while (static_cast<int>(path_to_2.size()) - 1 > lca_h) {
                path_to_2.pop_back();
            }
            for (int i = nxt_i; static_cast<int>(path_to_2.size()) < d13; i++) {
                path_to_2.push_back(i + 4);
                nxt_i = i + 1;
                edges.push_back({path_to_2[path_to_2.size() - 2], path_to_2.back()});
            }
            edges.emplace_back(path_to_2.back(), 3);
            path_to_2.push_back(3);
            for (int i = nxt_i; i + 4 <= n; i++) {
                edges.emplace_back(path_to_2.back(), i + 4);
                path_to_2.push_back(i + 4);
            }
            cout << "YES\n";
            for (auto [u, v] : edges) {
                cout << u << ' ' << v << '\n';
            }
        } else {
            vector<int> path_to_2 = {1};
            int nxt_i = 0;
            for (int i = 0; i + 1 < d13; i++) {
                path_to_2.push_back(i + 4);
                nxt_i = i + 1;
            }
            path_to_2.push_back(3);
            vector<pair<int, int>> edges;
            for (int i = 0; i + 1 < path_to_2.size(); i++) {
                edges.push_back({path_to_2[i], path_to_2[i + 1]});
            }
            while (static_cast<int>(path_to_2.size()) - 1 > lca_h) {
                path_to_2.pop_back();
            }
            for (int i = nxt_i; static_cast<int>(path_to_2.size()) < d12; i++) {
                path_to_2.push_back(i + 4);
                nxt_i = i + 1;
                edges.push_back({path_to_2[path_to_2.size() - 2], path_to_2.back()});
            }
            edges.emplace_back(path_to_2.back(), 2);
            path_to_2.push_back(2);
            for (int i = nxt_i; i + 4 <= n; i++) {
                edges.emplace_back(path_to_2.back(), i + 4);
                path_to_2.push_back(i + 4);
            }
            cout << "YES\n";
            for (auto [u, v] : edges) {
                cout << u << ' ' << v << '\n';
            }
        }
    }
    return 0;
}