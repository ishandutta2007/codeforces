#include <bits/stdc++.h>

using ll = long long;
const int N = 200010;

int a[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    ll max = 0, min = 0, pre = 0;
    for (int i = 0; i + 1 < n; i += 2){
        pre += -a[i] + a[i + 1];
        max = std::max(max, pre - min);
        min = std::min(min, pre);
    }
    min = 0, pre = 0;
    for (int i = 1; i + 1 < n; i += 2){
        pre += a[i] - a[i + 1];
        max = std::max(max, pre - min);
        min = std::min(min, pre);
    }
    for (int i = 0; i < n; i += 2){
        max += a[i];
    }
    printf("%lld\n", max);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}