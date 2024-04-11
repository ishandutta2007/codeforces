#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
const long long inf = 1e15;
int x[maxn], y[maxn], dt[maxn];
int xh[maxn], yh[maxn], xf[maxn], yf[maxn];
long long dp[2][maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d%d", &x[i], &y[i]);
    x[n] = 0, y[n] = 0, ++n;
    vector<int> v(n); iota(v.begin(), v.end(), 0);
    sort(v.begin(), v.end(), [&](int i, int j) {
        if (max(x[i], y[i]) != max(x[j], y[j])) return max(x[i], y[i]) < max(x[j], y[j]);
        if (y[i] != y[j]) return y[i] < y[j];
        return x[i] > x[j];
    });
    int sz = 0;
    for (int i = 0; i < n; ) {
        int j = i, k = max(x[v[i]], y[v[i]]);
        while (j < n && max(x[v[j]], y[v[j]]) == k) ++j;
        dt[sz] = abs(x[v[j - 1]] - x[v[i]]) + abs(y[v[j - 1]] - y[v[i]]);
        xh[sz] = x[v[i]], yh[sz] = y[v[i]];
        xf[sz] = x[v[j - 1]], yf[sz] = y[v[j - 1]];
        // printf("dt[%d] = %d\n", i, dt[i]);
        // printf("xh[%d] = %d, yh[%d] = %d\n", sz, xh[sz], sz, yh[sz]);
        // printf("xf[%d] = %d, yf[%d] = %d\n", sz, xf[sz], sz, yf[sz]);
        ++sz;
        i = j;
    }
    for (int i = 0; i < maxn; ++i) {
        dp[0][i] = inf;
        dp[1][i] = inf;
    }
    dp[0][0] = dp[1][0] = dt[0];
    for (int i = 1; i < sz; ++i) {
        dp[0][i] = min(dp[0][i], dp[0][i - 1] + abs(xh[i - 1] - xf[i]) + abs(yh[i - 1] - yf[i]) + dt[i]);
        dp[0][i] = min(dp[0][i], dp[1][i - 1] + abs(xf[i - 1] - xf[i]) + abs(yf[i - 1] - yf[i]) + dt[i]);
        dp[1][i] = min(dp[1][i], dp[0][i - 1] + abs(xh[i - 1] - xh[i]) + abs(yh[i - 1] - yh[i]) + dt[i]);
        dp[1][i] = min(dp[1][i], dp[1][i - 1] + abs(xf[i - 1] - xh[i]) + abs(yf[i - 1] - yh[i]) + dt[i]);
        // printf("dp[%d][%d] = %lld\n", 0, i, dp[0][i]);
        // printf("dp[%d][%d] = %lld\n", 1, i, dp[1][i]);
    }
    printf("%lld\n", min(dp[0][sz - 1], dp[1][sz - 1]));
    return 0;
}