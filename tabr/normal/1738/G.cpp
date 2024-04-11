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
        int n, k;
        cin >> n >> k;
        k = n - k + 1;
        vector<string> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        vector<string> t(n, string(n, '1'));
        vector<vector<int>> b(k + 1, vector<int>(k + 1));
        for (int i = 0; i < k; i++) {
            b[i][0]++;
            b[0][i]++;
        }
        vector<vector<pair<int, int>>> c(2 * n);
        c[n].emplace_back(0, 0);
        for (int sum = 0; sum < 2 * n - 1; sum++) {
            for (int i = 0; i <= min(sum, n - 1); i++) {
                int j = sum - i;
                if (j >= n) {
                    continue;
                }
                if (s[i][j] == '0') {
                    continue;
                }
                if (c[i - j + n].empty()) {
                    continue;
                }
                t[i][j] = '0';
                auto [x, y] = c[i - j + n].back();
                c[i - j + n].pop_back();
                b[x + 1][y]++;
                if (b[x + 1][y] == 2) {
                    c[x + 1 - y + n].emplace_back(x + 1, y);
                }
                b[x][y + 1]++;
                if (b[x][y + 1] == 2) {
                    c[x - y - 1 + n].emplace_back(x, y + 1);
                }
            }
        }
        if (b[k][k - 1]) {
            cout << "YES" << '\n';
            for (int i = 0; i < n; i++) {
                cout << t[i] << '\n';
            }
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}