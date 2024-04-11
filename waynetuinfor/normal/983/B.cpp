#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 5, maxq = 1e5 + 5;
int a[maxn], f[maxn][maxn], dp[maxn];
vector<int> qr[maxn];
int ans[maxq], l[maxq], r[maxq];

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    memset(f, -1, sizeof(f));
    for (int i = n; i > 0; --i) {
        f[i][i] = a[i];
        for (int j = i + 1; j <= n; ++j) f[i][j] = f[i][j - 1] ^ f[i + 1][j];
    }
    int q; scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        scanf("%d %d", &l[i], &r[i]);
        qr[l[i]].push_back(i);
    }
    for (int i = n; i > 0; --i) {
        for (int j = i; j <= n; ++j) dp[j] = max(dp[j], f[i][j]);
        for (int j = i; j <= n; ++j) dp[j] = max(dp[j], dp[j - 1]);
        for (int j = 0; j < qr[i].size(); ++j) ans[qr[i][j]] = dp[r[qr[i][j]]];
    }
    for (int i = 0; i < q; ++i) printf("%d\n", ans[i]);
    return 0;
}