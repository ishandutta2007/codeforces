#include <bits/stdc++.h>

const int N = 100010;

int x[N];

void solve(){
    int n, r;
    scanf("%d%d", &n, &r);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &x[i]);
    }
    std::sort(x, x + n);
    n = std::unique(x, x + n) - x;
    int offset = 0, ans = 0;
    for (int i = n - 1; i >= 0; -- i){
        if (x[i] > offset){
            ++ ans;
            offset += r;
        }
        else{
            break;
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