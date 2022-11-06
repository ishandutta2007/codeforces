#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10;
int a[maxn][maxn];
long long dp1[maxn][maxn], dp2[maxn][maxn], dp3[maxn][maxn], dp4[maxn][maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) cin >> a[i][j];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) dp1[i][j] = max(dp1[i][j - 1], dp1[i - 1][j]) + a[i][j];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= 1; --j) dp2[i][j] = max(dp2[i][j + 1], dp2[i - 1][j]) + a[i][j];
    }
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= m; ++j) dp3[i][j] = max(dp3[i][j - 1], dp3[i + 1][j]) + a[i][j];
    }
    for (int i = n; i >= 1; --i) {
        for (int j = m; j >= 1; --j) dp4[i][j] = max(dp4[i][j + 1], dp4[i + 1][j]) + a[i][j];
    }
    long long ans = 0;
    int ai, aj;
    for (int i = 2; i < n; ++i) {
        for (int j = 2; j < m; ++j) {
            long long now = max(dp1[i - 1][j] + dp2[i][j + 1] + dp3[i][j - 1] + dp4[i + 1][j],
                                dp1[i][j - 1] + dp2[i - 1][j] + dp3[i + 1][j] + dp4[i][j + 1]);
            ans = max(ans, now);
        }
    }
    cout << ans << endl;
}