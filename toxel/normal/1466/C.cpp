#include <bits/stdc++.h>

const int N = 200010;

int dp[N][4];
char s[N];

void update(int &u, int v){
    if (u == -1 || u > v){
        u = v;
    }
}

void solve(){
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n + 5; ++ i){
        memset(dp[i], -1, sizeof(dp[i]));
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++ i){
        for (int state = 0; state < 4; ++ state){
            if (dp[i - 1][state] == -1){
                continue;
            }
            for (int j = 0; j < 2; ++ j){
                int cur_pos = i - 1;
                bool flag = true;
                for (int k = 0; k < 2; ++ k){
                    int n_pos = cur_pos - k - 1;
                    if (n_pos < 0){
                        continue;
                    }
                    if (s[cur_pos] == s[n_pos] && (state >> k & 1) == 0 && j == 0){
                        flag = false;
                        break;
                    }
                }
                if (!flag){
                    continue;
                }
                int nstate = state << 1 | j;
                nstate &= 3;
                update(dp[i][nstate], dp[i - 1][state] + j);
            }
        }
    }
    int ans = -1;
    for (int i = 0; i < 4; ++ i){
        if (dp[n][i] == -1){
            continue;
        }
        update(ans, dp[n][i]);
    }
    printf("%d\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}