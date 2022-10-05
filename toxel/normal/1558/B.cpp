#include <bits/stdc++.h>

const int N = 4000010;
int moder;

void add(int &u, int v){
    u += v;
    u -= u >= moder ? moder : 0;
}

void sub(int &u, int v){
    u -= v;
    u += u < 0 ? moder : 0;
}

int dp[N];

int main(){
    int n;
    scanf("%d%d", &n, &moder);
    dp[1] = 1;
    int cur = 0;
    for (int i = 1; i <= n; ++ i){
        if (i > 1){
            add(cur, dp[i]);
            dp[i] = cur;
        }
        add(dp[i + 1], dp[i]);
        for (int j = 2; i * j <= n; ++ j){
            add(dp[i * j], dp[i]);
            int num = (i + 1) * j;
            if (num < N){
                sub(dp[num], dp[i]);
            }
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}