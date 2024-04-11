#include <bits/stdc++.h>
using namespace std;

const int kN = 1 << 19;
long long dp[20][kN], pf[20][kN];
int a[kN], cr[20];

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i) {
        if (a[i] == -1) {
            for (int j = 1; j <= i; ++j) a[j] = 0;
            break;
        }
    }
    int k = 0, m = n;
    while (m > 0) k += 1, m >>= 1;
    cr[k] = n / 2;
    for (int i = k - 1; i >= 1; --i) {
        int p = i - 2 >= 0 ? (1 << (i - 2)) : 1;
        cr[i] = cr[i + 1] + p;
    }
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j <= n; ++j)
            dp[i][j] = 1e18;
    }
    dp[0][0] = 0;
    for (int i = 1; i <= k; ++i) {
        deque<int> dq = {0};
        for (int j = 1; j <= n; ++j) {
            int p = n - cr[i];
            while (!dq.empty() && dq[0] < p) dq.pop_front();
            if (!dq.empty()) dp[i][j] = min(dp[i][j], dp[i - 1][dq.front()] + a[j]);
            while (!dq.empty() && dp[i - 1][j] < dp[i - 1][dq.back()]) dq.pop_back();
            dq.push_back(j);
        }
    }
    printf("%lld\n", dp[k][n]);
}