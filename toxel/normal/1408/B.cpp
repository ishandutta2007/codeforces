#include <bits/stdc++.h>

const int N = 110;

int a[N];

int divup(int a, int b){
    return (a + b - 1) / b;
}

void solve(){
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    if (k == 1){
        for (int i = 1; i < n; ++ i){
            if (a[i] != a[0]){
                puts("-1");
                return;
            }
        }
        puts("1");
        return;
    }
    int tot = 0;
    for (int i = 0; i < n - 1; ++ i){
        tot += a[i] != a[i + 1];
    }
    tot = std::max(tot, 1);
    printf("%d\n", divup(tot, k - 1));
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}