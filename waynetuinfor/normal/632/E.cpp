#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
int dp[maxn * maxn], a[maxn];

int main() {
    int n, k; scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    sort(a + 1, a + n + 1);
    int p = a[1];
    for (int i = 1; i <= n; ++i) a[i] -= p;
    fill(dp, dp + maxn * maxn, maxn);
    dp[0] = 0;
    for (int i = 0; i <= a[n] * k; ++i) {
        if (dp[i] == maxn) continue;
        for (int j = 1; j <= n; ++j) dp[i + a[j]] = min(dp[i + a[j]], dp[i] + 1); 
    } 
    for (int i = 0; i <= a[n] * k; ++i) {
        if (dp[i] <= k) printf("%d ", i + k * p);
    }
    puts("");
}