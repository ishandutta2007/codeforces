#include <bits/stdc++.h>

void solve(){
    int n, k;
    scanf("%d%d", &n, &k);
    int prod = 1;
    if (k % 2 == 0 && n % 2 == 1){
        puts("NO");
        return;
    }
    if (k % 2 == 1 && n % 2 == 0){
        if (n < 2 * k){
            puts("NO");
            return;
        }
        puts("YES");
        for (int i = 0; i < k - 1; ++ i){
            printf("2 ");
        }
        printf("%d\n", n - 2 * (k - 1));
        return;
    }
    if (n < k){
        puts("NO");
        return;
    }
    puts("YES");
    for (int i = 0; i < k - 1; ++ i){
        printf("1 ");
    }
    printf("%d\n", n - k + 1);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
}