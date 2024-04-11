#include <bits/stdc++.h>

using ll = long long;
const int N = 1010;

ll a[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%lld", &a[i]);
    }
    printf("%d\n", 3 * n);
    for (int i = 1; i <= n; i += 2){
        printf("1 %d %d\n", i, i + 1);
        printf("2 %d %d\n", i, i + 1);
        printf("1 %d %d\n", i, i + 1);
        printf("1 %d %d\n", i, i + 1);
        printf("2 %d %d\n", i, i + 1);
        printf("1 %d %d\n", i, i + 1);
        a[i] += a[i + 1];
        a[i + 1] -= a[i];
        a[i] += a[i + 1];
        a[i] += a[i + 1];
        a[i + 1] -= a[i];
        a[i] += a[i + 1];
    }
    /*for (int i = 1; i <= n; ++ i){
        printf("%lld\n", a[i]);
    }*/
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}