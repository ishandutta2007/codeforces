#include <bits/stdc++.h>

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        printf("1%c", " \n"[i == n - 1]);
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