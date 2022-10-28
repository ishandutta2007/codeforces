#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        if (n == 2) {
            cout << -1 << "\n";
            continue;
        }

        vector<vector<int>> ans(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[j][i] = i * n + j + 1;
            }
        }

        for (int i = 0; i < n; ++i) {
            rotate(ans[i].begin(), ans[i].begin() + i, ans[i].end());
        }

        for (auto &i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
}