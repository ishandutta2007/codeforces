#include <bits/stdc++.h>

const int N = 510;

int a[N], b[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++ i){
        scanf("%d", &b[i]);
    }
    for (int i = 1; i < n; ++ i){
        if (b[i] != b[0]){
            puts("Yes");
            return;
        }
    }
    int pre = -1;
    for (int i = 0; i < n; ++ i){
        if (pre > a[i]){
            puts("No");
            return;
        }
        pre = a[i];
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