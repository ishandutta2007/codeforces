#include <bits/stdc++.h>

using ll = long long;

void solve(){
    int n;
    scanf("%d", &n);
    ll sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; ++ i){
        int x;
        scanf("%d", &x);
        sum1 += x, sum2 ^= x;
    }
    printf("2\n%lld", sum2);
    sum1 += sum2, sum2 ^= sum2;
    printf(" %lld\n", sum1);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}