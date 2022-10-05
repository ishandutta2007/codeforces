#include <bits/stdc++.h>

const int N = 100010;

int a[N];

void solve(){
    int n, x;
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++ i){
        if (a[i] == x){
            puts("1");
            return;
        }
    }
    int num = *std::max_element(a, a + n);
    int ans = (x + num - 1) / num;
    ans = std::max(2, ans);
    printf("%d\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}