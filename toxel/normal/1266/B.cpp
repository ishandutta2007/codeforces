#include <bits/stdc++.h>

int main(){
    /*for (auto u : cnt){
        dp[21 - u] = true;
    }
    for (int i = 1; i < N; ++ i){
        for (int j = 0; j < 6; j += 2){
            int num = 21 - cnt[j] - cnt[j + 1];
            if (i >= num && dp[i - num]){
                dp[i] = true;
            }
        }
    }*/
    int test;
    scanf("%d", &test);
    while (test --){
        long long x;
        scanf("%lld", &x);
        if (x >= 15 && (x % 14 >= 1 && x % 14 <= 6)){
            puts("YES");
        }
        else{
            puts("NO");
        }
    }
    return 0;
}