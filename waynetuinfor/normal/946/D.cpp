#include <bits/stdc++.h>
using namespace std;

const int maxn = 500 + 10;
int dp1[maxn][maxn], dp2[maxn][maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < maxn; ++i) for (int j = 0; j < maxn; ++j) dp1[i][j] = maxn * maxn;
    for (int i = 1; i <= n; ++i) {
        string s; cin >> s;
        vector<int> pos;
        for (int j = 0; j < m; ++j) if (s[j] == '1') pos.push_back(j);
        for (int j = 0; j <= min(k, (int)pos.size()); ++j) {
            deque<int> dq;
            for (int p = 0; p < pos.size() - j; ++p) dq.push_back(pos[p]);
            if (dq.size() < 2) {
                dp1[i][j] = dq.size();
                continue;
            }
            dp1[i][j] = dq.back() - dq.front() + 1;
            for (int p = pos.size() - j; p < pos.size(); ++p) {
                dq.push_back(pos[p]);
                dq.pop_front();
                dp1[i][j] = min(dp1[i][j], dq.back() - dq.front() + 1);
            }
        }
    }
    for (int i = 0; i < maxn; ++i) for (int j = 0; j < maxn; ++j) dp2[i][j] = maxn * maxn;
    dp2[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int p = 0; p <= j; ++p) dp2[i][j] = min(dp2[i][j], dp2[i - 1][j - p] + dp1[i][p]);
        }
    }
    int ans = maxn * maxn;
    for (int j = 0; j <= k; ++j) ans = min(ans, dp2[n][j]);
    cout << ans << endl;
    return 0;
}