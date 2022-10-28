#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, l, r, s;
        cin >> n >> l >> r >> s;

        int d = r - l + 1;
        if (s < d * (d + 1) / 2 || s > d * (2 * n - d + 1) / 2) {
            cout << -1 << "\n";
            continue;
        }

        vector<bool> used(n + 1);
        vector<int> ans(n);

        for (int i = d - 1, j = n; i >= 0; --i) {
            while (s - j < i * (i + 1) / 2) {
                --j;
            }
            used[j] = true;
            ans[l + i - 1] = j;
            s -= j, --j;
        }

        for (int i = 0, j = 1; i < n; ++i) {
            if (ans[i] == 0) {
                while (used[j]) {
                    ++j;
                }
                ans[i] = j;
                used[j] = true;
            }
        }

        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";
    }
}