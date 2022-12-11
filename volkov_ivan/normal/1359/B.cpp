#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    char f[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> f[i][j];
        }
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j != m - 1 && f[i][j] == '.' && f[i][j + 1] == '.') {
                cnt1 += 2;
                cnt2++;
                j++;
                continue;
            }
            if (f[i][j] == '.') cnt1++;
        }
    }
    cout << min(cnt1 * x, cnt2 * y + x * (cnt1 - 2 * cnt2)) << endl;
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("Desktop/input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}