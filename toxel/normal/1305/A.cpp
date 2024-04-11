#include <bits/stdc++.h>

const int N = 110;

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
    std::sort(a, a + n);
    std::sort(b, b + n);
    for (int i = 0; i < n; ++ i){
        printf("%d%c", a[i], " \n"[i == n - 1]);
    }
    for (int i = 0; i < n; ++ i){
        printf("%d%c", b[i], " \n"[i == n - 1]);
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