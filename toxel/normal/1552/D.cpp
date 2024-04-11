#include <bits/stdc++.h>

const int N = 100;

int a[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++ i){
        if (a[i] == 0){
            puts("YES");
            return;
        }
    }
    for (int i = 1; i < 1 << n; ++ i){
        for (int j = 0; j < 1 << n; ++ j){
            if (i & j){
                continue;
            }
            int sum = 0;
            for (int k = 0; k < n; ++ k){
                if (i >> k & 1){
                    sum += a[k];
                }
                if (j >> k & 1){
                    sum -= a[k];
                }
            }
            if (sum == 0){
                puts("YES");
                return;
            }
        }
    }
    puts("NO");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}