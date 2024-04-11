#include <bits/stdc++.h>

using namespace std;

const int MX = 2005;
const int INF = 1e9;
int n, k;
int a[MX];
int dp[MX][MX];

void clr() {
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = -INF;
    dp[0][0] = 0;
}

void solve() {
    scanf("%d %d", &n, &k); clr();
    for (int i = 0; i < n; i++) scanf("%d", &a[i]), --a[i];
    for (int pos = 0; pos < n; pos++) {
        for (int cnt = 0; cnt < n; cnt++) {
            dp[pos + 1][cnt + 1] = max(dp[pos][cnt], dp[pos + 1][cnt + 1]);
            int fk = (a[pos] == pos - cnt ? 1 : 0);
            dp[pos + 1][cnt] = max(dp[pos + 1][cnt], dp[pos][cnt] + fk);
        }
    }
    int mn = n;
    for (int cnt = 0; cnt < n; cnt++) if (dp[n][cnt] >= k) mn = min(mn, cnt);
    printf("%d\n", (mn == n ? -1 : mn));
}

int main() {
    int T; scanf("%d", &T);
    while (T--) solve();
}