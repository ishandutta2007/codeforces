#include <bits/stdc++.h>

const int N = 200010;

int a[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    std::sort(a, a + n);
    int cur = 0, ans = 0;
    for (int i = 0; i < n; ++ i){
        ++ cur;
        if (a[i] <= cur){
            ++ ans;
            cur = 0;
        }
    }
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