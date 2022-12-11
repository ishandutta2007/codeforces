#include <bits/stdc++.h>

const int N = 100010;

int cnt[N], ans[N];
std::vector <int> vec[N];

void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; ++ i){
        cnt[i] = 0;
    }
    for (int i = 0; i <= m; ++ i){
        vec[i].clear();
    }
    for (int i = 0; i < m; ++ i){
        int num;
        scanf("%d", &num);
        vec[i].resize(num);
        for (int j = 0; j < num; ++ j){
            scanf("%d", &vec[i][j]);
        }
    }
    for (int i = 0; i < m; ++ i){
        if (int(vec[i].size()) == 1){
            ++ cnt[vec[i][0]];
        }
    }
    for (int i = 1; i <= n; ++ i){
        if (cnt[i] > (m + 1) / 2){
            puts("NO");
            return;
        }
    }
    for (int i = 0; i <= n; ++ i){
        cnt[i] = 0;
    }
    for (int i = 0; i < m; ++ i){
        if (int(vec[i].size()) != 1){
            continue;
        }
        for (auto u : vec[i]){
            if (cnt[u] < (m + 1) / 2){
                ++ cnt[u];
                ans[i] = u;
                break;
            }
        }
    }
    for (int i = 0; i < m; ++ i){
        if (int(vec[i].size()) == 1){
            continue;
        }
        for (auto u : vec[i]){
            if (cnt[u] < (m + 1) / 2){
                ++ cnt[u];
                ans[i] = u;
                break;
            }
        }
    }
    puts("YES");
    for (int i = 0; i < m; ++ i){
        printf("%d%c", ans[i], " \n"[i == m - 1]);
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