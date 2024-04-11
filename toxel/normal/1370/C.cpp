#include <bits/stdc++.h>

void solve(){
    int n;
    scanf("%d", &n);
    int cnt = 0;
    while (n % 2 == 0){
        n /= 2;
        ++ cnt;
    }
    std::vector<int> fact, dp;
    for (int i = 1; i * i <= n; ++ i){
        if (n % i == 0){
            fact.emplace_back(i);
            if (i * i < n){
                fact.emplace_back(n / i);
            }
        }
    }
    std::sort(fact.begin(), fact.end());
    dp.resize(fact.size());
    dp[0] = cnt == 1;
    int sz = fact.size();
    for (int i = 1; i < sz; ++ i){
        for (int j = 0; j < i; ++ j){
            if (fact[i] % fact[j] == 0 && !dp[j]){
                dp[i] = 1;
            }
        }
    }
    puts(dp[sz - 1] ? "Ashishgup" : "FastestFinger");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}