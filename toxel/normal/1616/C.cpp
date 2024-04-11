#include <bits/stdc++.h>

const int N = 80;

int a[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    if (n == 1){
        puts("0");
        return;
    }
    int ans = n;
    for (int i = 0; i < n; ++ i){
        for (int j = i + 1; j < n; ++ j){
            int kup = a[j] - a[i], kdown = j - i;
            int bup = a[i] * kdown - kup * i;
            int cnt = 0;
            for (int k = 0; k < n; ++ k){
                if ((kup * k + bup) != (kdown * a[k])){
                    ++ cnt;
                }
            }
            ans = std::min(ans, cnt);
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