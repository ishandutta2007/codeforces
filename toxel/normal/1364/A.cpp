#include <bits/stdc++.h>

const int N = 100010;

int a[N];

void solve(){
    int n, x;
    scanf("%d%d", &n, &x);
    int sum = 0;
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        sum = (sum + a[i]) % x;
    }
    if (sum != 0){
        printf("%d\n", n);
        return;
    }
    int first = -1, last = -1;
    for (int i = 0; i < n; ++ i){
        if (a[i] % x != 0){
            first = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; -- i){
        if (a[i] % x != 0){
            last = i;
            break;
        }
    }
    if (first == -1){
        puts("-1");
        return;
    }
    int ans = n - std::min(first + 1, n - last);
    printf("%d\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
}