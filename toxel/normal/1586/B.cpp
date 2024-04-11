#include <bits/stdc++.h>

const int N = 100010;

void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    std::set <int> set;
    for (int i = 0; i < m; ++ i){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        set.emplace(b);
    }
    for (int i = 1; i <= n; ++ i){
        if (!set.count(i)){
            for (int j = 1; j <= n; ++ j){
                if (i == j){
                    continue;
                }
                printf("%d %d\n", i, j);
            }
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