#include <bits/stdc++.h>

const int N = 40;

int a[N][N];

void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            scanf("%d", &a[i][j]);
        }
    }
    int ans = 0;
    std::map <int, int> map, tot;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            int len = i + j;
            if (len == n + m - 2 - len){
                continue;
            }
            len = std::min(n + m - 2 - len, len);
            ++ tot[len];
            if (a[i][j]){
                ++ map[len];
            }
        }
    }
    for (auto u : map){
        ans += std::min(u.second, tot[u.first] - u.second);
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