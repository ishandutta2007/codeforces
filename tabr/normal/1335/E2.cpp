#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
        int n;
        cin >> n;
        vector<int> a(n);
        vector<vector<int>> s(200, vector<int>(n + 1));
        vector<vector<int>> pos(200);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
            pos[a[i]].emplace_back(i);
        }
        for (int i = 0; i < n; i++) {
            s[a[i]][i + 1]++;
            for (int j = 0; j < 200; j++) {
                s[j][i + 1] += s[j][i];
            }
        }
        int ans = 0;
        for (int i = 0; i < 200; i++) {
            int m = pos[i].size();
            ans = max(ans, m);
            for (int j = 0; j < m - 1 - j; j++) {
                int x = pos[i][j], y = pos[i][m - 1 - j];
                int sum = 0;
                for (int k = 0; k < 200; k++) {
                    sum = max(sum, s[k][y] - s[k][x + 1]);
                }
                sum += 2 * (j + 1);
                ans = max(ans, sum);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}