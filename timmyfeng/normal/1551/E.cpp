#include <bits/stdc++.h>
using namespace std;

void set_max(int &a, int b) {
    if (b > a) {
        a = b;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (auto &i : a) {
            cin >> i;
        }

        vector<vector<int>> max_equal(n + 1, vector<int>(n + 1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                set_max(max_equal[i + 1][j], max_equal[i][j]);
                set_max(max_equal[i + 1][j + 1], max_equal[i][j] + (a[i] == j + 1));
            }
        }

        int ans = -1;
        for (int i = 0; i <= n; ++i) {
            if (max_equal[n][i] >= k) {
                ans = n - i;
            }
        }

        cout << ans << "\n";
    }
}