#include <bits/stdc++.h>

const int N = 200010;
const int BIT = 20;

int cnt[N][BIT];

void solve(){
    int l, r;
    scanf("%d%d", &l, &r);
    int max = 0;
    for (int i = 0; i < BIT; ++ i){
        max = std::max(max, cnt[r][i] - cnt[l - 1][i]);
    }
    printf("%d\n", r - l + 1 - max);
}

int main(){
    for (int i = 1; i < N; ++ i){
        for (int j = 0; j < BIT; ++ j){
            cnt[i][j] = cnt[i - 1][j] + (i >> j & 1);
        }
    }
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}