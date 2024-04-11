#include <bits/stdc++.h>
using namespace std;

const int maxn = 50000 + 10;
int t[maxn][10], tot[maxn], ans[maxn][10];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int m, n; cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) cin >> t[i][j], tot[i] += t[i][j];
    }
    int p = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            ans[i][j] = max(ans[i][j - 1], ans[i - 1][j]) + t[i][j];
        }
    }
    for (int i = 1; i <= m; ++i) cout << ans[i][n] << ' '; cout << endl;
    return 0;
}