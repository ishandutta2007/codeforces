#include <bits/stdc++.h>

const int N = 100010;
using ll = long long;

int a[N];

void solve(){
    int n, x;
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    std::sort(a, a + n, std::greater <int>());
    ll sum = 0;
    for (int i = 0; i < n; ++ i){
        sum += a[i];
        if (sum / (i + 1) < x){
            printf("%d\n", i);
            return;
        }
    }
    printf("%d\n", n);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}