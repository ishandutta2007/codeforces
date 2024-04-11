#include <bits/stdc++.h>

void solve(){
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; ++ i){
        int x;
        scanf("%d", &x);
        sum += x;
    }
    puts(sum % n == 0 ? "0" : "1");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}