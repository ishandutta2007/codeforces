#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = 998244353;

int n;
int k;
int a[1005];
ll pref[1005];
ll dp[1005];

ll solve(int x) {
    for (int i = 0; i <= n; i++) {
        pref[i] = 1;
    }
    for (int j = 1; j <= k; j++) {
        int ptr = 0;
        for (int i = 1; i <= n; i++) {
            while (a[ptr + 1] <= a[i] - x) {
                ptr += 1;
            }
            dp[i] = pref[ptr];
            dp[i] %= MOD;
        }
        pref[0] = 0;
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + dp[i];
        }
    }
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        res += dp[i];
        res %= MOD;
    }
    return res;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    sort(a + 1, a + n + 1);
    ll ans = 0;
    for (int x = 1; x <= 1e5; x++) {
        if (x * (k - 1) > 2e5) {
            break;
        }
        ans += solve(x);
        ans %= MOD;
    }
    printf("%lld", ans);
    return 0;
}