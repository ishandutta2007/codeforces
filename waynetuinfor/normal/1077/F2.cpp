#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 5;
const long long inf = 1e15;
int a[maxn];
long long dp[2][maxn];

int main() {
    int n, k, x; scanf("%d%d%d", &n, &k, &x);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < maxn; ++i) {
        dp[0][i] = -inf;
        dp[1][i] = -inf;
    }
    dp[0][0] = 0;
    for (int i = 1; i <= x; ++i) {
        deque<int> dq;
        dq.push_back(0);
        for (int j = 1; j <= n; ++j) {
            while (dq.size() && j - dq.front() > k) dq.pop_front();
            dp[i & 1][j] = dp[i & 1 ^ 1][dq.front()] + a[j];
            while (dq.size() && dp[i & 1 ^ 1][j] >= dp[i & 1 ^ 1][dq.back()]) dq.pop_back();
            dq.push_back(j);
        }
    }
    long long ans = -inf;
    for (int i = 1; i <= n; ++i) {
        if (n - i + 1 <= k) ans = max(ans, dp[x & 1][i]);
    }
    if (ans < 0) ans = -1;
    printf("%lld\n", ans);
    return 0;
}