#include <bits/stdc++.h>

const int N = 1010;
const int moder = 998244353;

int p[N][N];
bool ban[N];
bool choose[N], not_choose[N];
int cnt[N], vis[N];
int col[N];
std::vector <int> e[N];

void dfs(int u){
    for (auto v : e[u]){
        if (col[v] == -1){
            col[v] = col[u] ^ 1;
            dfs(v);
        }
        else{
        }
    }
}

void solve(){
    memset(ban, 0, sizeof(ban));
    memset(choose, 0, sizeof(choose));
    memset(not_choose, 0, sizeof(not_choose));
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n; ++ i){
        for (int j = 1; j <= n; ++ j){
            scanf("%d", &p[i][j]);
        }
    }
    while (true){
        bool modified = false;
        for (int i = 1; i <= n; ++ i){
            if (ban[i]){
                continue;
            }
            memset(cnt, 0, sizeof(cnt[0]) * (n + 1));
            for (int j = 1; j <= 2 * n; ++ j){
                if (choose[j] || not_choose[j]){
                    continue;
                }
                ++ cnt[p[j][i]];
                vis[p[j][i]] = j;
            }
            for (int j = 1; j <= n; ++ j){
                if (cnt[j] == 1){
                    int id = vis[j];
                    choose[id] = true;
                    modified = true;
                    for (int k = 1; k <= 2 * n; ++ k){
                        if (choose[k] || not_choose[k]){
                            continue;
                        }
                        bool flag = false;
                        for (int u = 1; u <= n; ++ u){
                            if (p[k][u] == p[id][u]){
                                flag = true;
                                break;
                            }
                        }
                        if (flag){
                            not_choose[k] = true;
                        }
                    }
                }
            }
        }
        if (!modified){
            break;
        }
    }
    for (int i = 1; i <= 2 * n; ++ i){
        e[i].clear();
    }
    for (int i = 1; i <= 2 * n; ++ i){
        if (choose[i] || not_choose[i]){
            continue;
        }
        for (int j = i + 1; j <= 2 * n; ++ j){
            if (choose[j] || not_choose[j]){
                continue;
            }
            bool flag = false;
            for (int k = 1; k <= n; ++ k){
                if (p[i][k] == p[j][k]){
                    flag = true;
                    break;
                }
            }
            if (flag){
                e[i].emplace_back(j);
                e[j].emplace_back(i);
            }
        }
    }
    memset(col, -1, sizeof(col));
    int ans = 1;
    for (int i = 1; i <= 2 * n; ++ i){
        if (choose[i] || not_choose[i]){
            continue;
        }
        if (col[i] != -1){
            continue;
        }
        col[i] = 0;
        dfs(i);
        ans = 2 * ans % moder;
    }
    printf("%d\n", ans);
    std::vector <int> output;
    for (int i = 1; i <= 2 * n; ++ i){
        if (col[i] == 0 || choose[i]){
            output.emplace_back(i);
        }
    }
    for (int i = 0; i < n; ++ i){
        printf("%d%c", output[i], " \n"[i == n - 1]);
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