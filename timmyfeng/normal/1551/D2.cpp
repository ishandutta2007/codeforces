#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<string> ans(n, string(m, 0));
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < m; ++j) {
                ans[2 * i][j] = ans[2 * i + 1][j] = 'a' + (i + j) % 2;
            }
        }

        if (n % 2 == 1) {
            if (k < m / 2 || k % 2 != m / 2 % 2) {
                cout << "NO\n";
                continue;
            } else {
                for (int i = 0; i < m / 2; ++i) {
                    ans[n - 1][2 * i] = ans[n - 1][2 * i + 1] = 'c' + i % 2;
                }
                k -= m / 2, --n;
            }
        } else {
            if (k > m / 2 * n || k % 2 == 1) {
                cout << "NO\n";
                continue;
            }
        }

        int i = 0, j = 0;
        while (k--) {
            ans[i][2 * j] = ans[i][2 * j + 1] = 'c' + (i + j) % 2;
            if (++i == n) {
                i = 0, ++j;
            }
        }

        cout << "YES\n";
        for (auto &i : ans) {
            cout << i << "\n";
        }
    }
}