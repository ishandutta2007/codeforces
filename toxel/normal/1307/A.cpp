#include <bits/stdc++.h>

const int N = 110;

int a[N];

void solve(){
    int n, d;
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; ++ i){
        int num = std::min(a[i], d / i);
        a[0] += num;
        d -= i * num;
    }
    printf("%d\n", a[0]);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}