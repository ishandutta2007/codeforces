#include <bits/stdc++.h>

const int N = 1000010;
using ll = long long;

ll dp[N][2];
int a[N];

void update(ll &u, ll v, ll w){
    v += w;
    if (u == -1 || u > v){
        u = v;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int r1, r2, r3;
    scanf("%d%d%d", &r1, &r2, &r3);
    int d;
    scanf("%d", &d);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    ll ans = 1ll * d * (n - 1);
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < 2; ++ j){
            if (dp[i][j] == -1){
                continue;
            }
            ll first = 1ll * (a[i] + 1) * r1;
            first = std::min(first, ll(r2));
            first += r1;
            int nj = j ^ 1;
            if (j == 0){
                first += 2 * d;
            }
            update(dp[i + 1][nj], dp[i][j], first);
            ll second = 1ll * a[i] * r1 + r3;
            if (i == n - 1 && j == 1){
                second -= d;
            }
            update(dp[i + 1][0], dp[i][j], second);
        }
    }
    ans += std::min(dp[n][0], dp[n][1]);
    printf("%lld\n", ans);
    return 0;
}