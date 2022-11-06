#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 10;
short dp[maxn][maxn], dp2[maxn][maxn], p[maxn];
int ans;
vector<pair<short, short>> vans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> p[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= n; ++j) dp[i][j] = dp[i][j - 1] + (int)(p[j] > i);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = n; j >= 1; --j) dp2[i][j] = dp2[i][j + 1] + (int)(p[j] < i);
    }
    int cur = 0;
    ans = n * n;
    for (int i = 1; i <= n; ++i) cur += dp[p[i]][i - 1];
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
             int delta = (dp2[p[j]][i + 1] - dp2[p[j]][j]) - (dp[p[j]][j - 1] - dp[p[j]][i]) + (dp[p[i]][j - 1] - dp[p[i]][i]) - (dp2[p[i]][i + 1] - dp2[p[i]][j]);
             int sw = cur + delta;
             if (p[i] > p[j]) --sw;
             else ++sw;
             if (sw < ans) {
                 vans.clear(); vans.push_back(make_pair(i, j));
                 ans = sw;
             } else if (sw == ans) vans.push_back(make_pair(i, j));
        }
    }
    cout << ans << ' ' << vans.size() << endl;
    return 0;
}