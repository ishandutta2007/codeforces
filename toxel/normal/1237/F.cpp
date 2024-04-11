#include <bits/stdc++.h>

const int N = 3610;
const int moder = 998244353;

int comb[N][N];
int dp1[N][N], dp2[N], dp3[N];
int fac[N];
bool vis1[N], vis2[N];

void solve(std::vector <int> &vec, int *dp){
    dp[0] = 1;
    for (auto u : vec){
        for (int i = N - 1; i >= 0; -- i){
            for (int j = 1; j <= u / 2; ++ j){
                if (i + j < N){
                    dp[i + j] = (dp[i + j] + 1ll * dp[i] * dp1[u][j]) % moder;
                }
            }
        }
    }
}

int main(){
    fac[0] = 1;
    for (int i = 1; i < N; ++ i){
        fac[i] = 1ll * fac[i - 1] * i % moder;
    }
    for (int i = 0; i < N; ++ i){
        comb[i][0] = 1;
        for (int j = 1; j <= i; ++ j){
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % moder;
        }
    }
    dp1[0][0] = 1;
    for (int i = 1; i < N; ++ i){
        dp1[i][0] = 1;
        for (int j = 1; j < N; ++ j){
            dp1[i][j] = dp1[i - 1][j];
            if (i >= 2){
                dp1[i][j] = (dp1[i][j] + dp1[i - 2][j - 1]) % moder;
            }
        }
    }
    int h, w, n;
    scanf("%d%d%d", &h, &w, &n);
    for (int i = 1; i <= n; ++ i){
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        for (int j = 1; j <= w; ++ j){
            vis1[x1] = vis1[x2] = true;
        }
        for (int j = 1; j <= h; ++ j){
            vis2[y1] = vis2[y2] = true;
        }
    }
    std::vector <int> vec1, vec2;
    int pre = 0;
    for (int i = 1; i <= h; ++ i){
        if (vis1[i]){
            pre = i;
            continue;
        }
        if (i == h || vis1[i + 1]){
            vec1.push_back(i - pre);
        }
    }
    pre = 0;
    for (int i = 1; i <= w; ++ i){
        if (vis2[i]){
            pre = i;
            continue;
        }
        if (i == w || vis2[i + 1]){
            vec2.push_back(i - pre);
        }
    }
    solve(vec1, dp2);
    solve(vec2, dp3);
    int sum1 = 0, sum2 = 0;
    for (auto u : vec1){
        sum1 += u;
    }
    for (auto u : vec2){
        sum2 += u;
    }
    int ans = 0;
    for (int i = 0; i <= h; ++ i){
        for (int j = 0; j <= w; ++ j){
            if (sum1 < i + 2 * j){
                continue;
            }
            if (sum2 < 2 * i + j){
                continue;
            }
            int coe1 = 1ll * dp2[j] * comb[sum1 - 2 * j][i] % moder;
            int coe2 = 1ll * dp3[i] * comb[sum2 - 2 * i][j] % moder;
            ans = (ans + 1ll * coe1 * coe2 % moder * fac[i] % moder * fac[j]) % moder;
        }
    }
    printf("%d\n", ans);
    return 0;
}