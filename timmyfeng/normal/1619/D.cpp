#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> joy(m, vector<int>(n));
        for (auto &i : joy) {
            for (auto &j : i) {
                cin >> j;
            }
        }

        int alpha = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int best = 0;
            for (int j = 0; j < m; ++j) {
                best = max(best, joy[j][i]);
            }
            alpha = min(alpha, best);
        }

        int nxt_best = 0;
        for (int i = 0; i < m; ++i) {
            sort(joy[i].rbegin(), joy[i].rend());
            nxt_best = max(nxt_best, joy[i][1]);
        }

        cout << min(alpha, nxt_best) << "\n";
    }
}