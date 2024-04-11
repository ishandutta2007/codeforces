#include <bits/stdc++.h>

const int N = 200010;

void update(int &u, int v, int w){
    v += w;
    if (u == -1 || u > v){
        u = v;
    }
}

int dp[N];
char s[N];

void solve(){
    int n;
    scanf("%d%s", &n, s);
    int ans = INT_MAX;
    for (int i = 0; i < 5; ++ i){
        for (int j = 1; j <= n; ++ j){
            dp[j] = -1;
        }
        dp[0] = 0;
        for (int j = 1; j <= n; ++ j){
            if (j >= 2 && dp[j - 2] != -1){
                int w = 0;
                w += s[j - 2] != 'R';
                w += s[j - 1] != 'L';
                update(dp[j], dp[j - 2], w);
            }
            if (j >= 3 && dp[j - 3] != -1){
                int w = 0;
                w += s[j - 3] != 'R';
                w += s[j - 1] != 'L';
                update(dp[j], dp[j - 3], w);
            }
            if (j >= 4 && dp[j - 4] != -1){
                int w = 0;
                w += s[j - 4] != 'R';
                w += s[j - 3] != 'R';
                w += s[j - 2] != 'L';
                w += s[j - 1] != 'L';
                update(dp[j], dp[j - 4], w);
            }
        }
        if (dp[n] != -1){
            update(ans, dp[n], 0);
        }
        std::rotate(s, s + 1, s + n);
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