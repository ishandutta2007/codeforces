#include <bits/stdc++.h>

const int N = 1010;

int a[N];

void solve(){
    int n, x;
    scanf("%d%d", &n, &x);
    int cnt[2] = {};
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        ++ cnt[a[i] % 2];
    }
    if (cnt[1] == 0){
        puts("No");
        return;
    }
    if (cnt[0] == 0 && x % 2 == 0){
        puts("No");
        return;
    }
    if (cnt[1] % 2 == 0 && x == n){
        puts("No");
        return;
    }
    puts("Yes");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}