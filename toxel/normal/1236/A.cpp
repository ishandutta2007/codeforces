#include <bits/stdc++.h>

void solve(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int max = 0;
    for (int i = 0; i <= 100; ++ i){
        for (int j = 0; j <= 100; ++ j){
            if (i <= a && 2 * i + j <= b && 2 * j <= c){
                max = std::max(max, 3 * (i + j));
            }
        }
    }
    printf("%d\n", max);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}