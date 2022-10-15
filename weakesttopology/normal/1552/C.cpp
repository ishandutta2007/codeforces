#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<array<int, 2>> edges(k);
        vector<bool> b(2 * n);
        for (auto& [x, y] : edges) {
            cin >> x >> y;
            --x, --y;
            if (x > y) swap(x, y);
            b[x] = b[y] = true;
        }
        vector<int> I;
        for (int i = 0; i < 2 * n; ++i) {
            if (not b[i]) I.push_back(i);
        }
        for (int i = 0; i < n - k; ++i) {
            edges.push_back({I[i], I[i + n - k]});
        }
        sort(begin(edges), end(edges));
        int ans = 0;
        for (auto [x, y] : edges) {
            for (auto [u, v] : edges) {
                if (u == x) break;
                ans += u < x && x < v && v < y;
            }
        }
        cout << ans << '\n';
    }
    exit(0);
}