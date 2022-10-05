#include <bits/stdc++.h>

const int N = 100010;

int a[N];

void solve(){
    int n;
    scanf("%d", &n);
    int max = INT_MIN, max_diff = 0;
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        if (max != INT_MIN){
            max_diff = std::max(max_diff, max - a[i]);
        }
        max = std::max(max, a[i]);
    }
    for (int i = 0; ; ++ i){
        if ((1ll << i) - 1 >= max_diff){
            printf("%d\n", i);
            return;
        }
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