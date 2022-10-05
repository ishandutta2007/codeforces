#include <bits/stdc++.h>

const int N = 2000010;
const int moder = int(1e9) + 7;

bool dp[N];
int cnt[N];

int main(){
    for (int i = 3; i < N; ++ i){
        int x = 1 - 2 * int(dp[i - 2]) - int(dp[i - 1]);
        int y = 0;
        if (x < y){
            x = y;
        }
        dp[i] = x != y;
        cnt[i] = (2ll * cnt[i - 2] + cnt[i - 1] + 4 * x) % moder;
    }
    int test;
    scanf("%d", &test);
    while (test --){
        int n;
        scanf("%d", &n);
        printf("%d\n", cnt[n]);
    }
    return 0;
}