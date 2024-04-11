#include <bits/stdc++.h>
using namespace std;
#define REP(i, m, n) for (int i = (int)(m); i < (int)(n); ++i)
#define rep(i, n) REP(i, 0, n)

void solve() {
    int n, m;
    cin >> n >> m;
    string s[n];
    rep(i, n) cin >> s[i];
    vector<vector<int>> a(n, vector<int>(m, 0));
    rep(i, n) rep(j, m) a[i][j] = s[i][j] == '1';
    vector<pair<int, int>> ans1;
    vector<pair<int, int>> ans2;
    rep(i, n) rep(j, m) {
        if (i + j == n + m - 2) continue;
        int x = min(i, n - 2), y = min(j, m - 2);
        ans1.emplace_back(x, y);
        rep(k, 2) rep(l, 2) {
            a[x + k][y + l] ^= 1;
        }
    }
    int cnt = n * m - 1;
    rep(i, n) rep(j, m) cnt += a[i][j];
    if (cnt % 2) {
        ans1.emplace_back(n - 2, m - 2);
        rep(k, 2) rep(l, 2) {
            a[n - 1 - k][m - 1 - l] ^= 1;
        }
    }
    rep(i, n) rep(j, m) {
        if (ans1.size() != n * m && i == n - 1 && j == m - 1)
            continue;
        if (a[i][j]) {
            ans2.emplace_back(i, j);
            a[i][j] = 0;
        } else if (j + 1 < m) {
            ans2.emplace_back(i, j + 1);
            a[i][j + 1] ^= 1;
        } else if (i + 1 < n) {
            ans2.emplace_back(i + 1, j);
            a[i + 1][j] ^= 1;
        } else {
            assert(false);
        }
    }
    cout << ans1.size() << endl;
    rep(t, ans1.size()) {
        rep(j, 2) rep(k, 2) {
            if (ans1[t].first + j != ans2[t].first || ans1[t].second + k != ans2[t].second) {
                cout << ans1[t].first + j + 1 << " " << ans1[t].second + k + 1 << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}