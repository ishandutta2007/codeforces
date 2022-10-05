#include <bits/stdc++.h>

const int N = 1010;

int a[N];
int ans[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    ans[0] = 1;
    int len = 1;
    for (int i = 0; i < n; ++ i){
        if (i > 0){
            if (a[i] == 1){
                ans[len ++] = 1;
            }
            else{
                while (len > 0 && ans[len - 1] != a[i] - 1){
                    -- len;
                }
                ++ ans[len - 1];
            }
        }
        for (int j = 0; j < len; ++ j){
            printf("%d%c", ans[j], ".\n"[j == len - 1]);
        }
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}