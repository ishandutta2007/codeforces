#include <bits/stdc++.h>

const int N = 200010;

int p[N], c[N];
bool vis[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &c[i]);
    }
    for (int i = 1; i <= n; ++ i){
        vis[i] = false;
    }
    int ans = INT_MAX;
    for (int i = 1; i <= n; ++ i){
        if (vis[i]){
            continue;
        }
        int x = i;
        std::vector <int> color;
        while (!vis[x]){
            color.emplace_back(c[x]);
            vis[x] = true;
            x = p[x];
        }
        std::vector <int> to_check;
        int len = color.size();
        for (int j = 1; j * j <= len; ++ j){
            if (len % j == 0){
                to_check.emplace_back(j);
                to_check.emplace_back(len / j);
            }
        }
        for (auto u : to_check){
            for (int j = 0; j < u; ++ j){
                bool flag = true;
                for (int k = 0; k < len / u; ++ k){
                    if (color[k * u + j] != color[j]){
                        flag = false;
                        break;
                    }
                }
                if (flag){
                    ans = std::min(ans, u);
                }
            }
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