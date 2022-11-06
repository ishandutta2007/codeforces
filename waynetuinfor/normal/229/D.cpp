#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 10;
const long long inf = 1e16;
long long h[maxn], s[maxn];
long long dp[maxn][maxn], dv[maxn];
int fr[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> h[i], s[i] = s[i - 1] + h[i];
    fill(&dp[0][0], &dp[maxn - 1][maxn - 1] + 1, inf);
    fill(dv, dv + maxn, inf);
    dv[0] = 0;
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        fr[i] = i;
        int p = i;
        while (s[i] < dv[p - 1]) dp[i][p] = dp[i - 1][p] + h[i], dv[p] = min(dv[p], dp[i][p] + s[i]), --p;
        while (fr[i] >= 1 && s[i] - s[fr[i] - 1] < dp[fr[i] - 1][p - 1]) --fr[i];
        for (int j = p; j >= 1; --j) {
            dp[i][j] = dp[i - 1][j] + h[i];
            while (fr[i] >= 1 && (s[i] - s[fr[i] - 1] < dp[fr[i] - 1][j - 1])) --fr[i];
            if (s[i] - s[fr[i] - 1] >= dp[fr[i] - 1][j - 1]) dp[i][j] = min(dp[i][j], s[i] - s[fr[i] - 1]);
            dv[j] = min(dv[j], dp[i][j] + s[i]);
        }
    }
    for (int i = n; i >= 1; --i) {
        if (dp[n][i] < inf) return cout << n - i << endl, 0;
    }
    return 0;
}