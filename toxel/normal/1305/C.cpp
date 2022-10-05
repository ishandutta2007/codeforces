#include <bits/stdc++.h>

const int N = 200010;

int a[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    if (n > 2000){
        puts("0");
        return 0;
    }
    int ans = 1;
    for (int i = 0; i < n; ++ i){
        for (int j = i + 1; j < n; ++ j){
            ans = 1ll * ans * std::abs(a[i] - a[j]) % m;
        }
    }
    printf("%d\n", ans);
    return 0;
}